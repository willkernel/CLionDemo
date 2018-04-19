#include <iostream>

using namespace std;

// 函数声明 引用调用函数
void swap(int &x, int &y);

double &setValues(int i);

double vals[] = {10.2, 13.4, 15.6, 23.5, 67.2};

int main() {
    int i = 17;
    double d = 15.5;
    int &r = i;
    double &s = d;

    cout << "i:" << i << endl;
    cout << "r:" << r << endl;
    cout << "d:" << d << endl;
    cout << "s:" << s << endl;

    // 局部变量声明
    int a = 100;
    int b = 200;

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    /* 调用函数来交换值 */
    swap(a, b);

    cout << " a:" << a << endl;
    cout << " b:" << b << endl;

    setValues(1) = 18.6;
    setValues(3) = 19.3;

    for (int j = 0; j < 5; ++j) {
        cout << "j:" << j << "-" << vals[j] << endl;
    }

    //r 的值发生改变，但是指向的地址未变
    r=a;
    cout << "r: " << r << endl;
    cout<<"address a "<<&a<<endl;
    cout<<"address r "<<&r<<endl;
    cout<<"address i "<<&i<<endl;

    return 0;
}

// 函数定义
void swap(int &x, int &y) {
    int temp;
    temp = x; /* 保存地址 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y  */

}

double &setValues(int i) {
    return vals[i];// 返回第 i 个元素的引用
}

//（1）以引用返回函数值，定义函数时需要在函数名前加 &
//（2）用引用返回一个函数值的最大好处是，在内存中不产生被返回值的副本。
//引用作为返回值，必须遵守以下规则：
// （1）不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
// （2）不能返回函数内部new分配的内存的引用。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部new分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一 个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由new分配）就无法释放，造成memory leak
// （3）可以返回类成员的引用，但最好是const。主要原因是当对象的属性是与某种业务规则（business rule）相关联的时候，其赋值常常与某些其它属性或者对象的状态有关，因此有必要将赋值操作封装在一个业务规则当中。如果其它对象可以获得该属性的非常 量引用（或指针），那么对该属性的单纯赋值就会破坏业务规则的完整性
//当返回一个引用时，要注意被引用的对象不能超出作用域
//所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用
int& func() {
    int q;
    //return q; // 在编译时发生错误
    static int x;
    return x;     // 安全，x 在函数作用域外依然是有效的
}