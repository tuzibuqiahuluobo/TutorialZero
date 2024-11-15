#include "Bullet.h"

void Bullet::Draw() const
{
    setlinecolor(RGB(255, 155, 50));
    setfillcolor(RGB(200, 75, 10));
    fillcircle(position.x, position.y, RADIUS);
}

const POINT& Bullet::Get_Bullet_Pos() const
{
    return position;
}
