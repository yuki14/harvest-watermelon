#include "ResultScene.h"
using namespace CocosDenshion;
Scene*Result::createScene(){
    auto scene = Scene::create();
    
    auto layer = Result::create();
    
    scene->addChild(layer);
    return scene;
}

bool Result::init(){
    
    if (!Layer::init())
    {
        return false;
    }
    
    //背景を設置
    Sprite* background = Sprite::create(BACKGROUND);
    background->setPosition(Point(WINSIZE.width/2, WINSIZE.height/2));
    this->addChild(background, 1); //第2引数は表示順
    
    
    //タイトルを設置
    auto lbl_title = LabelTTF::create("結果", "Marker Felt.ttf", 80);
    lbl_title->setPosition(Point(WINSIZE.width/2,
                                 WINSIZE.height/7*6));
    this->addChild(lbl_title,1);
    
    //リトライボタンを設置
    auto retryButton = MenuItemImage::create(
                                             RETRY,  //通常状態の画像
                                             RETRY,  //押した状態の画像
                                             CC_CALLBACK_1(Result::pushResult, this)); //押した時のアクション
    
    retryButton->setPosition(Point(WINSIZE.width/2, WINSIZE.height/4));
    retryButton->setScale(3.0f);
    //create menu, it's an autorelease object
    auto menu = Menu::create(retryButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    //タイトルボタンを設置
    auto titleButton = MenuItemImage::create(
                                             TITLE,  //通常状態の画像
                                             TITLE,  //押した状態の画像
                                             CC_CALLBACK_1(Result::pushTitle, this)); //押した時のアクション
    
    titleButton->setPosition(Point(WINSIZE.width/2, WINSIZE.height/5*2));
    titleButton->setScale(2.0f);
    //create menu, it's an autorelease object
    auto menu1 = Menu::create(titleButton, NULL);
    menu1->setPosition(Point::ZERO);
    this->addChild(menu1, 1);
    
    
    UserDefault*user = UserDefault::sharedUserDefault();
    
    int msFlag = user->getIntegerForKey("IntKeyms", 0);

        int score = user->getIntegerForKey("IntKey", 0);
        int firstScore = user->getIntegerForKey("IntKey1",0);
        int secondScore = user->getIntegerForKey("IntKey2",0);
        int thirdScore = user->getIntegerForKey("IntKey3",0);
        std::stringstream string;
        string << "スコア : " << score<<"点";
        auto scoreLabel = LabelTTF::create(string.str(),"Marker Felt.ttf", 40);
        scoreLabel->setPosition(Point(WINSIZE.width/4, WINSIZE.height/4*3));
        scoreLabel->setScale(1.0f);
        this -> addChild(scoreLabel,18);
    
    

        if(firstScore<score){
            user->setIntegerForKey("IntKey3", secondScore);
            user->flush();
            thirdScore=user->getIntegerForKey("IntKey3",0);
        
            user->setIntegerForKey("IntKey2", firstScore);
            user->flush();
            secondScore=user->getIntegerForKey("IntKey2",0);
        
            user->setIntegerForKey("IntKey1", score);
            user->flush();
            firstScore=user->getIntegerForKey("IntKey1",0);
        }
        else if(firstScore>=score && secondScore<score){
            user->setIntegerForKey("IntKey3", secondScore);
            user->flush();
            thirdScore=user->getIntegerForKey("IntKey3",0);
        
            user->setIntegerForKey("IntKey2", score);
            user->flush();
            secondScore=user->getIntegerForKey("IntKey2",0);
        }
        else if ((firstScore>=score && secondScore>=score) && thirdScore<score){
            user->setIntegerForKey("IntKey3", score);
            user->flush();
            thirdScore=user->getIntegerForKey("IntKey3",0);
        }

        //第一位
        std::stringstream string1;
        string1 << "第一位 : " << firstScore<<"点";
        auto scoreLabel1 = LabelTTF::create(string1.str(),"Marker Felt.ttf", 40);
        scoreLabel1->setPosition(Point(WINSIZE.width/4*3, WINSIZE.height/4*3));
        scoreLabel1->setScale(1.0f);
        this -> addChild(scoreLabel1,2);
    
        //第二位
        std::stringstream string2;
        string2 << "第二位 : " << secondScore<<"点";
        auto scoreLabel2 = LabelTTF::create(string2.str(),"Marker Felt.ttf", 40);
        scoreLabel2->setPosition(Point(WINSIZE.width/4*3, WINSIZE.height/3*2));
        scoreLabel2->setScale(1.0f);
        this -> addChild(scoreLabel2,2);
    
        //第三位
        std::stringstream string3;
        string3 << "第三位 : " << thirdScore<<"点";
        auto scoreLabel3 = LabelTTF::create(string3.str(),"Marker Felt.ttf", 40);
        scoreLabel3->setPosition(Point(WINSIZE.width/4*3, WINSIZE.height/5*3));
        scoreLabel3->setScale(1.0f);
        this -> addChild(scoreLabel3,2);

    return true;

}

void Result::pushResult(Ref*pSender)
{
    Scene*pScene = HelloWorld::createScene();
    TransitionFade*transition = TransitionFade::create(0.5f, pScene);
    Director::getInstance()->replaceScene(transition);
}

void Result::pushTitle(Ref*pSender)
{
    Scene*pScene = Start::createScene();
    TransitionFade*transition = TransitionFade::create(0.5f, pScene);
    Director::getInstance()->replaceScene(transition);
}

int Result::getScore(int score)
{
    return score;
}
