#ifndef DESCRIPTIONSCENE_H_
#define DESCRIPTIONSCENE_H_

#include <iostream>
#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;
class Description : public Layer
{
public:
    static Scene*createScene();

    virtual bool init();
    CREATE_FUNC(Description);
    void pushStart(Ref* pSender);
};


#endif /* DESCRIPTION_SCENE_H_ */
