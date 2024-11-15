#pragma once
#include "Button.h"

class QuitGameButton : public Button
{
public:
    QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
    ~QuitGameButton() = default;

protected:
    void Onclick() override;
};
