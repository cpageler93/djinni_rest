// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

package com.mycompany.djinni_rest;

import java.util.ArrayList;

/**
 *hello_model = record {
 *	welcome_title: string;
 *}
 */
public abstract class ApiPhotosResponse {
    public abstract void onIndexSuccess(ArrayList<PhotoModel> result);

    public abstract void onShowSuccess(PhotoModel result);

    public abstract void onFailure();
}
