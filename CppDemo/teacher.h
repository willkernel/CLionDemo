//
// Created by willkernel on 2018/1/5.
//
//C++中类的写法
//定义一般写在头文件中，实现在源文件中

//预编译一次，防止循环依赖
#pragma once
class Teacher{
public:
    Teacher();
    ~Teacher();
};