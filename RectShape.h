#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
private:
    long xstart, ystart;
public:
    RectShape(void);
    virtual ~RectShape(void);
    void Show(HDC, BOOL, BOOL);
    LPCWSTR GetName();
    Shape* CreateShape();
};