#pragma once
#include <memory>
#include <graphics.h>
#include "Animation.h"



class Player
{
public:
    Player();
    ~Player() = default;

    void processEvent(const ExMessage& msg);
    void Move();
    void Draw(int delta);
    const POINT& GetPosition() const;

    const int PLAYER_SPEED = 5;
    const int PLAYER_WIDTH = 80;
    const int PLAYER_HEIGHT = 80;
    const int SHADOW_WIDTH = 32;

private:
    IMAGE img_shadow;
    std::unique_ptr<Animation> anim_left;
    std::unique_ptr<Animation> anim_right;
    POINT player_pos = { 500,500 };
    bool is_move_up = false;
    bool is_move_down = false;
    bool is_move_left = false;
    bool is_move_right = false;
};
