#pragma once
//新版本的时候通过#pragma once语句即可自动解决这个问题
//该头文件只被包含一次，编译器自动处理循环包含问题,并写在顶部

#include "b.h"

#ifndef PREBUILT_A_H
#define PREBUILT_A_H

#endif //PREBUILT_A_H
