//
//  main.cpp
//  MemCpy
//
//  Created by Kieran Will on 10/9/16.
//  Copyright © 2016 liuw53. All rights reserved.
//


// 实现内存拷贝函数


#include <iostream>
using namespace std;

void myMemCpy(const void *dst, const void *src, size_t count) {
    if (dst == NULL) return;
    if (src == NULL) return;
    
    
    unsigned char *pdst = (unsigned char *)dst;
    const unsigned char *psrc = (const unsigned char *)src;
    
    
    
    // 检验是否有重叠
    if (psrc <= pdst && pdst < psrc + count) return;
    if (pdst <= psrc && psrc < pdst + count) return;
    
    
    // 拷贝
    while (count --) {
        *pdst = *psrc;
        pdst ++;
        psrc ++;
    }
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/**
 这个题目在面试出现的次数太频繁，能够比较正确的写出这个函数的能说明什么呢？
 1.缺乏项目经验，对于面试因此复习的很到位。
 2.有可能有丰富的项目经验，在项目中也这么做。
 3.认为有较多项目经验，但是没有注意非功能性要求。等着杯具吧。
*/