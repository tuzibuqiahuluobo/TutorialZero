#pragma once
#include <graphics.h>
#include <string>


class Button
{
public:
    Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
    virtual ~Button() = default;

    void ProcessEvent(const ExMessage& msg);
    void Draw() const;

protected:
    virtual void Onclick() = 0;

private:
    enum class Status
    {
        Idle = 0,
        Hovered,
        Pushed
    };

    RECT region;
    IMAGE img_idle;
    IMAGE img_hovered;
    IMAGE img_pushed;
    Status status = Status::Idle;

    bool CheckCursorHit(int x, int y) const;
};
