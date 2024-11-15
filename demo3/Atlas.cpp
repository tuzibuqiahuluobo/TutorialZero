#include "Atlas.h"

Atlas::Atlas(LPCTSTR path, int num)
{
    TCHAR path_file[256];
    for (size_t i = 0; i < num; i++)
    {
        _stprintf_s(path_file, path, i);
        IMAGE* frame = new IMAGE();
        loadimage(frame, path_file);
        frame_list.push_back(frame);
    }
}

Atlas::~Atlas()
{
    for (size_t i = 0; i < frame_list.size(); i++)
    {
        delete frame_list[i];
    }
}

const std::vector<IMAGE*>& Atlas::GetFrames() const
{
    return frame_list;
}
