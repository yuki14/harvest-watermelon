#ifndef CONST_H_
#define CONST_H_

enum ObjectType
{
    kOT_Basket,
    kOT_Wm,
    kOT_Wwm,
    kOT_Otsukisama
};

enum Category
{
    cat_basket      = 0x01,////00000001
    cat_wm          = 0x02,////00000010
    cat_wwm         = 0x04,
    cat_otsukisama	= 0x08
};

enum Collision
{
    col_basket = cat_wm + cat_wwm + cat_otsukisama,
    col_wm = cat_basket,
    col_wwm = cat_basket,
    col_otsukisama = cat_basket
};

enum Contact
{
    con_basket = cat_wm + cat_wwm + cat_otsukisama,
    con_wm = cat_basket,
    con_wwm = cat_basket,
    con_otsukisama = cat_basket
};

enum kTag	//使ってない
{
    kTagBasket,
    kTagWm,
    kTagWmm,
    kTagOtsukisama
};

enum Score
{
    kTagScoreLabel=100,
    kTagHighScoreLabel=200,
};

enum Time{
	kTagTimerLabel
};

#define WINSIZE Director::getInstance()->getWinSize()
#define DESCRIPTION "Description.png"
#define START "Start.jpg"
#define RETRY "Retry.png"
#define TITLE "Title.png"
#define WATER_MELON "WaterMelon.png"
#define WIZENED_WATER_MELON "WizenedWaterMelon.png"
#define OTSUKISAMA "Otsukisama.png"
#define BASKET "Basket.png"
#define SOIL "Soil.png"
#define BACKGROUND "Background.png"

#endif /* CONST_H_ */
