#pragma once
#include <memory>
#include <graphics.h>
#include "Animation.h"
#include "Player.h"
#include "Bullet.h"

class Enemy
{
public:
    Enemy();
    ~Enemy() = default;

    bool CheckBulletCollision(const Bullet& bullet) const;
    bool CheckPlayerCollision(const Player& player);
    void Move(const Player& player);
    void Draw(int delta);
    void Hurt();
    bool CheckAlive() const;
    const POINT& GetPos() const;

private:
    bool Alive = true;
    const int SPEED = 2;
    const int ENEMY_WIDTH = 80;
    const int ENEMY_HEIGHT = 80;
    const int SHADOW_WIDTH = 48;

    IMAGE img_shadow;
    std::unique_ptr<Animation> anim_left;
    std::unique_ptr<Animation> anim_right;
    POINT enemy_position = { 0,0 };
    bool facing_left = false;
};
