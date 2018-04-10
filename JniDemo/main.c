//注意：include<>是引入系统的头文件，include""是引入自己的头文件，因此这里需要改一下，否则会报错
#include <stdio.h>
#include "com_test_JniDemo.h"

//JNI开发流程
//编写native方法
//javah命令，生成.h头文件
//复制.h头文件到CPP工程中
//复制jni.h和jni_md.h文件到CPP工程中
//实现.h头文件中声明的函数
//生成dll文件
//配置dll文件所在目录到环境变量
//重启Eclipse


//动态库与静态库
//        不同平台下的区别：
//
//Linux平台下：动态库是.so，静态库是.a
//        Windows平台下：动态库是.dll，静态库是.lib
//        动态库与静态库的区别：
//
//如果使用静态库，全部都会包含在最终生成的exe文件动态库是不会包含的，运行的时候才会被程序加载进来
//动态库可以多个应用共享（加载即可），加载不加载可以随时由程序完成


//JNIEnv：JNIEnv里面有很多方法，与Java进行交互，代表Java的运行环境 JNI Environment
//在C中：
//JNIEnv 结构体指针的别名 env 二级指针
//在C++中：
//JNIEnv 是一个结构体的别名 env 一级指针

//为什么要用二级指针：
//为什么需要传入JNIEnv？函数执行过程中需要JNIEnv
//C++为什么没有传入？因为C++中有this指针
//C++只是对C的那一套进行的封装，给一个变量赋值为指针，这个变量是二级指针

JNIEXPORT jstring JNICALL Java_com_test_JniDemo_getStringFromC
        (JNIEnv * env, jclass jcls){
    return (*env)->NewStringUTF(env, "String From C");
}

int main() {
    printf("Hello, World!\n");
    return 0;
}