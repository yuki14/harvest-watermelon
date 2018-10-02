#include "WaterMelon.h"

WaterMelon* WaterMelon::create(const std::string& filename)
{
    WaterMelon *waterMelon = new (std::nothrow) WaterMelon();
    if (waterMelon && waterMelon->initWithFile(filename))
    {
    	waterMelon->setUp(waterMelon);
        return waterMelon;
    }
    CC_SAFE_DELETE(waterMelon);
    return nullptr;
}

//新しくメソッドを作って違うものだけ入れてオーバーライド
void WaterMelon::setUp(WaterMelon* wm){
	PhysicsBody*wmPb=BaseWaterMelon::createPhysicsBody();
//	wmPb->setMass(1.0f);
//	wmPb->setVelocityLimit(100.0);
//	wmPb->setDynamic(true);
//	wmPb->setGravityEnable(false);
//	wmPb->setEnable(true);

	wmPb->setCategoryBitmask(cat_wm);
    wmPb->setContactTestBitmask(con_wm);
    wmPb->setCollisionBitmask(col_wm);

    wm->setPhysicsBody(wmPb);
    wm->autorelease();
}

