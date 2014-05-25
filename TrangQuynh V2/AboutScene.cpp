//
//  AboutScene.cpp
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/25/14.
//
//

#include "AboutScene.h"
#include "Constants.h"
#include "AppSceneController.h"

AboutScene::AboutScene(){
    
}

AboutScene::~AboutScene(){
    
}

bool AboutScene::init(){
    CC_RETURNBOOL_IF(!CCLayer::init());
    ADDWHITELAYER;
    
    CCMenuItemImage *btnBack = CCMenuItemImage::create("Setting/button_back_drawing.png",
                                                       "Setting/button_back_drawing_touch.png",
                                                       this,
                                                       menu_selector(AboutScene::menuPressed));
    btnBack->setPosition(ccp(btnBack->getContentSize().width/2.0f,
                             btnBack->getContentSize().height/2.0f));
    btnBack->setTag(10);
    
    CCMenu *menu = CCMenu::create(btnBack, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    return true;
}

void AboutScene::menuPressed(cocos2d::CCObject *pSender){
    CCMenuItemImage *item = dynamic_cast<CCMenuItemImage*>(pSender);
    if (item) {
        switch (item->getTag()) {
            case 10:
            {
                AppSceneController::sharedInstant()->changeToMainScene();
                break;
            }
                
            default:
                break;
        }
        
    }
}