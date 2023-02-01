#include "animation.hpp"

animation::animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imagecount = imageCount;
    this->switchtime = switchTime;
    totaltime = 0.0f;
    currentimage.x = 0;

    uvRect.width = texture->getSize().x /float(imageCount.x);
    uvRect.height = texture->getSize().y /float(imageCount.y);
}

animation::~animation()
{

}

void animation::Update(int row, float deltaTime, bool faceRight)
{
    currentimage.y = row;
    totaltime += deltaTime;

    if(totaltime >= switchtime)
    {
        totaltime -= switchtime;
        currentimage.x++;

        if(currentimage.x >= imagecount.x)
        {
            currentimage.x = 0;
        }
    }

    
    uvRect.top = currentimage.y * uvRect.height;
    if (faceRight)
    {
         uvRect.left = currentimage.x * uvRect.width;
         uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentimage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
    
}