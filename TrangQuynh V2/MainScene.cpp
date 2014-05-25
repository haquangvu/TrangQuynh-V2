//
//  MainScene.cpp
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/24/14.
//
//

#include "MainScene.h"
#include "Constants.h"
#include "CCScrollLayer.h"
#include "AppSceneController.h"

MainScene::MainScene(){
    
}

MainScene::~MainScene(){
    
}

bool MainScene::init(){
    CC_RETURNBOOL_IF(!CCLayer::init());
    
    CCSprite *bg = CCSprite::create("MainPage/main_bk-iPad.png");
    bg->setPosition(CENTER);
    this->addChild(bg);
    
    CCMenuItemImage *btnSetting = CCMenuItemImage::create("MainPage/settings_nonselected.png",
                                                          "MainPage/settings_nonselected.png",
                                                          this,
                                                          menu_selector(MainScene::menuPressed));
    btnSetting->setTag(10);
    btnSetting->setPosition(ccp(btnSetting->getContentSize().width/2.0f,
                                btnSetting->getContentSize().height/2.0f));
    
    CCMenuItemImage *btnAbout = CCMenuItemImage::create("MainPage/aboutus_nonselected.png",
                                                          "MainPage/aboutus_nonselected.png",
                                                          this,
                                                          menu_selector(MainScene::menuPressed));
    btnAbout->setPosition(ccp(SCREEN.width - btnAbout->getContentSize().width/2.0f,
                                btnAbout->getContentSize().height/2.0f));
    btnAbout->setTag(11);
    
    CCMenu *menu = CCMenu::create(btnSetting, btnAbout, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    //create layer
    
    int pagesCount = 2;
    CCArray *arrayLayerScroll = CCArray::create();
    for (int i=0 ; i<pagesCount ; i++) {
        const char* path = CCString::createWithFormat("MainPage/book%d.png", i)->getCString();
        CCMenuItemImage *page = CCMenuItemImage::create(path,
                                                        path,
                                                        this,
                                                        menu_selector(MainScene::menuPressed));
        page->setPosition(ccp(SCREEN.width/2.0f, SCREEN.height*2.0f/3.0f));
        page->setTag(100 + i);
        
        CCMenu *menu = CCMenu::create(page, NULL);
        menu->setPosition(CCPointZero);
        
        CCLayer *layer = new CCLayer();
        layer->init();
        layer->addChild(menu);
        layer->setContentSize(CCSizeMake(SCREEN.width, SCREEN.height));
        layer->setPosition(CCPointZero);
        arrayLayerScroll->addObject(layer);
        layer->release();
    }
    
    CCScrollLayer *scroller = CCScrollLayer::nodeWithLayers(arrayLayerScroll, 0);
    scroller->setPosition(CCPointZero);
    this->addChild(scroller);
    
    return true;
}

void MainScene::menuPressed(CCObject *pSender){
    CCMenuItemImage *pMenuItem = dynamic_cast<CCMenuItemImage*>(pSender);
    if (pMenuItem) {
        switch (pMenuItem->getTag()) {
            case 10:
            {
                AppSceneController::sharedInstant()->changeToSettingScene();
                break;
            }
                
            case 11:
            {
                AppSceneController::sharedInstant()->changeToAboutScene();
                break;
            }
                
            case 100:
            {
                AppSceneController::sharedInstant()->changeToReadingScene();
                break;
            }
                
            case 101:
            {
                
                break;
            }
                
            default:
                break;
        }
    }
    
    
}