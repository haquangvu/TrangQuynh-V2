//
//  MyRatingStar.h
//  SacVietDigitalBook
//
//  Created by vuha on 5/23/14.
//  Copyright (c) 2014 Pops. All rights reserved.
//

#ifndef __SacVietDigitalBook__MyRatingStar__
#define __SacVietDigitalBook__MyRatingStar__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MyRatingStar:public CCLayer {
    CCMenuItemToggle *star1;
    CCMenuItemToggle *star2;
    CCMenuItemToggle *star3;
    CCMenuItemToggle *star4;
    CCMenuItemToggle *star5;
    
public:
    MyRatingStar();
    ~MyRatingStar();
    
    virtual bool init();
    CREATE_FUNC(MyRatingStar);
    void valueChanged(CCControlSlider *sender, CCControlEvent controlEvent);
    void callback();
};


#endif /* defined(__SacVietDigitalBook__MyRatingStar__) */
