#include "CubeShape.h"

CubeShape::CubeShape(void) {};

CubeShape::~CubeShape(void) {};

void CubeShape::Show(HDC hdc)
{
    int x1, y1, x2, y2;
    int x1_proect, y1_proect, x2_proect, y2_proect;

    x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;
    x1_proect = x1 + (x2 - x1) / 3;
    y1_proect = y1 - (y2 - y1) / 3;
    x2_proect = x2 + (x2 - x1) / 3;
    y2_proect = y2 - (y2 - y1) / 3;

    RectShape::Show(hdc);

    RectShape::SetAll(x1_proect, y1_proect, x2_proect, y2_proect);
    RectShape::Show(hdc);

    LineShape::SetAll((x1 * 2) - x2, (y1 * 2) - y2, (x1_proect * 2) - x2_proect, (y1_proect * 2) - y2_proect);
    LineShape::Show(hdc);

    LineShape::SetAll((x1 * 2) - x2, y2, (x1_proect * 2) - x2_proect, y2_proect);
    LineShape::Show(hdc);

    LineShape::SetAll(x2, y2, x2_proect, y2_proect);
    LineShape::Show(hdc);

    LineShape::SetAll(x2, (y1 * 2) - y2, x2_proect, (y1_proect * 2) - y2_proect);
    LineShape::Show(hdc);

    xs1 = x1;
    ys1 = y1;
    xs2 = x2;
    ys2 = y2;
}

void CubeShape::PaintRubberMark(HWND hWnd)
{
    int x1, y1, x2, y2;
    int x1_proect, y1_proect, x2_proect, y2_proect;

    x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;
    x1_proect = x1 + (x2 - x1) / 3;
    y1_proect = y1 - (y2 - y1) / 3;
    x2_proect = x2 + (x2 - x1) / 3;
    y2_proect = y2 - (y2 - y1) / 3;

    RectShape::PaintRubberMark(hWnd);

    RectShape::SetAll(x1_proect, y1_proect, x2_proect, y2_proect);
    RectShape::PaintRubberMark(hWnd);

    LineShape::SetAll((x1 * 2) - x2, (y1 * 2) - y2, (x1_proect * 2) - x2_proect, (y1_proect * 2) - y2_proect);
    LineShape::PaintRubberMark(hWnd);

    LineShape::SetAll((x1 * 2) - x2, y2, (x1_proect * 2) - x2_proect, y2_proect);
    LineShape::PaintRubberMark(hWnd);

    LineShape::SetAll(x2, y2, x2_proect, y2_proect);
    LineShape::PaintRubberMark(hWnd);

    LineShape::SetAll(x2, (y1 * 2) - y2, x2_proect, (y1_proect * 2) - y2_proect);
    LineShape::PaintRubberMark(hWnd);

    xs1 = x1;
    ys1 = y1;
    xs2 = x2;
    ys2 = y2;
}

LPCWSTR CubeShape::GetName()
{
    return L"Cube";
}

Shape* CubeShape::CreateShape()
{
    return new CubeShape;
}