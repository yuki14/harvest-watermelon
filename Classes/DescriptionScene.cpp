#include "DescriptionScene.h"

Scene*Description::createScene(){
    auto scene = Scene::create();

    auto layer = Description::create();

    scene->addChild(layer);
    return scene;
}

bool Description::init(){

    if (!Layer::init())
    {
        return false;
    }

    //タイトルを設置
    auto lbl_title = LabelTTF::create("開始と見せかけて説明、画面を押すと本当に開始", "Marker Felt.ttf", 30);
    lbl_title->setPosition(Point(WINSIZE.width/2,
                                 WINSIZE.height
                                 -lbl_title->getContentSize().height));
    this->addChild(lbl_title,1);

    //スタートボタンを設置
    auto startButton = MenuItemImage::create(
                                             DESCRIPTION,  //通常状態の画像
                                             DESCRIPTION,  //押した状態の画像

                                             CC_CALLBACK_1(Description::pushStart, this)); //押した時のアクション

    startButton->setPosition(Point(WINSIZE.width/2, WINSIZE.height/2));
    //create menu, it's an autorelease object
    auto menu = Menu::create(startButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    return true;

}

void Description::pushStart(Ref*pSender)
{
    Scene*pScene = HelloWorld::createScene();
    TransitionFade*transition = TransitionFade::create(0.5f, pScene);
    Director::getInstance()->replaceScene(transition);
}
