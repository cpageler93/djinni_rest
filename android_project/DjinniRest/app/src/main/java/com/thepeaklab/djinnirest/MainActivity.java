package com.thepeaklab.djinnirest;

import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.mycompany.djinni_rest.Api;
import com.mycompany.djinni_rest.ApiPhotosResponse;
import com.mycompany.djinni_rest.ApiPostsResponse;
import com.mycompany.djinni_rest.PhotoModel;
import com.mycompany.djinni_rest.PostModel;

import java.util.ArrayList;

import butterknife.Bind;
import butterknife.ButterKnife;
import main.java.com.thepeaklab.djinnirest.MyHttp;
import main.java.com.thepeaklab.djinnirest.MyThreadLauncher;
import main.java.com.thepeaklab.djinnirest.adapter.MyPhotoDataAdapter;
import main.java.com.thepeaklab.djinnirest.adapter.MyPostDataAdapter;
import main.java.com.thepeaklab.djinnirest.interfaces.ImageRequestCallback;
import main.java.com.thepeaklab.djinnirest.interfaces.MyPhotoItemClickLIstener;
import main.java.com.thepeaklab.djinnirest.interfaces.MyPostItemClickLIstener;

public class MainActivity extends AppCompatActivity {


    //load library
    static {
        System.loadLibrary("djinnirest_jni");
    }

    // define native interfaces
    private Api api;
    private MyThreadLauncher myThreadLauncher;
    private MyHttp mMyHttp;

    private MyPostDataAdapter mMyPostDataAdapter;
    private MyPhotoDataAdapter mMyPhotoDataAdapter;

    // ui elements
    @Bind(R.id.uiTime)
    TextView mTimer;

    @Bind(R.id.uiRecyclerView)
    RecyclerView mRecyclerView;

    private MyPhotoItemClickLIstener mMyPhotoItemClickLIstener = new MyPhotoItemClickLIstener() {


        @Override
        public void onLoadImage(PhotoModel model, TYPE type) {

            switch (type){
                case IMAGE:
                    loadImage(model.getUrl());
                    break;
                case THUMBNAIL:
                    loadImage(model.getThumbnailUrl());
                    break;
            }
        }
    };

    private MyPostItemClickLIstener mMyPostClickLIstener = new MyPostItemClickLIstener() {
        @Override
        public void onItemClicked(PostModel model, TYPE type) {
            switch (type) {
                case MODIFY:
                    modifyPostModel(model);
                    break;
                case VALIDATE:
                    validatePostModel(model);
                    break;
            }
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
        api = Api.createApi(myThreadLauncher, mMyHttp);

        mMyPostDataAdapter = new MyPostDataAdapter(mMyPostClickLIstener);
        mMyPhotoDataAdapter = new MyPhotoDataAdapter(mMyPhotoItemClickLIstener);

        mRecyclerView.setLayoutManager(new LinearLayoutManager(getApplicationContext(), LinearLayoutManager.VERTICAL, false));

    }


    /**
     * loadPosts
     */
    public void getPostsIndex(View v) {

        final long startTime = System.currentTimeMillis();

        clearOutput();

        mRecyclerView.setAdapter(mMyPostDataAdapter);

        // call posts (via c++)
        api.getPostsIndex(new ApiPostsResponse() {
            @Override
            public void onIndexSuccess(final ArrayList<PostModel> result) {
                calculateDuration("100 getPosts", startTime);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        mMyPostDataAdapter.setData(result);
                    }
                });
            }

            @Override
            public void onShowSuccess(PostModel result) {
                //not implemented here
            }

            @Override
            public void onFailure() {
                calculateDuration("100 getPosts FAIL ", startTime);
            }
        });

    }


    /**
     * getPostShow
     *
     * @param v
     */
    public void getPostShow(View v) {

        final long startTime = System.currentTimeMillis();

        clearOutput();

        mRecyclerView.setAdapter(mMyPostDataAdapter);

        api.getPostsShow(1, new ApiPostsResponse() {
            @Override
            public void onIndexSuccess(final ArrayList<PostModel> result) {
                // not implemented here
            }

            @Override
            public void onShowSuccess(final PostModel result) {
                calculateDuration("1 getPost", startTime);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        mMyPostDataAdapter.setData(result);
                    }
                });
            }

            @Override
            public void onFailure() {
                calculateDuration("1 getPost", startTime);
            }
        });

    }


    /**
     * loadPosts
     */
    public void getPhotosIndex(View v) {

        final long startTime = System.currentTimeMillis();

        clearOutput();

        mRecyclerView.setAdapter(mMyPhotoDataAdapter);

        // call posts (via c++)
        api.getPhotosIndex(new ApiPhotosResponse() {
            @Override
            public void onIndexSuccess(final ArrayList<PhotoModel> result) {
                calculateDuration("5000 getPhotos", startTime);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        mMyPhotoDataAdapter.setData(result);
                    }
                });
            }

            @Override
            public void onShowSuccess(PhotoModel result) {
                // not implemented here
            }

            @Override
            public void onFailure() {
                calculateDuration("5000 getPhotos FAIL", startTime);
            }
        });

    }


    /**
     * getPhotosShow
     *
     * @param v
     */
    public void getPhotosShow(View v) {

        final long startTime = System.currentTimeMillis();

        clearOutput();

        mRecyclerView.setAdapter(mMyPhotoDataAdapter);

        // call posts (via c++)
        api.getPhotosShow(1, new ApiPhotosResponse() {
            @Override
            public void onIndexSuccess(ArrayList<PhotoModel> result) {
                // not implemented here
            }

            @Override
            public void onShowSuccess(final PhotoModel result) {
                calculateDuration("1 getPhoto", startTime);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        mMyPhotoDataAdapter.setData(result);
                    }
                });
            }

            @Override
            public void onFailure() {
                calculateDuration("1 getPhoto FAIL", startTime);
            }
        });

    }


    /**
     * modifyPostModel
     *
     * @param model
     */
    public void modifyPostModel(PostModel model) {

        final long startTime = System.currentTimeMillis();

        final PostModel postModel = api.modifyPost(model);

        calculateDuration("modifyPost", startTime);

        final AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                final AlertDialog dialog = builder.create();

                dialog.setTitle("modified data");
                dialog.setMessage(postModel.toString());
                dialog.setButton(DialogInterface.BUTTON_POSITIVE, "close", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });

                dialog.show();

            }
        });
    }


    /**
     * modifyPostModel
     *
     * @param model
     */
    public void validatePostModel(PostModel model) {

        final long startTime = System.currentTimeMillis();

        final boolean valid = api.isPostValid(model);

        calculateDuration("validatePost", startTime);

        final AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                final AlertDialog dialog = builder.create();

                dialog.setTitle("validate data");
                dialog.setMessage("isValid = "+ valid);
                dialog.setButton(DialogInterface.BUTTON_POSITIVE, "close", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });

                dialog.show();

            }
        });
    }


    /**
     * loadImage
     *
     * @param url
     */
    private void loadImage(String url){

        final long startTime = System.currentTimeMillis();

        mMyHttp.getImage(url, new ImageRequestCallback() {
            @Override
            public void onSuccess(final Bitmap bmp) {

                calculateDuration("loadImage", startTime);

                final AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);

                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        final AlertDialog dialog = builder.create();

                        Drawable d = new BitmapDrawable(getResources(), bmp);
                        dialog.setTitle("image");
                        dialog.setButton(DialogInterface.BUTTON_POSITIVE, "close", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                            }
                        });

                        dialog.setIcon(d);
                        dialog.show();
                    }
                });
            }

            @Override
            public void onError() {

            }
        });

    }


    /**
     * endTimer
     *
     * @param trigger
     */
    public void calculateDuration(String trigger, long mStartTime) {
        final double duration = ((System.currentTimeMillis() - mStartTime) / 1000.0);
        Log.i("timer", "'" + trigger + "; duration ->" + duration + "Sek.");
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mTimer.setText(Double.toString(duration) + "Sek.");
            }
        });
    }


    /**
     * clearOutput
     */
    public void clearOutput() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mTimer.setText("Loading...");
                mMyPostDataAdapter.setData(new ArrayList<PostModel>());
                mMyPhotoDataAdapter.setData(new ArrayList<PhotoModel>());
            }
        });
    }


}
