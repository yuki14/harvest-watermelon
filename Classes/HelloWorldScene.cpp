#include "HelloWorldScene.h"
USING_NS_CC;
//srand
//srand((unsigned)time(NULL)); //メイン関数の一回だけ
//(int)((double)rand()/RAND_MAX*n)


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    //重力を設定
    PhysicsWorld* world = scene->getPhysicsWorld();
    Vect gravity;
    gravity.setPoint(0, -1);
    world->setGravity(gravity);
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


    // return the scene
    return scene;
}

//タップ開始時にコールされる
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    Basket* basket = (Basket*)this->getChildByTag(2);
    if (basket->isTapped(touch->getLocation())) {
        log("tapped !!");
    }
    return true;
}


//タップ開始後、移動するとコールされる
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    basket = (Basket*)this->getChildByTag(2);
    if (basket->isTapped(touch->getLocation())) {
        basket->setPosition(touch->getLocation());
    }
}


//タップが終了するとコールされる
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    basket = (Basket*)this->getChildByTag(2);
    if (basket->isTapped(touch->getLocation())) {
        Point point = touch->getLocation();
        basket->setPositionY(point.y - 10);
    }
}

void HelloWorld::growWM(float delta)
{
		//srand
	srand((unsigned)time(NULL)); //メイン関数の一回だけ
//	(int)(((double)rand() / ((double)RAND_MAX + 1)) * 9);
//	(int)((double)rand()/RAND_MAX*n);
	int i = (int)(((double)rand() / ((double)RAND_MAX + 1)) * 9);
	int j = (int)(((double)rand() / ((double)RAND_MAX + 1)) * 9);
	int type = (int)(((double)rand() / ((double)RAND_MAX + 1)) * 6);

	switch(type){
		case 0:
	    case 1:
	     wm = WaterMelon::create(WATER_MELON);
	     wm->setPosition(Point(soilPositionsX[i], soilPositionsY[j]));
	     this->addChild(wm,1,1);
	     wm->runAction(Sequence::create(Spawn::create(MoveBy::create(0.5f, Vec2(0,100)),
	        													FadeOut::create(0.5f),
	               													NULL),
	               									  CallFuncN::create([&](Node *node)
	               										{
	               											node->removeFromParent();
	               										}),
	               									  NULL));
	    break;
	    case 2:
	    case 3:
	    case 4:
	     wwm = WizenedWaterMelon::create(WIZENED_WATER_MELON);
	     wwm->setPosition(Point(soilPositionsX[i], soilPositionsY[j]));
	     this->addChild(wwm,1,3);
	     wwm->runAction(Sequence::create(Spawn::create(MoveBy::create(0.5f, Vec2(0,100)),
	        													FadeOut::create(0.5f),
	               													NULL),
	             									  CallFuncN::create([&](Node *node)
	              										{
	              											node->removeFromParent();
	              										}),
	             									  NULL));
	    break;
	    case 5:
	     otsukisama = Otsukisama::create(OTSUKISAMA);
	     otsukisama->setPosition(Point(soilPositionsX[i], soilPositionsY[j]));
	     this->addChild(otsukisama,1,4);
	     otsukisama->runAction(Sequence::create(Spawn::create(MoveBy::create(0.5f, Vec2(0,100)),
	        													FadeOut::create(0.5f),
	               													NULL),
	                									  CallFuncN::create([&](Node *node)
	                										{
	                											node->removeFromParent();
	                										}),
	                									  NULL));
	    }
}

bool HelloWorld::onContactBegin(PhysicsContact &contact){
	log("あたり !!");
    GameObject* nodeA = (GameObject*)contact.getShapeA()->getBody()->getNode();
    GameObject* nodeB = (GameObject*)contact.getShapeB()->getBody()->getNode();

    //safetyCode
    if(nodeA==nullptr || nodeB==nullptr){
        return true;
    }

    int tagNodeA = nodeA->getTag();
    auto catA=nodeA->getPhysicsBody()->getCategoryBitmask();
    auto catB=nodeB->getPhysicsBody()->getCategoryBitmask();

    if (catA|catB==cat_basket|cat_wm)
    {
        score+=10;
        scoreAdd();
    	log("あたり !!");
        this->removeChild(tagNodeA==1 ? nodeA:nodeB);
    }else if(catA|catB==cat_basket|cat_wwm)
    {
        score-=50;
        scoreAdd();
    	log("あたり !!");
        this->removeChild(tagNodeA==3 ? nodeA:nodeB);
    }
    else if(catA|catB==cat_basket|cat_otsukisama)
    {
        score+=50;
        scoreAdd();
    	log("あたり !!");
        this->removeChild(tagNodeA==4 ? nodeA:nodeB);
    }
    return true;
}

//スコアの加算
void HelloWorld::scoreAdd(){
    //スコア表示
    totalScore = score;
    scoreboard1 = String::createWithFormat("%d point", totalScore);
    Label* scoreLabel = (Label*)this->getChildByTag(kTagScoreLabel);
    scoreLabel->setString(scoreboard1->getCString());
}

//スコアの保存
void HelloWorld::scoreSave(){
    //スコアを記憶
    UserDefault*user = UserDefault::sharedUserDefault();
    user->setIntegerForKey("IntKey", score);
    user->flush();
}

void HelloWorld::gameTimer(float time)
{
    gameTime -= 1;
    String* timeboard = String::createWithFormat("%d 秒", gameTime);
    Label* timeLabel = (Label*)this->getChildByTag(kTagTimerLabel);
    timeLabel->setString(timeboard->getCString());

    if(gameTime == 0) {
        this->pauseSchedulerAndActions();
//        this->resumeSchedulerAndActions();
        scoreSave();
        moveResult();
    }
}

void HelloWorld::moveResult()
{
    Scene*pScene = Result::createScene();
    TransitionFade*transition = TransitionFade::create(0.5f, pScene);//フィードの時間、移動先のシーン、フィードの色（オプション）
    Director::getInstance()->replaceScene(transition);
}

void HelloWorld::randomGarbage(float dt)
{
	//srand((unsigned)time(NULL)); //メイン関数の一回だけ
	//(int)((double)rand()/RAND_MAX*n)
	int x = (int)(((double)rand() / ((double)RAND_MAX + 1)) * 9);
	int y = (int)(((double)rand() / ((double)RAND_MAX + 1)) * 9);
	wwm = WizenedWaterMelon::create(WIZENED_WATER_MELON);
	wwm->setPosition(Point(WINSIZE.width/x, WINSIZE.height/y));
	this->addChild(wwm,1,3);
	wwm->runAction(Sequence::create(FadeOut::create(2.0f),
	          									  CallFuncN::create([&](Node *node)
	         										{
	         											node->removeFromParent();
	         										}),
	        									  NULL));

}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    //背景を設置
    Sprite* background = Sprite::create(BACKGROUND);
    background->setPosition(Point(WINSIZE.width/2, WINSIZE.height/2));
    this->addChild(background, 0); //第2引数は表示順

    //時間表示
    gameTime=60;
    Label* timeLabel = Label::create("60秒","Marker Felt.ttf", 32.0f);
    timeLabel->setPosition(Point(WINSIZE.width/5, WINSIZE.height/10*9));
    timeLabel->setTag(kTagTimerLabel);
    this->addChild(timeLabel,2);

    //スコアを表示
    Label* scoreLabel = Label::create("0point","Marker Felt.ttf", 32.0f);
    scoreLabel->setPosition(Point(WINSIZE.width/5*4, WINSIZE.height/10*9));
    scoreLabel->setTag(kTagScoreLabel);
    this->addChild(scoreLabel,2);

    //タッチの有効化
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    auto eventDispatcher2 = Director::getInstance()->getEventDispatcher();
    auto p_listener = EventListenerPhysicsContact::create();
    p_listener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    eventDispatcher2-> addEventListenerWithSceneGraphPriority(p_listener, this);

    soilPositionsX[0] = WINSIZE.width/8*7;
    soilPositionsX[1] = WINSIZE.width/2;
    soilPositionsX[2] = WINSIZE.width/8;
    soilPositionsX[3] = WINSIZE.width/8*7;
    soilPositionsX[4] = WINSIZE.width/2;
    soilPositionsX[5] = WINSIZE.width/8;
    soilPositionsX[6] = WINSIZE.width/8*7;
    soilPositionsX[7] = WINSIZE.width/2;
    soilPositionsX[8] = WINSIZE.width/8;

    soilPositionsY[0] = WINSIZE.height/7*5;
    soilPositionsY[1] = WINSIZE.height/7*5;
    soilPositionsY[2] = WINSIZE.height/7*5;
    soilPositionsY[3] = WINSIZE.height/2;
    soilPositionsY[4] = WINSIZE.height/2;
    soilPositionsY[5] = WINSIZE.height/2;
    soilPositionsY[6] = WINSIZE.height/7*2;
    soilPositionsY[7] = WINSIZE.height/7*2;
    soilPositionsY[8] = WINSIZE.height/7*2;


    //スプライトを９つ生成
    for(int i=0; i<9; i++){
    	Soil* soil = Soil::create(SOIL);
    	soil->autorelease();
    	soil->setPosition(Point(soilPositionsX[i], soilPositionsY[i]));

    	this->addChild(soil);
    	soils.pushBack(soil);
    }

    this->schedule(schedule_selector(HelloWorld::growWM),0.3f);
    this->schedule(schedule_selector(HelloWorld::randomGarbage),5.0f);
    basket = Basket::create(BASKET);


    basket->setPosition(Point(WINSIZE.width/6, WINSIZE.height/8));

    // add the sprite as a child to this layer
    this->addChild(basket,1,2);
    this->schedule(schedule_selector(HelloWorld::gameTimer), 1.0f);
    return true;
}
