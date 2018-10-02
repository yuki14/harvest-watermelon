#include "Soil.h"


Soil* Soil::create(const std::string& filename)
{
    Soil *soil = new (std::nothrow) Soil();
    if (soil && soil->initWithFile(filename))
    {
        return soil;
    }
    CC_SAFE_DELETE(soil);
    return nullptr;
}
