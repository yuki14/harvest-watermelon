#ifndef OTSUKISAMA_H_
#define OTSUKISAMA_H_

#include "cocos2d.h"
#include "Const.h"
#include "BaseWaterMelon.h"
USING_NS_CC;

class Otsukisama:public BaseWaterMelon
{
public:
	static Otsukisama* create(const std::string& filename);
	void setUp(Otsukisama* otsukisama);
};

#endif /* OTSUKISAMA_H_ */
