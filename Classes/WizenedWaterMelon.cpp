#include "WizenedWaterMelon.h"

WizenedWaterMelon* WizenedWaterMelon::create(const std::string& filename)
{
    WizenedWaterMelon *wizenedWaterMelon = new (std::nothrow) WizenedWaterMelon();
    if (wizenedWaterMelon && wizenedWaterMelon->initWithFile(filename))
    {
    	wizenedWaterMelon->setUp(wizenedWaterMelon);
        return wizenedWaterMelon;
    }
    CC_SAFE_DELETE(wizenedWaterMelon);
    return nullptr;
}

void WizenedWaterMelon::setUp(WizenedWaterMelon* wwm){
	PhysicsBody*wwmPb=BaseWaterMelon::createPhysicsBody();
//    wwmPb->setMass(1.0f);
//    wwmPb->setVelocityLimit(100.0);
//    wwmPb->setDynamic(true);
//    wwmPb->setGravityEnable(false);
//    wwmPb->setEnable(true);

    wwmPb->setCategoryBitmask(cat_wwm);
    wwmPb->setContactTestBitmask(con_wwm);
    wwmPb->setCollisionBitmask(col_wwm);

    wwm->setPhysicsBody(wwmPb);
    wwm->autorelease();
}

