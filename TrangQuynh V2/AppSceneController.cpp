//
//  AppSceneController.cpp
//  TrangQuynh V2
//
//  Created by Vu Ha on 5/24/14.
//
//

#include "AppSceneController.h"
#include "HelloWorldScene.h"
#include "MainScene.h"
#include "SettingScene.h"
#include "AboutScene.h"
#include "ReadingScene.h"

static AppSceneController *s_SharedInstant = NULL;


AppSceneController::AppSceneController(){

}

AppSceneController::~AppSceneController(){

}

void AppSceneController::freeSingleton(){
    CC_SAFE_RELEASE_NULL(s_SharedInstant);
}

AppSceneController* AppSceneController::sharedInstant(){
    if (NULL == s_SharedInstant) {
        s_SharedInstant = new AppSceneController();
        s_SharedInstant->init();
    }
    
    return s_SharedInstant;
}

bool AppSceneController::init(){
    return true;
}

void AppSceneController::changeToMainScene(){
    CCScene *scene = CCScene::create();
    MainScene *layer = MainScene::create();
    scene->addChild(layer);
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

void AppSceneController::changeToSettingScene(){
    CCScene *scene = CCScene::create();
    SettingScene *layer = SettingScene::create();
    scene->addChild(layer);
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

void AppSceneController::changeToAboutScene(){
    CCScene *scene = CCScene::create();
    AboutScene *layer = AboutScene::create();
    scene->addChild(layer);
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

void AppSceneController::changeToReadingScene(){
    CCScene *scene = CCScene::create();
    ReadingScene *layer = ReadingScene::create();
    scene->addChild(layer);
    
    CCDirector::sharedDirector()->replaceScene(scene);
}


