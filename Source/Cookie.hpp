#ifndef COOKIE_HPP
#define COOKIE_HPP

#include <SFML/Graphics.hpp>

class Cookie {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image; // To store the texture's pixel data

public:
    Cookie(const std::string& textureFile, const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePosition);
};

#endif
