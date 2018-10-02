#include "StartScene.h"



Scene*Start::createScene(){
    auto scene = Scene::create();
    
    auto layer = Start::create();
    
    scene->addChild(layer);
    return scene;
}

bool Start::init(){
    
    if (!Layer::init())
    {
        return false;
    }
       
    //背景を設置
    Sprite* background = Sprite::create(BACKGROUND);
    background->setPosition(Point(WINSIZE.width/2, WINSIZE.height/2));
    this->addChild(background, 0); //第2引数は表示順

    //タイトルを設置
    auto lbl_title = LabelTTF::create("スイカ採り", "Marker Felt.ttf", 80);
    lbl_title->setPosition(Point(WINSIZE.width/2,
                                 WINSIZE.height/6*5
                                 -lbl_title->getContentSize().height));
    this->addChild(lbl_title,1);
    
    //スタートボタンを設置
    auto startButton = MenuItemImage::create(
                                             START,  //通常状態の画像
                                             START,  //押した状態の画像
                                             CC_CALLBACK_1(Start::pushStart, this)); //押した時のアクション
    
    startButton->setPosition(Point(WINSIZE.width/2, WINSIZE.height/2));
    startButton->setScale(4.0f);
    //create menu, it's an autorelease object
    auto menu = Menu::create(startButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    return true;
 
}

void Start::pushStart(Ref*pSender)
{
    Scene*pScene = Description::createScene();
    TransitionFade*transition = TransitionFade::create(0.5f, pScene);
    Director::getInstance()->replaceScene(transition);
}
