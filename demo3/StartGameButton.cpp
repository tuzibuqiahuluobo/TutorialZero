#include "StartGameButton.h"
#include <mmsystem.h>

#include "Globals.h"


StartGameButton::StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
    : Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {
}

void StartGameButton::Onclick()
{
    is_game_started = true;
    mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
}
