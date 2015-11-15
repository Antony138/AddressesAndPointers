//
//  passByReference.c
//  AddressesAndPointers
//
//  Created by Antony on 15/11/15.
//  Copyright © 2015年 Antony. All rights reserved.
//

#include "passByReference.h"
#include <math.h>
// Pass By Reference 通过引用传递

// 将笛卡尔(Cartesian)坐标转换为极(polar)坐标
void createsianToPolar(float x, float y, double *rPtr, double *thetaPtr) {
    // 计算极坐标的极径,并通过指针(*号)来访问(写入)极径值
    *rPtr = sqrt(x * x + y * y);
    
    // 计算极坐标的极角
    float theta;
    if (x == 0.0) {
        if (y == 0.0) {
            theta = 0;
        } else if (y > 0) {
            theta = M_PI_2;
        } else {
            theta = - M_PI_2;
        }
    } else {
        theta = atan(y / x);
    }
    // 通过指针(*号)来访问(写入)极角值
    *thetaPtr = theta;
}