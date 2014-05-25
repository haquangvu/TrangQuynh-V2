//
//  SettingScene.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/25/14.
//
//

#ifndef __TrangQuynh_V2__SettingScene__
#define __TrangQuynh_V2__SettingScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class SettingScene: public CCLayer {
    
public:
    SettingScene();
    ~SettingScene();
    virtual bool init();
    
    CREATE_FUNC(SettingScene);
    void menuPressed(CCObject *pSender);
};

#endif /* defined(__TrangQuynh_V2__SettingScene__) */
