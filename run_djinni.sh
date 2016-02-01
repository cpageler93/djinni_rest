#! /usr/bin/env bash

base_dir=$(cd $(dirname 0) && pwd)
cpp_out="$base_dir/generated-src/cpp"
jni_out="$base_dir/generated-src/jni"
objc_out="$base_dir/generated-src/objc"
java_out="$base_dir/generated-src/java/com/mycompany/djinni_rest"
java_package="com.mycompany.djinni_rest"
namespace="djinni_rest_gen"
objc_prefix="Native"
djinni_file="djinni/djinni_rest.djinni"

deps/djinni/src/run \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
   \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   \
   --jni-out $jni_out \
   --ident-jni-class NativeFooBar \
   --ident-jni-file NativeFooBar \
   \
   --objc-out $objc_out \
   --objc-type-prefix $objc_prefix \
   \
   --objcpp-out $objc_out \
   \
   --cpp-optional-template std::experimental::optional \
   --cpp-optional-header "<experimental/optional>" \
   \
   --idl $djinni_file