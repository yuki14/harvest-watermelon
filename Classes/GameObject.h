#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <iostream>
#include "cocos2d.h"
#include "Const.h"

USING_NS_CC;

class GameObject : public Sprite
{
public:
    ObjectType objectType;
};


#endif /* GAMEOBJECT_H_ */
