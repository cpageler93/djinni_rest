package main.java.com.thepeaklab.djinnirest;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import com.mycompany.djinni_rest.Http;
import com.mycompany.djinni_rest.HttpCallback;
import com.mycompany.djinni_rest.HttpMethod;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.StringWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import main.java.com.thepeaklab.djinnirest.interfaces.ImageRequestCallback;

/**
 * Created by thomas on 01.02.16.
 */
public class MyHttp extends Http {

    @Override
    public void send(HttpMethod httpMethod, final String urlString, final HttpCallback callback) {

        new android.os.AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... params) {

                int httpCode = 401;
                String response = null;

                try {
                    URL url = new URL(urlString);
                    HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                    httpCode = conn.getResponseCode();
                    BufferedInputStream iStream = new BufferedInputStream(conn.getInputStream());
                    response = getString(iStream, "UTF-8");
                } catch (MalformedURLException ex) {
                    // do nothing
                    callback.onFailure();
                } catch (IOException ex) {
                    // do nothing
                    callback.onFailure();
                }

                callback.onSuccess((short) httpCode, response);

                return null;
            }
        }.execute();
    }

    private static String getString(InputStream stream, String charsetName) throws IOException {
        int n = 0;
        char[] buffer = new char[1024 * 4];
        InputStreamReader reader = new InputStreamReader(stream, charsetName);
        StringWriter writer = new StringWriter();
        while (-1 != (n = reader.read(buffer))) {
            writer.write(buffer, 0, n);
        }
        return writer.toString();
    }

    public void getImage(final String urlString, final ImageRequestCallback imageRequestCallback) {
        new android.os.AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... params) {

                try {

                    URL obj = new URL(urlString);
                    HttpURLConnection conn = (HttpURLConnection) obj.openConnection();

                    System.out.println("Request URL ... " + urlString);

                    boolean redirect = false;

                    // normally, 3xx is redirect
                    int status = conn.getResponseCode();
                    if (status != HttpURLConnection.HTTP_OK) {
                        if (status == HttpURLConnection.HTTP_MOVED_TEMP
                                || status == HttpURLConnection.HTTP_MOVED_PERM
                                || status == HttpURLConnection.HTTP_SEE_OTHER)
                            redirect = true;
                    }

                    System.out.println("Response Code ... " + status);

                    if (redirect) {

                        // get redirect url from "location" header field
                        String newUrl = conn.getHeaderField("Location");

                        // get the cookie if need, for login
                        String cookies = conn.getHeaderField("Set-Cookie");

                        // open the new connnection again
                        conn = (HttpURLConnection) new URL(newUrl).openConnection();

                        System.out.println("Redirect to URL : " + newUrl);

                    }

                    Bitmap bmp = BitmapFactory.decodeStream(conn.getInputStream());


                    System.out.println("URL Content... \n" + bmp.getDensity());
                    System.out.println("Done");

                    imageRequestCallback.onSuccess(bmp);

                } catch (Exception e) {
                    e.printStackTrace();
                    imageRequestCallback.onError();
                }

                return null;
            }
        }.execute();
    }


}
