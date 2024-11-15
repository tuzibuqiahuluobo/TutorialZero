#include "Animation.h"
#include <iostream>
#include "Globals.h"
#include "Atlas.h"
#include "Utils.h"


Animation::Animation(Atlas* atlas, int interval)
{
    anim_atlas = atlas;
    interval_ms = interval;
    frame_list = anim_atlas->GetFrames();
}

void Animation::Play(int x, int y, int delta)
{
    if (this == nullptr)
    {
        return;
    }

    if (frame_list.empty())
    {
        std::cerr << "Frame list is empty!" << std::endl;
        return;
    }

    if (interval_ms == 0)
    {
        std::cerr << "Interval is zero!" << std::endl;
        return;
    }

    timer += delta;
    if (timer >= interval_ms)
    {
        idx_frame = (idx_frame + 1) % frame_list.size();
        timer = 0;
    }

    if (!frame_list.empty() && idx_frame >= 0 && idx_frame < frame_list.size())
    {
        putimage_alpha(x, y, frame_list[idx_frame]);
    }
    else
    {
        std::cerr << "Invalid frame index or empty frame list!" << std::endl;
    }
}
