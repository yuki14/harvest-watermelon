#ifndef RESULT_SCENE_H_
#define RESULT_SCENE_H_

#include <iostream>
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "StartScene.h"
#include "Const.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;
class Result : public Layer
{
public:
    static Scene*createScene();
    
    virtual bool init();
    CREATE_FUNC(Result);
    void pushResult(Ref* pSender);
    static int getScore(int score);
    void setScore();
    void pushTitle(Ref* pSender);


};
#endif /* RESULT_SCENE_H_ */
