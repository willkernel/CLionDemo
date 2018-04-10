#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void main() {
    //game time
    int time = 60;

    printf("%#x\n", &time);
    //0x61ff1c

    int *p = NULL;
    printf("%#x\n", p);
//    cannot open output file TimeGameDemo.exe: Permission denied
//    资源占用，停止程序
//    某些比较小的地址操作系统不允许访问（访问冲突）
//    *p =100;
//    多级指针（主要讨论二级）
//    指针变量保存的是变量的地址，可以是一个指针变量的地址，这时候就是多级指针了。
//    多级指针的意义：
//    动态内存分配二维数组，操作数组的时候。
//    在jni.h中的struct JNIEnv结构体等有用到。

    int a = 50;
    int *p1 = &a;
//    p2是一个二级指针，存放的是p1的值（即a的地址）
    int **p2 = &p1;
    printf("%d\n", **p2);


    while (time > 0) {
        time--;
        printf("game time left:%d\n", time);
        Sleep(1000);//#include <Windows.h>
    }
    system("pause");
}