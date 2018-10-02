#ifndef BASKET_H_
#define BASKET_H_

#include "cocos2d.h"
#include "Const.h"
#include "GameObject.h"

USING_NS_CC;

class Basket : public GameObject
{
    public:
	   static Basket* create(const std::string& filename);
	   void setUp(Basket* basket);
	   Rect getRect();
	   bool isTapped(Point point);
};

#endif /* BASKET_H_ */
