//
//  ReadingScene.cpp
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/25/14.
//
//

#include "ReadingScene.h"
#include "Constants.h"
#include "AppSceneController.h"

ReadingScene::ReadingScene(){
    
}

ReadingScene::~ReadingScene(){
    
}


bool ReadingScene::init(){
    CC_RETURNBOOL_IF(!CCLayer::init());
    ADDWHITELAYER;
    
    pageIndex = 1;
    
    CCMenuItemImage *btnBack = CCMenuItemImage::create("Setting/button_back_drawing.png",
                                                       "Setting/button_back_drawing_touch.png",
                                                       this,
                                                       menu_selector(ReadingScene::menuPressed));
    btnBack->setPosition(ccp( btnBack->getContentSize().width/2.0f,
                             SCREEN.height - btnBack->getContentSize().height/2.0f));
    btnBack->setTag(10);
    
    CCMenu *menu = CCMenu::create(btnBack, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 10);
    
    currentPage = new CCSprite();
    previousPage = new CCSprite();
    
    this->loadContent(pageIndex);
    
    return true;
}

void ReadingScene::loadContent(int page){
    
    
    if (pageIndex == 1) {
        CCString *path = CCString::createWithFormat("Content/a%d-iPad.jpg", page);
        currentPage->initWithFile(path->getCString());
        currentPage->setPosition(CENTER);
        this->addChild(currentPage);
    }
    
}



void ReadingScene::menuPressed(cocos2d::CCObject *pSender){
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