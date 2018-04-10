#include <stdio.h>
#include <mem.h>
#include "jni.h"

JNIEXPORT void
JNICALL
Java_com_willkernel_app_ndkdemo_MainActivity_accessField(JNIEnv* env, jobject object) {
//    通过对象拿到class
    jclass clz = (*env)->GetObjectClass(env,object);
//    拿到对应属性的ID
    jfieldID fieldID = (*env)->GetFieldID(env,clz, "str", "Ljava/lang/String;");
//    通过属性ID拿到属性值
    jstring jstr = (jstring) (*env)->GetObjectField(env,object, fieldID);

    //通过Java字符串拿到C字符串，第三个参数是一个出参，用来告诉我们GetStringUTFChars内部是否复制了一份字符串
    //如果没有复制，那么出参为isCopy，这时候就不能修改字符串的值了，因为Java中常量池中的字符串是不允许修改的
    //（但是jstr可以指向另外一个字符串）
    char *cstr = (char *) (*env)->GetStringUTFChars(env,jstr, NULL);
    char *res = "I luv u";
    strcat(res, cstr);

    //重新生成jstring,并赋值给对应的属性
    jstring jstr_new = (*env)->NewStringUTF(env,res);
    (*env)->SetObjectField(env,object, fieldID, jstr_new);

    //最后释放资源，通知垃圾回收器来回收
    //良好的习惯就是，每次GetStringUTFChars，结束的时候都有一个ReleaseStringUTFChars与之呼应
    (*env)->ReleaseStringUTFChars(env,jstr_new, cstr);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}