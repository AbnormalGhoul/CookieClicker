#include "Cookie.hpp"
#include <stdexcept>

Cookie::Cookie(const std::string& textureFile, const sf::Vector2f& position) {
    // Load the cookie texture
    if (!texture.loadFromFile(textureFile)) {
        throw std::runtime_error("Failed to load cookie texture from " + textureFile);
    }

    // Create the sprite
    sprite.setTexture(texture);
    sprite.setPosition(position);

    // Center the sprite origin
    sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);

    // Load the texture into an image for pixel-perfect detection
    image = texture.copyToImage();
}

void Cookie::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Cookie::isClicked(const sf::Vector2i& mousePosition) {
    sf::FloatRect bounds = sprite.getGlobalBounds();

    // Check if the mouse is within the sprite bounds
    if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        // Translate global mouse position to local sprite position
        sf::Vector2f localPos = sf::Vector2f(mousePosition.x, mousePosition.y) - sprite.getPosition();
        localPos.x += sprite.getOrigin().x;
        localPos.y += sprite.getOrigin().y;

        // Get texture size to ensure we don't access out-of-bounds pixels
        sf::Vector2u textureSize = texture.getSize();
        if (localPos.x >= 0 && localPos.y >= 0 &&
            static_cast<unsigned int>(localPos.x) < textureSize.x &&
            static_cast<unsigned int>(localPos.y) < textureSize.y) {
            // Check the alpha value of the pixel
            sf::Color pixelColor = image.getPixel(static_cast<unsigned int>(localPos.x),
                static_cast<unsigned int>(localPos.y));
            if (pixelColor.a > 0) {
                return true; // Non-transparent part was clicked
            }
        }
    }

    return false; // Either outside bounds or on a transparent pixel
}
