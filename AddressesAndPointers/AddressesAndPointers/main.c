//
//  main.c
//  AddressesAndPointers
//
//  Created by Antony on 15/11/15.
//  Copyright © 2015年 Antony. All rights reserved.
//

#include <stdio.h>
#include "passByReference.h"

int main(int argc, const char * argv[]) {
#pragma mark - 指针基本概念
    int i = 0;
    int j = 2;
    int k = 3;
    
#pragma mark 获取某个变量的地址(&的作用)
    // 用&获取一个变量保存的地址
    printf("i在(地址)%p中保存它的值; j在(地址)%p保存它的值\n", &i, &j);

#pragma mark 通过指针保存地址(*号的作用1)
    // 星号作用1:声明指针变量
    int *p1 = &i;
    int *p2 = &j;
    printf("- 指针变量也有自己的地址,p1保存在%p上, p2保存在%p上\n", &p1, &p2);
    printf("- 一个指针占%lu个字节(bytes)\n", sizeof(int *));
    
    // 指针变量保存(指向)的地址，其实就是该指针变量的值(就好比如变量i保存的是0,变量p1保存的是0x7fff5fbff79c,仅此而已)
    printf("- 指针变量p1保存(指向)的地址是%p\n", p1);
#pragma mark 通过地址访问数据(*号的作用2)
    printf("- 指针变量p1指向地址保存的内容是%d\n", *p1);// 星号作用2:访问(读取)该指针变量指向地址的值
    printf("- 指针变量p2保存(指向)的地址是%p\n", p2);
    printf("- 指针变量p2指向地址保存的内容是%d\n", *p2);
    
    // 星号作用2:访问(写入)该指针变量指向地址的值
    *p1 = 1;
    printf("- 通过指针变量改值后,指针变量p1保存(指向)的地址是%p\n", p1);
    printf("- 通过指针变量改值后,指针变量p1指向地址保存的内容是%d\n", *p1);
    
    // 改变指针变量的值后，指针指向的值也改变了
    p1 = &k;
    printf("- 通过改变指针变量的值后,指针变量p1保存(指向)的地址是%p\n", p1);
    printf("- 通过改变指针变量的值后,指针变量p1指向地址保存的内容是%d\n", *p1);
    
    // 一行声明两个指针->为什么*号要紧贴着指针变量名?
    // 第1、4行正确声明了两个指针，而第2、3行都是生命了一个指针，一个float变量而已。
    // 所以,*号紧贴变量名，仅仅是为了看上去更清楚而已
    // __unused表示不需要使用的变量(有意为之)，如果不添加，编译器有警告
    __unused float *a, *b;
    __unused float* c, d;
    __unused float *e, f;
    __unused float* g, * h;
    
#pragma mark - 通过引用(指针)传递
    // 将笛卡尔坐标转换为极坐标
    double x = 3.0, y = 4.0;
    double radius, angle;
    // 因为该函数后面两个参数定义成一个指针，所以要传入的是地址
    createsianToPolar(x, y, &radius, &angle);
    printf("笛卡尔坐标x:%.2f,y:%.2f转换为极坐标为:极径:%.2f, 极角:%.2f\n", x, y, radius, angle);
    
    return 0;
}
