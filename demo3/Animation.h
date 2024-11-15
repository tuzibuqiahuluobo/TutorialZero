#pragma once
#include <vector>
#include <graphics.h>
#include "Atlas.h"

class Animation
{
public:
    Animation(Atlas* atlas, int interval);
    ~Animation() = default;

    void Play(int x, int y, int delta);

private:
    int timer = 0;
    int idx_frame = 0;
    int interval_ms = 0;
    std::vector<IMAGE*> frame_list;
	Atlas* anim_atlas = nullptr;
};
