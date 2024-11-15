#include <graphics.h>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <windows.h>
#include "Button.h"
#include "StartGameButton.h"
#include "QuitGameButton.h"
#include "Atlas.h"
#include "Animation.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Globals.h"
#include "Utils.h"

#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")



inline void TryGenerateEnemy(std::vector<std::unique_ptr<Enemy>>& enemy_list)
{
    const int INTERVAL = 100;
    static int counter = 0;
    if ((++counter) % INTERVAL == 0)
    {
        enemy_list.push_back(std::make_unique<Enemy>());
    }
}

inline void UpdateBullets(std::vector<Bullet>& bullet_list, const Player& player)
{
    const double RADIAL_SPEED = 0.0045;
    const double TANGENT_SPEED = 0.0055;
    double radian_interval = 2 * 3.14159 / bullet_list.size();
    POINT player_position = player.GetPosition();
    double radius = 100 + 25 * sin(GetTickCount() * RADIAL_SPEED);
    for (size_t i = 0; i < bullet_list.size(); i++)
    {
        double radian = GetTickCount() * TANGENT_SPEED + radian_interval * i;
        bullet_list[i].position.x = player_position.x + player.PLAYER_WIDTH / 2 + (int)(radius * sin(radian));
        bullet_list[i].position.y = player_position.y + player.PLAYER_HEIGHT / 2 + (int)(radius * cos(radian));
    }
}

inline void DrawPlayerScore(int score)
{
    static TCHAR text[64];
    _stprintf_s(text, _T("当前玩家得分：%d"), score);

    setbkmode(TRANSPARENT);
    settextcolor(RGB(255, 85, 185));
    outtextxy(10, 10, text);
}

int main()
{
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

    atlas_player_left = new Atlas(L"img/player_left_%d.png", 6);
    atlas_player_right = new Atlas(L"img/player_right_%d.png", 6);
    atlas_enemy_left = new Atlas(L"img/enemy_left_%d.png", 6);
    atlas_enemy_right = new Atlas(L"img/enemy_right_%d.png", 6);

    mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
    mciSendString(_T("open mus/hit.wav alias hit"), NULL, 0, NULL);

    int score = 0;

    Bullet bullet;
    Player player;
    ExMessage msg;

    IMAGE img_menu;
    IMAGE img_background;

    std::vector<std::unique_ptr<Enemy>> enemy_list;
    std::vector<Bullet> bullet_list(3);

    RECT region_btn_start_game{}, region_btn_quit_game{};
    region_btn_start_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
    region_btn_start_game.right = region_btn_start_game.left + BUTTON_WIDTH;
    region_btn_start_game.top = 430;
    region_btn_start_game.bottom = region_btn_start_game.top + BUTTON_HEIGHT;

    region_btn_quit_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
    region_btn_quit_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
    region_btn_quit_game.top = 550;
    region_btn_quit_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT;

    std::unique_ptr<StartGameButton> btn_start_game = std::make_unique<StartGameButton>(
        region_btn_start_game,
        _T("img/ui_start_idle.png"),
        _T("img/ui_start_hovered.png"),
        _T("img/ui_start_pushed.png"));

    std::unique_ptr<QuitGameButton> btn_quit_game = std::make_unique<QuitGameButton>(
        region_btn_quit_game,
        _T("img/ui_quit_idle.png"),
        _T("img/ui_quit_hovered.png"),
        _T("img/ui_quit_pushed.png"));

    loadimage(&img_menu, _T("img/menu.png"));
    loadimage(&img_background, _T("img/background.png"));

    BeginBatchDraw();

    while (Running)
    {
        DWORD start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            if (is_game_started)
            {
                player.processEvent(msg);
            }
            else
            {
                btn_start_game->ProcessEvent(msg);
                btn_quit_game->ProcessEvent(msg);
            }
        }

        if (is_game_started)
        {
            TryGenerateEnemy(enemy_list);
            player.Move();
            UpdateBullets(bullet_list, player);
            for (auto& enemy : enemy_list)
                enemy->Move(player);

            for (auto& enemy : enemy_list)
            {
                if (enemy->CheckPlayerCollision(player))
                {
                    static TCHAR text[128];
                    _stprintf_s(text, _T("最终得分：%d！"), score);
                    MessageBox(GetHWnd(), text, _T("游戏结束！"), MB_OK);
                    Running = false;
                    break;
                }
            }

            for (auto& enemy : enemy_list)
            {
                for (const auto& bullet : bullet_list)
                {
                    if (enemy->CheckBulletCollision(bullet))
                    {
                        mciSendString(_T("play hit from 0"), NULL, 0, NULL);
                        enemy->Hurt();
                        score++;
                    }
                }
            }

            enemy_list.erase(
                std::remove_if(enemy_list.begin(), enemy_list.end(),
                    [](const std::unique_ptr<Enemy>& enemy) { return !enemy->CheckAlive(); }),
                enemy_list.end());
        }

        cleardevice();
        if (is_game_started)
        {
            putimage(0, 0, &img_background);
            player.Draw(1000 / 144);
            for (const auto& enemy : enemy_list)
                enemy->Draw(1000 / 144);

            UpdateBullets(bullet_list, player);

            for (const Bullet& bullet : bullet_list)
            {
                bullet.Draw();
            }

            DrawPlayerScore(score);
        }
        else
        {
            putimage(0, 0, &img_menu);
            btn_start_game->Draw();
            btn_quit_game->Draw();
        }

        FlushBatchDraw();

        DWORD end_time = GetTickCount();
        DWORD delta_time = end_time - start_time;

        if (delta_time < 1000 / 144)
        {
            Sleep(1000 / 144 - delta_time);
        }
    }

    delete atlas_player_left;
    delete atlas_player_right;
    delete atlas_enemy_left;
    delete atlas_enemy_right;

    EndBatchDraw();

    return 0;
}