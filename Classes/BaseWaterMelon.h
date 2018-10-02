#ifndef BASEWATERMELON_H_
#define BASEWATERMELON_H_

#include "cocos2d.h"
#include "GameObject.h"

USING_NS_CC;

class BaseWaterMelon:public GameObject {
public:
	virtual PhysicsBody* createPhysicsBody();
};

#endif /* BASEWATERMELON_H_ */
