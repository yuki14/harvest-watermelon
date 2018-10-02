#ifndef START_SCENE_H_
#define START_SCENE_H_

#include <iostream>
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "DescriptionScene.h"

USING_NS_CC;
class Start : public Layer
{
public:
    static Scene*createScene();
    
    virtual bool init();
    CREATE_FUNC(Start);
    void pushStart(Ref* pSender);
};

#endif /* START_SCENE_H_ */
