#include "Timer.hpp"

Timer::Timer(int interval, std::function<void()> callback)
    : interval(interval), callback(callback) {
}

void Timer::update() {
    if (clock.getElapsedTime().asMilliseconds() >= interval) {
        callback(); // Execute the callback
        reset();
    }
}

void Timer::reset() {
    clock.restart();
}
