#pragma once
#include <graphics.h>

class Bullet
{
public:
    Bullet() = default;
    ~Bullet() = default;

    void Draw() const;
    const POINT& Get_Bullet_Pos() const;

    POINT position = { 0,0 };

private:
    const int RADIUS = 10;
};
