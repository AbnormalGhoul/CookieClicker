#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/System/Clock.hpp>
#include <functional>

class Timer {
private:
    sf::Clock clock;
    int interval; // Interval in milliseconds
    std::function<void()> callback; // Action to trigger when the interval elapses

public:
    Timer(int interval, std::function<void()> callback);

    void update();
    void reset();
};

#endif
