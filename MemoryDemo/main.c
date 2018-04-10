#include <stdio.h>
#include <malloc.h>

//C 里面的内存划分
//栈区（栈内存，存放局部变量，自动分配和释放，里面函数的参数，方法里面的临时变量）
//堆区（动态内存分配，C语音里面由程序员手动分配），最大值为操作系统的80%
//全局区（静态区）
//常量区（字符串）
//程序代码区

//静态与动态内存分配
//在程序运行过程中，动态指定需要使用的内存大小，手动释放，释放之后这些内存还可以被重新使用。
//静态内存分配，分配内存大小的是固定，问题：1.很容易超出栈内存的最大值 2.为了防止内存不够用会开辟更多的内存，容易浪费内存。


void main() {
    //下面的代码会导致栈溢出
    //属于静态内存分配，分配到栈里面，Window里面每一个应用栈大概是2M，大小确定,与操作系统有关
//    int a [1024 * 1024 * 10 * 4];

    //堆存分配,40M
    //参数：字节 KB M 10M 40M
    //开辟
    int *p1 = (int *) malloc(1024 * 1024 * 10 * sizeof(int));
    //释放
    free(p1);


//    通过动态内存分配来动态指定数组的大小
    int len;
    scanf("%d\n", &len);
    printf("sizeof(int) %d\n", sizeof(int));
    printf("len %d\n", len);

//    int* arr = (int *) malloc(len * sizeof(int));
//  另外一种方法
    int* arr = (int *) calloc(len, sizeof(int));

    int i = 0;
    for (; i < len; ++i) {
        arr[i] = i % 100;
        printf("%d,%#x\n",arr[i],&arr[i]);
    }
//    free(arr);
    printf("\n\n");


//重新分配内存的两种情况：
//缩小，缩小的那一部分数据会丢失
//扩大，（连续的）
//1.如果当前内存段后面有需要的内存空间，直接扩展这段内存空间，realloc返回原指针
//2.如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块，将目前的数据复制到新的位置，
//  并将原来的数据库释放掉，返回新的内存地
//3.如果申请失败，返回NULL，原来的指针仍然有效
    int addLen=10;
//    用realloc扩大内存： 1.原来内存的指针 2.内存扩大后的总大小
    int* p2=(int*)realloc(arr,(len+addLen)* sizeof(int));

    i=0;
    for (; i <len+addLen ;i ++) {
        p2[i]=i%200;
        printf("%d,%#x\n",p2[i],&p2[i]);
    }

//    释放内存的细节问题
//    不能多次释放（否则会产生中断）
//    释放完之后（指针仍然有值），给指针置NULL，标志释放完成
//    内存泄露（p重新赋值之后，再free，并没有真正释放内存（之前的内存））

//    安全释放的例子
    if (arr!=NULL) {
        free(arr);
        arr=NULL;
    }
    if (p2!=NULL) {
        free(p2);
        arr=NULL;
    }

    //分配40M
    int* p = (int*)malloc(1024*1024*40);

    //下一次分配之前，如果不释放，会造成40M的内存泄漏
    free(p);
    p = NULL;

    //分配80M
    p = (int*)malloc(1024*1024*80);
    free(p);
}