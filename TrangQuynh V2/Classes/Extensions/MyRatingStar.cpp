//
//  MyRatingStar.cpp
//  SacVietDigitalBook
//
//  Created by vuha on 5/23/14.
//  Copyright (c) 2014 Pops. All rights reserved.
//

#include "MyRatingStar.h"
#include "Constants.h"
#include "CCControlSlider.h"



MyRatingStar::MyRatingStar(){
    
}

MyRatingStar::~MyRatingStar(){
    
}

bool MyRatingStar::init(){
    
    CC_RETURNBOOL_IF(!CCLayer::init());
    
    star1 = CCMenuItemToggle::createWithTarget(this,
                                                                 menu_selector(MyRatingStar::callback),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_empty_big.png"), NULL),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_full_big.png"), NULL),
                                                                 NULL);
    star1->setPosition(CCPointZero);
    
    star2 = CCMenuItemToggle::createWithTarget(this,
                                                                 menu_selector(MyRatingStar::callback),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_empty_big.png"), NULL),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_full_big.png"), NULL),
                                                                 NULL);
    star2->setPosition(ccp(star1->getPositionX() + star1->getContentSize().width, star1->getPositionY()));
    
    star3 = CCMenuItemToggle::createWithTarget(this,
                                                                 menu_selector(MyRatingStar::callback),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_empty_big.png"), NULL),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_full_big.png"), NULL),
                                                                 NULL);
    star3->setPosition(ccp(star2->getPositionX() + star2->getContentSize().width, star2->getPositionY()));
    
    star4 = CCMenuItemToggle::createWithTarget(this,
                                                                 menu_selector(MyRatingStar::callback),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_empty_big.png"), NULL),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_full_big.png"), NULL),
                                                                 NULL);
    star4->setPosition(ccp(star3->getPositionX() + star3->getContentSize().width, star3->getPositionY()));
    
    star5 = CCMenuItemToggle::createWithTarget(this,
                                                                 menu_selector(MyRatingStar::callback),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_empty_big.png"), NULL),
                                                                 CCMenuItemImage::create(GET_PATH_FILE("star_full_big.png"), NULL),
                                                                 NULL);
    star5->setPosition(ccp(star4->getPositionX() + star4->getContentSize().width, star4->getPositionY()));
    
    
    CCSize size = CCSizeMake(star1->getContentSize().width * 5, star1->getContentSize().height);
    this->addChild(star1, 10);
    this->addChild(star2, 10);
    this->addChild(star3, 10);
    this->addChild(star4, 10);
    this->addChild(star5, 10);
    
    // Add the slider
    CCControlSlider *slider = CCControlSlider::create(GET_PATH_FILE("sliderTrack.png"),
                                                      GET_PATH_FILE("sliderProgress.png") ,
                                                      GET_PATH_FILE("sliderThumb.png"));
    
    slider->setTouchPriority(kCCMenuHandlerPriority);
    slider->setMinimumValue(0.0f); // Sets the min value of range
    slider->setMaximumValue(5.0f); // Sets the max value of range
    slider->setPosition(CCPoint(size.width/2.0f - 20.0f, 0.0f));
    slider->setTag(1);
    slider->addTargetWithActionForControlEvents(this,
                                                cccontrol_selector(MyRatingStar::valueChanged),
                                                CCControlEventValueChanged);
    this->addChild(slider);
    
    return true;
}

void MyRatingStar::valueChanged(CCControlSlider *sender, CCControlEvent controlEvent){
    star1->setSelectedIndex(0);
    star2->setSelectedIndex(0);
    star3->setSelectedIndex(0);
    star4->setSelectedIndex(0);
    star5->setSelectedIndex(0);
    
    float value = sender->getValue();
    if (value > 4.0f) {
        star1->setSelectedIndex(1);
        star2->setSelectedIndex(1);
        star3->setSelectedIndex(1);
        star4->setSelectedIndex(1);
        star5->setSelectedIndex(1);
    } else if (value > 3.0f){
        star1->setSelectedIndex(1);
        star2->setSelectedIndex(1);
        star3->setSelectedIndex(1);
        star4->setSelectedIndex(1);
    } else if (value > 2.0f){
        star1->setSelectedIndex(1);
        star2->setSelectedIndex(1);
        star3->setSelectedIndex(1);
    } else if (value > 1.0f){
        star1->setSelectedIndex(1);
        star2->setSelectedIndex(1);
    } else if (value >= 0.0f){
        star1->setSelectedIndex(1);
    }
}

void MyRatingStar::callback(){
    
}










