package main.java.com.thepeaklab.djinnirest.adapter;

import android.content.DialogInterface;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.mycompany.djinni_rest.PostModel;
import com.thepeaklab.djinnirest.R;

import java.util.ArrayList;
import java.util.List;

import butterknife.Bind;
import butterknife.ButterKnife;
import main.java.com.thepeaklab.djinnirest.interfaces.MyPostItemClickLIstener;

/**
 * Created by thomas on 02.02.16.
 */
public class MyPostDataAdapter extends RecyclerView.Adapter<MyPostDataAdapter.ViewHolder> {

    List<PostModel> mDataList = new ArrayList<>();
    private boolean mSingleItemView = false;
    private MyPostItemClickLIstener mMyPostItemClickLIstener;

    public MyPostDataAdapter(MyPostItemClickLIstener myPostItemClickLIstener){
        mMyPostItemClickLIstener = myPostItemClickLIstener;
    }

    public void setData(List<PostModel> dataList) {
        mSingleItemView = false;
        mDataList = dataList;
        notifyDataSetChanged();
    }

    public void setData(PostModel postModel){
        mSingleItemView = true;
        mDataList.clear();
        mDataList.add(postModel);
        notifyDataSetChanged();
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_post_model, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        final PostModel data = mDataList.get(position);

        holder.mData.setText("");
        holder.mData.append("id: " + data.getId());
        holder.mData.append("\ntitle: " + data.getTitle());

        if(mSingleItemView){
            holder.mData.append("\nbody: " + data.getBody());
        }

        View.OnClickListener clickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                switch(v.getId()){
                    case R.id.uiBtnModifyPost:
                        mMyPostItemClickLIstener.onItemClicked(data, MyPostItemClickLIstener.TYPE.MODIFY);
                        break;
                    case R.id.uiBtnValidatePost:
                        mMyPostItemClickLIstener.onItemClicked(data, MyPostItemClickLIstener.TYPE.VALIDATE);
                        break;
                }

            }
        };

        holder.mModifyBtn.setOnClickListener(clickListener);
        holder.mValidateBtn.setOnClickListener(clickListener);

    }

    @Override
    public int getItemCount() {
        return mDataList.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        @Bind(R.id.uiItemData)
        TextView mData;

        @Bind(R.id.uiBtnModifyPost)
        Button mModifyBtn;

        @Bind(R.id.uiBtnValidatePost)
        Button mValidateBtn;

        public ViewHolder(View itemView) {
            super(itemView);
            ButterKnife.bind(this, itemView);
        }
    }

}
