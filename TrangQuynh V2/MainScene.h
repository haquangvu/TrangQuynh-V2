//
//  MainScene.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/24/14.
//
//

#ifndef __TrangQuynh_V2__MainScene__
#define __TrangQuynh_V2__MainScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class MainScene: public CCLayer {
    
public:
    MainScene();
    ~MainScene();
    virtual bool init();
    
    CREATE_FUNC(MainScene);
    void menuPressed(CCObject *pSender);
};



#endif /* defined(__TrangQuynh_V2__MainScene__) */
