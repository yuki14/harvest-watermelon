#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Soil.h"
#include "WaterMelon.h"
#include "Basket.h"
#include "ResultScene.h"
#include "Const.h"
#include "WizenedWaterMelon.h"
#include "Otsukisama.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    //Touchイベントの開始地点
    cocos2d::Point touchPoint;
    bool onContactBegin(PhysicsContact&contact);
    bool contactChecker(PhysicsContact &contact, ObjectType objectType1, ObjectType objectType2);
    //Touchイベント用
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    //スプライトを格納する配列
    Vector <Soil*> soils;
    Basket* basket;
    WaterMelon* wm;
    WizenedWaterMelon* wwm;
    Otsukisama* otsukisama;

    void growWM(float delta);
    void scoreSave();
    void scoreAdd();
    void makeBasket();
    void gameTimer(float time);
    int score;
    void moveResult();
    void randomGarbage(float dt);
private:
    //スプライトを表示する座標を設定
    float soilPositionsX[9];
    float soilPositionsY[9];
    int gameTime;
    int totalScore;
    String* scoreboard1;
    std::stringstream scoreBoard;
};

#endif // __HELLOWORLD_SCENE_H__
