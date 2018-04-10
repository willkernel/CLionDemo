#include <iostream>

using namespace std;

//函数声明
void func();

extern void write_extern();

int sum;
int ival;
int *pval;
static int count = 10;/*全局变量*/
int main() {
//    ival=pval=0; //error 尽管ival和pval都可以赋值为0
    while (count--) {
        func();
    }
    sum = 3;
    write_extern();

    int i = -5;
    unsigned int ii = 1;
    cout << (i > ii) << endl; //输出1，非常有趣的结果 原因是int型的i转换为unsigned int型
    short s = -5;
    unsigned short ss = 1;
    cout << (s > ss) << endl; //输出0 比较时short和unsigned short都提升为int型

    return 0;
}

//函数定义
void func() {
    static int i = 5;//局部静态变量
    i++;
    cout << "var i =" << i;
    cout << " , var count=" << count << endl;
}