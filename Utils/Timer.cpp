//
// Created by kenwi on 12/5/16.
//

#include "Timer.h"

Utils::Timer::Timer() {
    _begin = high_resolution_clock::now();
}

__int64 Utils::Timer::GetCurrentFPS() {
    auto _end  = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(_end - _begin).count();
    if(duration > 5) {
        auto fps = _frames/duration;
        _begin = high_resolution_clock::now();
        _frames = 0;
        return fps;
    }
    _frames++;
    return 0;
}
