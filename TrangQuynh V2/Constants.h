//
//  Constants.h
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/24/14.
//
//

#ifndef __TrangQuynh_V2__Constants__
#define __TrangQuynh_V2__Constants__

#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <iterator>
#include "cocos2d.h"

USING_NS_CC;

//vu ha
#define SCREEN CCDirector::sharedDirector()->getWinSize()
#define FRAMESIZE CCEGLView::sharedOpenGLView()->getFrameSize();
#define CENTER ccp(SCREEN.width/2, SCREEN.height/2)

#define GET_PATH_FILE(_file) (CCFileUtils::sharedFileUtils()->fullPathForFilename(_file).c_str())

#define CC_RETURN_IF(cond)            if(cond) return
#define CC_RETURNBOOL_IF(cond)            if(cond) return false

#define ADDTRANSPARENTLAYER this->addChild(CCLayerColor::create(ccc4(0, 0, 0, 75), SCREEN.width, SCREEN.height))
#define ADDWHITELAYER this->addChild(CCLayerColor::create(ccc4(255, 255, 255, 255), SCREEN.width, SCREEN.height))

#endif /* defined(__TrangQuynh_V2__Constants__) */
