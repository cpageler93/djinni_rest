package main.java.com.thepeaklab.djinnirest;

import com.mycompany.djinni_rest.AsyncTask;
import com.mycompany.djinni_rest.ThreadLauncher;

/**
 * Created by thomas on 01.02.16.
 */
public class MyThreadLauncher extends ThreadLauncher {
    @Override
    public void startThread(String name, final AsyncTask runFn) {
        new android.os.AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... params) {
                runFn.execute();
                return null;
            }
        }.execute();
    }
}
