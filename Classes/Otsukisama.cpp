#include "Otsukisama.h"

Otsukisama* Otsukisama::create(const std::string& filename)
{
    Otsukisama *otsukisama = new (std::nothrow) Otsukisama();
    if (otsukisama && otsukisama->initWithFile(filename))
    {
    	otsukisama->setUp(otsukisama);
        return otsukisama;
    }
    CC_SAFE_DELETE(otsukisama);
    return nullptr;
}

void Otsukisama::setUp(Otsukisama* otsukisama){
	PhysicsBody*otsukisamaPb=BaseWaterMelon::createPhysicsBody();
//    otsukisamaPb->setMass(1.0f);
//    otsukisamaPb->setVelocityLimit(100.0);
//    otsukisamaPb->setDynamic(true);
//    otsukisamaPb->setGravityEnable(false);
//    otsukisamaPb->setEnable(true);


    otsukisamaPb->setCategoryBitmask(cat_otsukisama);
    otsukisamaPb->setContactTestBitmask(con_otsukisama);
    otsukisamaPb->setCollisionBitmask(col_otsukisama);

    otsukisama->setPhysicsBody(otsukisamaPb);
    otsukisama->autorelease();
}
