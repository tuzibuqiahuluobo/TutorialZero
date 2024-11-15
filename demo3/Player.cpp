#include "Player.h"
#include <cmath>
#include <iostream>
#include "Utils.h"
#include "Globals.h"



Player::Player()
{
    loadimage(&img_shadow, _T("img/shadow_player.png"));
    anim_left = std::make_unique<Animation>(atlas_player_left, 45);
    anim_right = std::make_unique<Animation>(atlas_player_right, 45);
}

void Player::processEvent(const ExMessage& msg)
{
    if (msg.message == WM_KEYDOWN)
    {
        switch (msg.vkcode)
        {
        case VK_UP:
            is_move_up = true;
            break;
        case VK_DOWN:
            is_move_down = true;
            break;
        case VK_LEFT:
            is_move_left = true;
            break;
        case VK_RIGHT:
            is_move_right = true;
            break;
        }
    }
    else if (msg.message == WM_KEYUP)
    {
        switch (msg.vkcode)
        {
        case VK_UP:
            is_move_up = false;
            break;
        case VK_DOWN:
            is_move_down = false;
            break;
        case VK_LEFT:
            is_move_left = false;
            break;
        case VK_RIGHT:
            is_move_right = false;
            break;
        }
    }
}

void Player::Move()
{
    int dir_x = is_move_right - is_move_left;
    int dir_y = is_move_down - is_move_up;
    double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
    if (len_dir != 0)
    {
        double normalized_x = dir_x / len_dir;
        double normalized_y = dir_y / len_dir;
        player_pos.x += (int)(PLAYER_SPEED * normalized_x);
        player_pos.y += (int)(PLAYER_SPEED * normalized_y);
    }

    if (player_pos.x < 0) player_pos.x = 0;
    if (player_pos.y < 0) player_pos.y = 0;
    if (player_pos.x + PLAYER_WIDTH > WINDOW_WIDTH)
        player_pos.x = WINDOW_WIDTH - PLAYER_WIDTH;
    if (player_pos.y + PLAYER_HEIGHT > WINDOW_HEIGHT)
        player_pos.y = WINDOW_HEIGHT - PLAYER_HEIGHT;
}

void Player::Draw(int delta)
{
    if (anim_left && anim_right)
    {
        int pos_shadow_x = player_pos.x + (PLAYER_WIDTH / 2 - SHADOW_WIDTH / 2);
        int pos_shadow_y = player_pos.y + PLAYER_HEIGHT - 8;
        putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);

        static bool facing_left = false;
        int dir_x = is_move_right - is_move_left;
        if (dir_x < 0)
        {
            facing_left = true;
        }
        else if (dir_x > 0)
        {
            facing_left = false;
        }

        if (facing_left)
        {
            anim_left->Play(player_pos.x, player_pos.y, delta);
        }
        else
        {
            anim_right->Play(player_pos.x, player_pos.y, delta);
        }
    }
    else
    {
        std::cerr << "Animation objects are not initialized!" << std::endl;
    }
}

const POINT& Player::GetPosition() const
{
    return player_pos;
}
