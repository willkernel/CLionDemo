#include <stdio.h>
#include "a.h"
//重复引入
//fatal error C1014: 包含文件太多 : 深度 = 1024
//error: #include nested too deeply


//通过宏定义判断就可以解决这个问题
//#if A_H
//#include "b.h"
//void a();
//#endif


//预编译（预处理include、define）
//头文件告诉编译器有这样一个函数，连接器负责找到这个函数的实现，
//通过include引入，实现的话，在哪里都可以，类似于Android布局文件中的include标签

//C语音的执行流程
//编译：形成目标代码(.obj)。
//连接：将目标代码与C函数库连接合并，形成最终的可执行文件。
//执行

//宏定义、宏替换
//1.定义标识
//2.定义常数（便于修改与阅读）
//3.定义“宏函数”

//定义常数
#define MAX 100



//定义“宏函数” 实质上就是一个替换的过程
#define LOG(FORMAT, ...) printf("info"); printf(##FORMAT,__VA_ARGS__);
#define LOG_I(FORMAT, ...) printf("info"); printf(##FORMAT,__VA_ARGS__);
#define LOG_E(FORMAT, ...) printf("error"); printf(##FORMAT,__VA_ARGS__);

//LEVEL日志级别
#define LOG_E(LEVEL, FORMAT, ...) printf(##LEVEL); printf(##FORMAT,__VA_ARGS__);

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"abc",FORMAT,##__VA_ARGS__);


void main() {
#include "text.txt"

//    判断一些标识是否定义来判断是否支持某种语法、平台
//    表示支持C++语法
#ifdef _cplusplus
#endif
//    表示支持Android、Windows、苹果平台等等
#ifdef ANDROID
#endif

    if (MAX == 100) printf("max is 100");

//    LOGI("%s", "fix");
//    替换
//    __android_log_print(ANDROID_LOG_INFO,"abc","%s","fix");
}
