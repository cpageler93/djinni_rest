package com.thepeaklab.djinnirest;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.annotation.BinderThread;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import com.mycompany.djinni_rest.Api;
import com.mycompany.djinni_rest.ApiPhotosResponse;
import com.mycompany.djinni_rest.ApiPostsResponse;
import com.mycompany.djinni_rest.PhotoModel;
import com.mycompany.djinni_rest.PostModel;

import java.util.ArrayList;

import butterknife.Bind;
import butterknife.ButterKnife;
import main.java.com.thepeaklab.djinnirest.ImageRequestCallback;
import main.java.com.thepeaklab.djinnirest.MyHttp;
import main.java.com.thepeaklab.djinnirest.MyThreadLauncher;

public class MainActivity extends AppCompatActivity {


    //load library
    static {
        System.loadLibrary("djinnirest_jni");
    }

    // define native interfaces
    private MyThreadLauncher myThreadLauncher;
    private MyHttp mMyHttp;

    // ui elements
    @Bind(R.id.imageresult)
    ImageView uiImageView;

    // define request callback
    private ApiPostsResponse mApiPostsResponse = new ApiPostsResponse() {
        @Override
        public void onIndexSuccess(ArrayList<PostModel> result) {
            Log.d("onIndexSuccess", result.toString());
        }

        @Override
        public void onShowSuccess(PostModel result) {
            Log.d("onShowSuccess", result.toString());
        }

        @Override
        public void onFailure() {
            Log.d("onFailure", "");
        }
    };


    /**
     * on create activity
     *
     * @param savedInstanceState
     */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        //bind butterknife
        ButterKnife.bind(this);

        // initialize native variables
        myThreadLauncher = new MyThreadLauncher();
        mMyHttp = new MyHttp();

        // generate Api
        final Api api = Api.createApi(myThreadLauncher, mMyHttp);

        // call posts (via c++)
        api.getPostsIndex(mApiPostsResponse);

        // call single post by id (via c++)
        api.getPostsShow(1, mApiPostsResponse);

        api.getPhotosIndex(new ApiPhotosResponse() {
            @Override
            public void onIndexSuccess(final ArrayList<PhotoModel> result) {
                for(int i=0; i<result.size(); i++){
                    if(i==0){
                        PhotoModel photoModel = result.get(0);
                        mMyHttp.getImage(photoModel.getUrl(), new ImageRequestCallback() {
                            @Override
                            public void onSuccess(final Bitmap bmp) {
                                Log.d("ImageRequestCallback", "success");
                                runOnUiThread(new Runnable() {
                                    @Override
                                    public void run() {
                                        uiImageView.setImageBitmap(bmp);
                                    }
                                });
                            }

                            @Override
                            public void onError() {
                                Log.d("ImageRequestCallback", "error");
                            }
                        });
                    }
                    else{
                        break;
                    }
                }
            }

            @Override
            public void onShowSuccess(PhotoModel result) {

            }

            @Override
            public void onFailure() {

            }
        });

    }

}
