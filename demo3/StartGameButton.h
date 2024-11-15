#pragma once
#include "Button.h"

class StartGameButton : public Button
{
public:
    StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
    ~StartGameButton() = default;

protected:
    void Onclick() override;
};
