#include "Enemy.h"
#include <cmath>
#include <cstdlib>

#include "Globals.h"
#include "Utils.h"



Enemy::Enemy()
{
    loadimage(&img_shadow, _T("img/shadow_enemy.png"));
    anim_left = std::make_unique<Animation>(atlas_enemy_left, 45);
    anim_right = std::make_unique<Animation>(atlas_enemy_right, 45);

    enum class SpawnEdge
    {
        Up = 0,
        Down,
        Left,
        Right
    };

    SpawnEdge edge = (SpawnEdge)(rand() % 4);
    switch (edge)
    {
    case SpawnEdge::Up:
        enemy_position.x = rand() % WINDOW_WIDTH;
        enemy_position.y = -ENEMY_HEIGHT;
        break;
    case SpawnEdge::Down:
        enemy_position.x = rand() % WINDOW_WIDTH;
        enemy_position.y = -WINDOW_HEIGHT;
        break;
    case SpawnEdge::Left:
        enemy_position.x = -ENEMY_WIDTH;
        enemy_position.y = rand() % WINDOW_HEIGHT;
        break;
    case SpawnEdge::Right:
        enemy_position.x = -WINDOW_HEIGHT;
        enemy_position.y = rand() % WINDOW_HEIGHT;
        break;
    default:
        break;
    }
}

bool Enemy::CheckBulletCollision(const Bullet& bullet) const
{
    bool is_overlap_x = bullet.Get_Bullet_Pos().x >= enemy_position.x && bullet.Get_Bullet_Pos().x <= enemy_position.x + ENEMY_WIDTH;
    bool is_overlap_y = bullet.Get_Bullet_Pos().y >= enemy_position.y && bullet.Get_Bullet_Pos().y <= enemy_position.y + ENEMY_HEIGHT;
    return is_overlap_x && is_overlap_y;
}

bool Enemy::CheckPlayerCollision(const Player& player)
{
    POINT check_position = { enemy_position.x + ENEMY_WIDTH / 2, enemy_position.y + ENEMY_HEIGHT / 2 };
    POINT player_position = player.GetPosition();

    bool is_overlap_x = check_position.x >= player_position.x && check_position.x <= player_position.x + player.PLAYER_WIDTH;
    bool is_overlap_y = check_position.y >= player_position.y && check_position.y <= player_position.y + player.PLAYER_HEIGHT;

    return is_overlap_x && is_overlap_y;
}

void Enemy::Move(const Player& player)
{
    const POINT& player_position = player.GetPosition();

    int dir_x = player_position.x - enemy_position.x;
    int dir_y = player_position.y - enemy_position.y;
    double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
    if (len_dir != 0)
    {
        double normalized_x = dir_x / len_dir;
        double normalized_y = dir_y / len_dir;
        enemy_position.x += (int)(SPEED * normalized_x);
        enemy_position.y += (int)(SPEED * normalized_y);
    }
    if (dir_x < 0)
    {
        facing_left = true;
    }
    else if (dir_x > 0)
    {
        facing_left = false;
    }
}

void Enemy::Draw(int delta)
{
    int pos_shadow_x = enemy_position.x + (ENEMY_WIDTH / 2 - SHADOW_WIDTH / 2);
    int pos_shadow_y = enemy_position.y + ENEMY_HEIGHT - 35;
    putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);
    if (facing_left)
    {
        anim_left->Play(enemy_position.x, enemy_position.y, delta);
    }
    else
    {
        anim_right->Play(enemy_position.x, enemy_position.y, delta);
    }
}

void Enemy::Hurt()
{
    Alive = false;
}

bool Enemy::CheckAlive() const
{
    return Alive;
}

const POINT& Enemy::GetPos() const
{
    return enemy_position;
}
