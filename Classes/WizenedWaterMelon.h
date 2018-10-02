#ifndef WIZENEDWATERMELON_H_
#define WIZENEDWATERMELON_H_

#include "cocos2d.h"
#include "Const.h"
#include "GameObject.h"
#include "BaseWaterMelon.h"

USING_NS_CC;

class WizenedWaterMelon:public BaseWaterMelon
{
public:
	static WizenedWaterMelon* create(const std::string& filename);
	void setUp(WizenedWaterMelon* wwm);
};

#endif /* WIZENEDWATERMELON_H_ */
