package main.java.com.thepeaklab.djinnirest.interfaces;

import android.graphics.Bitmap;

/**
 * Created by thomas on 01.02.16.
 */
public interface ImageRequestCallback {

    void onSuccess(Bitmap bmp);
    void onError();
}
