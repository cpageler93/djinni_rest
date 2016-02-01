package com.thepeaklab.djinnirest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;

import com.mycompany.djinni_rest.Api;
import com.mycompany.djinni_rest.ApiPostsResponse;
import com.mycompany.djinni_rest.PostModel;

import java.util.ArrayList;

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

        // initialize native variables
        myThreadLauncher = new MyThreadLauncher();
        mMyHttp = new MyHttp();

        // generate Api
        Api api = Api.createApi(myThreadLauncher, mMyHttp);

        // call posts (via c++)
        api.getPostsIndex(mApiPostsResponse);

        // call single post by id (via c++)
        api.getPostsShow(1, mApiPostsResponse);

    }

}
