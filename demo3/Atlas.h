#pragma once
#include <vector>
#include <graphics.h>


class Atlas
{
public:
    Atlas(LPCTSTR path, int num);
    ~Atlas();

    const std::vector<IMAGE*>& GetFrames() const;

private:
    std::vector<IMAGE*> frame_list;
};
