//
//  AboutScene.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/25/14.
//
//

#ifndef __TrangQuynh_V2__AboutScene__
#define __TrangQuynh_V2__AboutScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class AboutScene: public CCLayer {
    
public:
    AboutScene();
    ~AboutScene();
    virtual bool init();
    
    CREATE_FUNC(AboutScene);
    void menuPressed(CCObject *pSender);
};


#endif /* defined(__TrangQuynh_V2__AboutScene__) */
