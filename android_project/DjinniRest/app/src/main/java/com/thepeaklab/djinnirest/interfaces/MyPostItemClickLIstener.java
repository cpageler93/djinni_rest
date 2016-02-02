package main.java.com.thepeaklab.djinnirest.interfaces;

import android.view.View;

import com.mycompany.djinni_rest.PostModel;

/**
 * Created by thomas on 02.02.16.
 */
public interface MyPostItemClickLIstener {

    enum TYPE {MODIFY, VALIDATE};

    void onItemClicked(PostModel model, TYPE type);

}
