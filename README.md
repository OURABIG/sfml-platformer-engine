# sfml-platformer-engine
you can help me develop more feature and make more tools by supporting me on patreon: https://www.patreon.com/OURABIG

THIS A PLATFORMER ENGINE I MADE WITH SFML AND C++ YOU CAN USE IT TO CREATE SIMPLE PLATFORMER GAME YOU CAN ALSO REPLACE THE ASSETS AND MODIFY THE ANIMATION IN THE PLAYER.cpp FILE BY CHANGING THE ROWS WICH MEAN THE LINE WE START FROM 0 SINCE IT'S AN ARRAY: 
```c++
void Player::Update(float deltaTime)
{
    velocity.x = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
    }


    velocity.y += 981.0f * deltaTime;
    
    if(velocity.x == 0.0f)
    {
        row = 0; // THE ROW = FOR IDLE ANIMATION
    }
    else
    {
        row = 1;
        if (velocity.x > 0.0f)
           faceRight = true;
        else
            faceRight = false;
    }
    
    anime.Update(row, deltaTime, faceRight);
    body.setTextureRect(anime.uvRect);
    body.move(velocity* deltaTime);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if(direction.x < 0.0f)
    {
        //collision on the left
        velocity.x = 0.0f;
    }
    else if(direction.x > 0.0f)
    {
        //collision .right
        velocity.x = 0.0f;
    }
    if(direction.y > 0.0f)
    {
        //collision top
        velocity.y = 0.0f;
        row = 2; // JUMP ANIMATION
    }
    else if(direction.y < 0.0f)
    {
        //collision bottom
        velocity.y = 0.0f;
        canJump = true;
    }
}
```
![game 30_01_2023 14_30_19](https://user-images.githubusercontent.com/94923157/216165137-9db0a503-6206-4b4b-9cda-b8b445e1192e.png)
