#include <iostream>
#include <cstring>
#include <vector>

#define N 100
using namespace std;

int main() {
    char str1[10] = "Hello";
    char str2[10] = "World";
    char str3[10];
    int len;
    strcpy(str3, str1);
    cout << "strcpy " << str3 << endl;

    strcat(str1, str2);
    cout << "strcat(str1,str2) " << str1 << endl;

    len = strlen(str1);
    cout << "len " << len << endl;

    string s1 = "Hello";
    string s2 = "World";
    string s3;
    s3 = s1;
    cout << "s3 " << str3 << endl;
    s3 = s1 + s2;
    cout << "s1 + s2 " << s3 << endl;
    cout << "len " << s3.length() << endl;
    cout << "size " << s3.size() << endl;

    char X[N];
    cin.getline(X, N);
    int a = 0, b = 0;
    for (int i = 0; i < N; ++i) {
        if (X[i] == '#' || X[i] == '\0') break;//为#为结束标志
        if (X[i] >= '0' && X[i] <= '9')
            a++;                                         //统计数字个数
        if ((X[i] >= 'a' && X[i] <= 'z') || (X[i] >= 'A' && X[i] <= 'Z'))
            b++;                                      //统计英文字母个数
    }
    cout << a << endl << b << endl;

    //字符串字面值与标准库string不是同一种类型
    string s("hello");
    cout << s.size() << endl;        //OK
    //cout<<"hello".size()<<endl;  //ERROR

    //strlen、sizeof与size()求字符串长度的区别
    cout << strlen("123") << endl;   //返回 3
    cout << sizeof("123") << endl;   //返回 4
    string ss = "123";
    cout << ss.size() << endl;        //返回 3

    //标准string库中的getline函数返回时会丢弃换行符const iterator与const_iterator的区别
//    vector<int>::const_iterator; //不能改变指向的值，自身的值可以改变
//    const vector<int>::iterator = a; //可以改变指向的值，自身的值不能改变
//    const vector<int>::const_iterator = 0; //自身的值和指向的值都是只读的

    //任何改变vector长度的操作都会使已存在的迭代器失效
    //如：在调用push_back之后，就不能再信赖指向vector的迭代器了
    vector<int> ivec;
    ivec.push_back(10);
    vector<int>::iterator it = ivec.begin();
    cout << *it << endl;// 10
    ivec.push_back(9);
    cout << *it << endl;//迭代器已经失效  51320512
    return 0;
}