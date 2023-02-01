#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "animation.hpp"
#include "Collider.hpp"

class Player
{
private:
    sf::RectangleShape body;
    animation anime; 
    unsigned int row;
    float speed;
    bool faceRight;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;

public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f Getposition(){ return body.getPosition(); }
    Collider GetCollider(){ return Collider(body); }
};


