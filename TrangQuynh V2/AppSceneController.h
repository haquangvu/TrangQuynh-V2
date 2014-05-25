//
//  AppSceneController.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/24/14.
//
//

#ifndef __TrangQuynh_V2__AppSceneController__
#define __TrangQuynh_V2__AppSceneController__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class AppSceneController: public CCObject {
    
public:
    AppSceneController();
    ~AppSceneController();
    virtual bool init();
    
    static AppSceneController *sharedInstant();
    static void freeSingleton();
    
    void changeToMainScene();
    void changeToSettingScene();
    void changeToAboutScene();
    void changeToReadingScene();
};

#endif /* defined(__TrangQuynh_V2__AppSceneController__) */
