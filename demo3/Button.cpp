#include "Button.h"

Button::Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
{
    region = rect;
    loadimage(&img_idle, path_img_idle);
    loadimage(&img_hovered, path_img_hovered);
    loadimage(&img_pushed, path_img_pushed);
}

void Button::ProcessEvent(const ExMessage& msg)
{
    switch (msg.message)
    {
    case WM_MOUSEMOVE:
        if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
            status = Status::Hovered;
        else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
            status = Status::Idle;
        break;
    case WM_LBUTTONDOWN:
        if (CheckCursorHit(msg.x, msg.y))
            status = Status::Pushed;
        break;
    case WM_LBUTTONUP:
        if (status == Status::Pushed)
            Onclick();
        break;
    default:
        break;
    }
}

void Button::Draw() const
{
    switch (status)
    {
    case Status::Idle:
        putimage(region.left, region.top, &img_idle);
        break;
    case Status::Hovered:
        putimage(region.left, region.top, &img_hovered);
        break;
    case Status::Pushed:
        putimage(region.left, region.top, &img_pushed);
        break;
    }
}

bool Button::CheckCursorHit(int x, int y) const
{
    return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
}