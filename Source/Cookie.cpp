#include "Cookie.hpp"

Cookie::Cookie(float radius, const sf::Vector2f& position, const sf::Color& color) {
    shape.setRadius(radius);
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius); // Center the circle
}

void Cookie::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Cookie::isClicked(const sf::Vector2i& mousePosition) {
    sf::Vector2f center = shape.getPosition();
    float radius = shape.getRadius();

    // Check if the mouse is within the circle
    float dx = mousePosition.x - center.x;
    float dy = mousePosition.y - center.y;
    return (dx * dx + dy * dy) <= (radius * radius);
}
