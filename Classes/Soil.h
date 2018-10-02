#ifndef SOIL_H_
#define SOIL_H_

#include "cocos2d.h"
USING_NS_CC;

class Soil:public Sprite
{
public:
	static Soil* create(const std::string& filename);
};

#endif /* SOIL_H_ */
