#include <iostream>
#include <fstream>

using namespace std;

void fun1() {
    //    文本文件操作
//    写二进制文件
    char *f_path = "E:\\CLion\\CppIO\\test.txt";
    ofstream f_out(f_path);
    if (f_out.bad()) {
        //文件打开失败
        return;
    }
    f_out << "baby" << endl;
    f_out << "I luv u" << endl;
    f_out.close();

    //读二进制文件
    ifstream f_in(f_path);
    if (f_in.bad()) {
        //文件打开失败
        return;
    }
    char ch;
    while (f_in.get(ch)) {
        cout << ch;
    }
    f_in.close();
}

//二进制文件操作,复制图片
void fun2() {
    char *src = "E:\\CLion\\CppIO\\s2.png";
    char *dest = "E:\\CLion\\CppIO\\dest.png";

    //输入流
    ifstream fin(src, ios::binary);
    //输出流
    ofstream fout(dest, ios::binary);

    if (fin.bad() || fout.bad()) {
        return;
    }

    while (!fin.eof()) {
        //读取
        char buff[1024];
        fin.read(buff, 1024);

        //写入
        fout.write(buff, 1024);
    }

    fin.close();
    fout.close();
}

//c++对象持久化
class Person {
public:
    Person() {

    }

    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    void print() {
        cout << name << "," << age << endl;
    }

private:
    char *name;
    int age;
};


//持久化、逆持久化
void fun3() {
    Person p1("liuyan", 22);
    Person p2("rose", 14);

    char *path = "E:\\CLion\\CppIO\\c_obj.data";
    //输出流
    ofstream fout(path, ios::binary);
    fout.write((char *) &p1, sizeof(Person));//指针能够读取到正确的数据，读取内存区的长度
    fout.write((char *) &p2, sizeof(Person));
    fout.close();

    //输入流
    ifstream fin(path, ios::binary);
    Person tmp;
    fin.read((char *) &tmp, sizeof(Person));
    tmp.print();

    fin.read((char *) (&tmp), sizeof(Person));
    tmp.print();


}

int main() {
    fun1();
    fun2();
    fun3();
    return 0;
}