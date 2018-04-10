#include <stdio.h>
#include <pbt.h>

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

void msg(char *msg, char *title) {
    //c语言里面字符串用char指针代替
    MessageBox(0, msg, title, 0);
}

/**NOTE
可以看到，msg函数调用的时候需要传一个函数指针，参数是两个整型，返回值是整型。msg函数的执行需要执行我们手动传入的代码（函数），从而实现了回调（注入代码）。
函数指针的使用，Java中new 内部类，类似Java的回调（比回调更加强大）。
函数指针，提高复用性，在C语音的回调机制里面非常重要*/
void msg1(int(*function_p)(int a, int b), int a, int b) {
    //调用函数指针的函数
    int res = function_p(a, b);
    printf("%d\n", res);
}

int main() {
    //直接调用
    msg("content", "title");

    //定义一个函数指针指向msg函数
    //方法：返回类型，指针名字，参数列表，后面也可以通过typedef 关键字定义一个新的类型
    //参数名可以省略，将函数指针指向msg函数
    void (*fun)(char *msg, char *title)=msg;
    int (*addFun)(int a, int b)=add;
    int (*minusFun)(int a, int b)=minus;

    //使用函数指针去间接调用msg函数
    fun("i love u", "c");

    msg1(add, 1, 2);
    msg1(minus, 2, 3);
    return 0;
}
