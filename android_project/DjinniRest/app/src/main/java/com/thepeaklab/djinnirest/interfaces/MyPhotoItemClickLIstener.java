package main.java.com.thepeaklab.djinnirest.interfaces;

import com.mycompany.djinni_rest.PhotoModel;

/**
 * Created by thomas on 02.02.16.
 */
public interface MyPhotoItemClickLIstener {

    enum TYPE {IMAGE, THUMBNAIL};

    void onLoadImage(PhotoModel model, TYPE type);

}
