#include "BaseWaterMelon.h"

PhysicsBody* BaseWaterMelon::createPhysicsBody(){
	PhysicsBody*bwmPb=PhysicsBody::createCircle(this->getContentSize().width/2);
	bwmPb->setMass(1.0f);
	bwmPb->setVelocityLimit(100.0);
	bwmPb->setDynamic(true);
	bwmPb->setGravityEnable(false);
	bwmPb->setEnable(true);
	return bwmPb;
}
