#include "QuitGameButton.h"
#include "Globals.h"


QuitGameButton::QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
    : Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {
}

void QuitGameButton::Onclick()
{
    Running = false;
}
