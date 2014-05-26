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
    
    CCMenuItemImage *btnBackPage = CCMenuItemImage::create("Button/back_scenes.png",
                                                           "Button/back_scenes.png",
                                                           this,
                                                           menu_selector(ReadingScene::menuPressed));
    btnBackPage->setPosition(ccp( btnBackPage->getContentSize().width/2.0f,
                                 btnBackPage->getContentSize().height/2.0f));
    btnBackPage->setTag(11);
    
    CCMenuItemImage *btnNextPage = CCMenuItemImage::create("Button/next_scenes.png",
                                                           "Button/next_scenes.png",
                                                           this,
                                                           menu_selector(ReadingScene::menuPressed));
    btnNextPage->setPosition(ccp(SCREEN.width - btnNextPage->getContentSize().width/2.0f,
                                 btnNextPage->getContentSize().height/2.0f));
    btnNextPage->setTag(12);
    
    
    CCMenu *menu = CCMenu::create(btnBack,btnBackPage,btnNextPage, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 10);
    
    //    currentPage = new CCSprite();
    previousPage = new CCSprite();
    nextPage = new CCSprite();
    
    this->loadContent(pageIndex);
    
    return true;
}

void ReadingScene::loadContent(int page){
    
    
    if (pageIndex == 1) {
        CCString *path = CCString::createWithFormat("Content/a%d-iPad.jpg", page);
        currentPage = CCSprite::create(path->getCString());
        currentPage->setPosition(CENTER);
        this->addChild(currentPage);
    } else {
        previousPage = CCSprite::createWithTexture(currentPage->getTexture());
        previousPage->setPosition(CENTER);
        this->addChild(previousPage, 10);
        
        //memory
        currentPage->removeFromParentAndCleanup(true);
        CCTextureCache::sharedTextureCache()->removeUnusedTextures();
        
        //load new page
        CCString *path = CCString::createWithFormat("Content/a%d-iPad.jpg", pageIndex);
        currentPage = CCSprite::create(path->getCString());
        currentPage->setPosition(CENTER);
        this->addChild(currentPage, 9);
        
        previousPage->runAction(CCSequence::create(CCFadeOut::create(0.5f),
                                                  CCCallFunc::create(this, callfunc_selector(ReadingScene::removePreviousPage))
                                                  ));
        
    }
    
}

void ReadingScene::removePreviousPage(){
    previousPage->removeFromParentAndCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
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
                
            case 11:
            {
                AppSceneController::sharedInstant()->changeToMainScene();
                break;
            }
                
                
            case 12:
            {
                pageIndex += 1;
                this->loadContent(pageIndex);
                break;
            }
                
                
            default:
                break;
        }
        
    }
}