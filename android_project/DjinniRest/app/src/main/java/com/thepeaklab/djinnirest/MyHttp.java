package main.java.com.thepeaklab.djinnirest;

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
}
