#include <iostream>
#include <ctime>

using namespace std;

int max(int, int);

void fun_swap_value(int, int);

void fun_swap_point(int *, int *);

void fun_swap_cite(int &x, int &y);

void fun_pptr();

void ptrArray();

void ptrCompare();

void getSeconds(unsigned long *par);

void getAvg(int *ptr, int size);

int *getRandom();

/**C++11 提供了对匿名函数的支持,称为 Lambda 函数
 * Lambda 表达式本质上与函数声明非常类似。Lambda 表达式具体形式
 * [capture](parameters) mutable ->return-type{statement}
 * [capture]：捕捉列表。捕捉列表总是出现在 lambda 表达式的开始处。事实上，[] 是 lambda 引出符。编译器根据该引出符判断接下来的代码是否是 lambda 函数。捕捉列表能够捕捉上下文中的变量供 lambda 函数使用。
 (parameters)：参数列表。与普通函数的参数列表一致。如果不需要参数传递，则可以连同括号 () 一起省略。
 mutable：mutable 修饰符。默认情况下，lambda 函数总是一个 const 函数，mutable 可以取消其常量性。在使用该修饰符时，参数列表不可省略（即使参数为空）。
 ->return_type：返回类型。用追踪返回类型形式声明函数的返回类型。出于方便，不需要返回值的时候也可以连同符号 -> 一起省略。此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
 {statement}：函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量
 *
 * 在Lambda表达式内可以访问当前作用域的变量，这是Lambda表达式的闭包（Closure）行为。
 * 与JavaScript闭包不同，C++变量传递有传值和传引用的区别。可以通过前面的[]来指定：
 * []      // 沒有定义任何变量。使用未定义变量会引发错误。
   [x, &y] // x以传值方式传入（默认），y以引用方式传入。
   [&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
   [=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
   [&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
   [=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
 * */
class LambdaTest {
public:
    void lambda() {

        int global_x = 0;
        //没有返回值
        [&global_x] { ++global_x; };
        //返回true，false
        [](int x, int y) { return x > y; };
        //指定返回int
        [](int x, int y) -> int {
            int z = x + y;
            return z + x;
        };
        [this]() { this->someFunc(); }();
        [] {};//最简单的lambda表达式
    }

    /**函数调用运算符的重载方法是const属性的
     * 有时候，你想改动传值方式捕获的值，那么就要使用mutable*/
    void someFunc() {
        int x = 10;

        auto add_x = [x](int a) mutable {
            x *= 2;
            return a + x;
        };  // 复制捕捉x

        cout << add_x(10) << endl; // 输出 30
    }
};

int main() {
    int a = 100;//实际整型变量
    int b = 200;
    char var1[10];
    //变量的地址
    cout << "a address " << &a << endl;
    cout << "var1 address " << &var1 << endl;
    //指针是一个变量，值为变量的地址,下面不同类型的指针的值
    //都是代表内存地址的十六进制数，指针所指向的变量类型不同
    int *ip = &a;//定义整型指针，并赋值变量的地址
    //输出在指针变量中存储的地址
    cout << "ip address " << ip << endl;
    //访问指针中地址的变量值
    cout << "*ip value " << *ip << endl;
    double *dp;//double型的指针
    float *fp;//float型的指针
    char *cp;//char型的指针

    //为指针变量赋一个 NULL 值是一个良好的编程习惯
    //赋为 NULL 值的指针被称为空指针
    //NULL 指针是一个定义在标准库中的值为零的常量
    //该指针不指向一个可访问的内存位置
    int *ptr0 = NULL;
    cout << "ptr value is " << ptr0 << endl;
    if (!ptr0) cout << "ptr is NULL" << endl;

    int var[3] = {10, 100, 200};
    int *ptr;
    ptr = var;
    //指针中第一个元素的地址，这里不使用&var，指针类型不一致，但是与&var[0]相同
    //因为ptr指向的是int *var[0]的地址,而不是int[3] *var
    //ptr = &var[0];//也可以使用这种方式
    cout << "*int[3] &var address " << &var << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "index " << i << " address is " << ptr << " value is " << *ptr << endl;
        //移动到下一个位置
        ptr++;
        //index 0 address is 0x61feec value is 10
        //index 1 address is 0x61fef0 value is 100
        //index 2 address is 0x61fef4 value is 200
        //如果这里指针指向的变量是整型数据 1000，占4个字节，移动到下个整数，当前位置往后移4个字节,地址是1004
        //相应的如果这个变量是字符数据，占1个字节，移动到下个字符，当前位置往后移1个字节,地址是1001
    }

    //var++;不正确,是数组第一个元素的常量，不能作为左值
    //var[2]=500;
    *(var + 2) = 500;

    cout << "---------" << endl;
    ptrCompare();
    cout << "---------" << endl;

    //指针数组，包含指针的数组
    ptrArray();

    cout << "---------" << endl;

    //二级指针，指向指针的指针，多级间接寻址
    fun_pptr();

    cout << "---------" << endl;
    int ret = max(a, b);
    cout << "max :" << ret << endl;

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    fun_swap_value(a, b);
    cout << "fun_swap_value a=" << a << endl;
    cout << "fun_swap_value b=" << b << endl;

    /** 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址
    * &b 表示指向 b 的指针，即变量 b 的地址
    */
    fun_swap_point(&a, &b);
    cout << "fun_swap_point a=" << a << endl;
    cout << "fun_swap_point b=" << b << endl;

    fun_swap_cite(a, b);
    cout << "fun_swap_cite a=" << a << endl;
    cout << "fun_swap_cite b=" << b << endl;
    cout << "---------" << endl;

    /**传递指针给函数，声明函数参数为指针类型*/
    unsigned long sec;
    getSeconds(&sec);
    // 输出实际值
    cout << "Number of seconds :" << sec << endl;
    cout << "---------" << endl;
    int balance[5] = {1000, 2000, 3000, 4000, 6000};
    getAvg(balance, 5);
    cout << "---------" << endl;

    int *random = getRandom();
    for (int j = 0; j < 10; ++j) {
        cout << "*(random + " << j << ") : ";
        cout << *(random + j) << endl;
    }

    cout << "---------" << endl;

    LambdaTest t;
    t.lambda();
    cout << "----END-----" << endl;
    return 0;
}

void ptrCompare() {
    int var[3] = {10, 100, 200};
    int *ptr;
    ptr = var;
    int i = 0;
    while (ptr <= &var[2]) {
        cout << "index " << i << " address is " << ptr << " value is " << *ptr << endl;
        //指向下一个位置
        ptr++;
        i++;
    }
}

void ptrArray() {
    int var[3] = {10, 100, 200};
    int *ptrAry[3];
    for (int j = 0; j < 3; ++j) {
        ptrAry[j] = &var[j];
    }
    for (int k = 0; k < 3; ++k) {
        cout << "Value of ptrAry[" << k << "] = ";
        cout << *ptrAry[k] << endl;
    }

    const char *names[4] = {
            "Zara Ali",
            "Hina Ali",
            "Nuha Ali",
            "Sara Ali",
    };
    for (int m = 0; m < 4; m++) {
        cout << "Value of names[" << m << "] = ";
        cout << names[m] << endl;
        cout << &names[m] << endl;
        cout << *names[m] << endl;//指向的是字符串的第一个字符
        cout << *names[m] + 1 << endl;//第一个字符+1 转换ASCII值
        cout << *(names[m] + 1) << endl;//指向的是字符串的第二个字符
    }
}

/**多级间接寻址*/
void fun_pptr() {
    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    ptr = &var;
    pptr = &ptr;
    cout << "Value of var :" << var << endl;
    cout << "Value available at *ptr :" << *ptr << endl;
    cout << "Value available at **pptr :" << **pptr << endl;
}

void getSeconds(unsigned long *par) {
    *par = time(NULL);
}

void getAvg(int *ptr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ptr[i];
    }
    double avg = double(sum) / size;
    cout << "avg is " << avg << endl;
}

/**函数返回指针*/
int *getRandom() {
    static int r[10];
    //设置种子
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}

int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * 传值调用,默认情况下，C++ 使用传值调用来传递参数
 * 实际参数的参数值传值给形式参数，调用不会影响实际参数*/
void fun_swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

/**指针调用
 * 实际参数的地址传给形式参数，修改形式参数会影响实际参数
 */
void fun_swap_point(int *a, int *b) {
    int temp;
    temp = *a; // 保存地址 x 的值
    *a = *b; //把 y 赋值给 x
    *b = temp; //把 x 赋值给 y
}

/**引用调用
 * 把引用的地址复制给形式参数。在函数内，
 * 该引用用于访问调用中要用到的实际参数，修改形式参数会影响实际参数*/
void fun_swap_cite(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
