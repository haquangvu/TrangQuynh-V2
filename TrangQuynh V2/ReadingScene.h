//
//  ReadingScene.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/25/14.
//
//

#ifndef __TrangQuynh_V2__ReadingScene__
#define __TrangQuynh_V2__ReadingScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class ReadingScene: public CCLayer {
    
public:
    ReadingScene();
    ~ReadingScene();
    virtual bool init();
    
    CREATE_FUNC(ReadingScene);
    void menuPressed(CCObject *pSender);
    void loadContent(int page);
    
    int pageIndex;
    
    CCSprite *previousPage;
    CCSprite *currentPage;
};
#endif /* defined(__TrangQuynh_V2__ReadingScene__) */
