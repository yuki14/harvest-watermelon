#include "Basket.h"

Basket* Basket::create(const std::string& filename)
{
    Basket *basket = new (std::nothrow) Basket();
    if (basket && basket->initWithFile(filename))
    {

    	basket->setUp(basket);
        return basket;
    }
    CC_SAFE_DELETE(basket);
    return nullptr;
}
//タップされたかどうか
bool Basket::isTapped(Point point)
{
    Rect rect = this->getRect();
    bool tapped = rect.containsPoint(point);
    if (tapped) {
        log("ok");
    } else {
        log("ng");
    }
    return tapped;
}

//スプライトの座標点の範囲を取得
Rect Basket::getRect()
{
	//スプライトの座標（画像の真ん中の座標のこと）
    Point point = this->getPosition();
    //スプライトの幅と高さ
    int w = this->getContentSize().width * this->getScaleX();
    int h = this->getContentSize().height * this->getScaleY();
    //スプライトの範囲を返す
    return Rect(point.x - (w / 2), point.y - (h / 2), w, h);
}

void Basket::setUp(Basket* basket){
	PhysicsBody*basketPb=PhysicsBody::createCircle(this->getContentSize().width/3);
    basketPb->setMass(1.0f);
    basketPb->setVelocityLimit(100.0);
    basketPb->setDynamic(true);
    basketPb->setGravityEnable(false);
    basketPb->setEnable(true);

    basketPb->setCategoryBitmask(cat_basket);
    basketPb->setContactTestBitmask(con_basket);
    basketPb->setCollisionBitmask(col_basket);

    basket->setPhysicsBody(basketPb);
    basket->setScale(3);
    basket->autorelease();
}

