package main.java.com.thepeaklab.djinnirest.adapter;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.mycompany.djinni_rest.PhotoModel;
import com.thepeaklab.djinnirest.R;

import java.util.ArrayList;
import java.util.List;

import butterknife.Bind;
import butterknife.ButterKnife;
import main.java.com.thepeaklab.djinnirest.interfaces.MyPhotoItemClickLIstener;

/**
 * Created by thomas on 02.02.16.
 */
public class MyPhotoDataAdapter extends RecyclerView.Adapter<MyPhotoDataAdapter.ViewHolder> {

    List<PhotoModel> mDataList = new ArrayList<>();
    private boolean mSingleItemView = false;
    private MyPhotoItemClickLIstener mMyPhotoItemClickLIstener;

    public MyPhotoDataAdapter(MyPhotoItemClickLIstener myPhotoItemClickLIstener){
        mMyPhotoItemClickLIstener = myPhotoItemClickLIstener;
    }

    public void setData(List<PhotoModel> dataList) {
        mSingleItemView = false;
        mDataList = dataList;
        notifyDataSetChanged();
    }

    public void setData(PhotoModel postModel){
        mSingleItemView = true;
        mDataList.clear();
        mDataList.add(postModel);
        notifyDataSetChanged();
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_photo_model, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        final PhotoModel data = mDataList.get(position);

        holder.mData.setText("");
        holder.mData.append("id: " + data.getId());
        holder.mData.append("\nalbumId: " + data.getAlbumId());
        holder.mData.append("\ntitle: " + data.getTitle());
        holder.mData.append("\nurl: " + data.getUrl());
        holder.mData.append("\nthumbnailUrl: " + data.getThumbnailUrl());

        View.OnClickListener onClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch(v.getId()){
                    case R.id.uiBtnLoadImageUrl:
                        mMyPhotoItemClickLIstener.onLoadImage(data, MyPhotoItemClickLIstener.TYPE.IMAGE);
                        break;
                    case R.id.uiBtnLoadImageThumbnailUrl:
                        mMyPhotoItemClickLIstener.onLoadImage(data, MyPhotoItemClickLIstener.TYPE.THUMBNAIL);
                        break;
                }
            }
        };

        holder.mLoadImage.setOnClickListener(onClickListener);
        holder.mLoadThumbnail.setOnClickListener(onClickListener);

    }

    @Override
    public int getItemCount() {
        return mDataList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        @Bind(R.id.uiItemData)
        TextView mData;

        @Bind(R.id.uiBtnLoadImageUrl)
        Button mLoadImage;

        @Bind(R.id.uiBtnLoadImageThumbnailUrl)
        Button mLoadThumbnail;

        public ViewHolder(View itemView) {
            super(itemView);
            ButterKnife.bind(this, itemView);
        }
    }

}
