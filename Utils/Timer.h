//
// Created by kenwi on 12/5/16.
//

#ifndef IMPROVED_POTATO_TIMER_H
#define IMPROVED_POTATO_TIMER_H

#include <chrono>
using namespace std::chrono;

namespace Utils {
    class Timer {
        using Clock = high_resolution_clock;
        using TimePoint = time_point<Clock>;

    private:
        int _frames;
        TimePoint _begin;

    public:
        Timer();
		__int64  GetCurrentFPS();
    };
}

#endif //IMPROVED_POTATO_TIMER_H
