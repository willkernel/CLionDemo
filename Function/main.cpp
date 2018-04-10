#include <iostream>
#include <ctime>

using namespace std;

int max(int, int);

void fun_swap_value(int, int);

void fun_swap_point(int *, int *);

void fun_swap_cite(int, int);

void fun_pptr();

void ptrArray();

void ptrCompare();

void getSeconds(unsigned long *par);

void getAvg(int *ptr, int size);

int *getRandom();

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


    /** 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址
    * &b 表示指向 b 的指针，即变量 b 的地址
    */
    fun_swap_point(&a, &b);
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
 * 传值调用
 * 实际参数的参数值传值给形式参数，调用不会影响实际参数*/
void fun_swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "fun_swap_value a=" << a << endl;
    cout << "fun_swap_value b=" << b << endl;
}

/**指针调用
 * 实际参数的地址传给形式参数，修改形式参数会影响实际参数
 */
void fun_swap_point(int *a, int *b) {
    int temp;
    temp = *a; // 保存地址 x 的值
    *a = *b; //把 y 赋值给 x
    *b = temp; //把 x 赋值给 y
    cout << "fun_swap_point a=" << a << endl;
    cout << "fun_swap_point b=" << b << endl;
}

void fun_swap_cite(int) {

}