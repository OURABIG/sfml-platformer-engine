#pragma once
#include <SFML/Graphics.hpp>

class animation
{
private:
    sf::Vector2u imagecount;
    sf::Vector2u currentimage;
    float totaltime;
    float switchtime;
public:
    animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~animation();
    void Update(int row, float deltaTime, bool faceRight);

public:
    sf::IntRect uvRect;
};
