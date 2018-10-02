#ifndef WATERMELON_H_
#define WATERMELON_H_

#include "cocos2d.h"
#include "Const.h"
#include "BaseWaterMelon.h"
USING_NS_CC;

class WaterMelon:public BaseWaterMelon
{
public:
	static WaterMelon* create(const std::string& filename);
	void setUp(WaterMelon* wm);
};
#endif /* WATERMELON_H_ */
