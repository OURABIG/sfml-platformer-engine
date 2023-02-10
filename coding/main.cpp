#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Platform.hpp"

static const float VIEW_HEIGHT = 600.0f;
static const float VIEW_WIDHT = 800.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_WIDHT * aspectRatio, VIEW_WIDHT);
}

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(VIEW_WIDHT,VIEW_HEIGHT), "game", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::View view(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(800, 600));
    sf::Texture playertexture;
    playertexture.loadFromFile("res/skin.png");
    sf::Texture blocktexture;
    blocktexture.loadFromFile("res/tile.png");
    sf::Sprite background;
    sf::Texture back;
    

    Player player(&playertexture, sf::Vector2u(6, 3), 0.2f, 200.0f, 400.0f);


    //World
    std::vector<Platform> platforms;
    //up
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 0.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 0.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, 0.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, -100.0f)));
    //middle
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(600.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(700.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 500.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, 500.0f)));
    //down
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(600.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(700.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 400.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, 400.0f)));
    //too down
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(400.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(600.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(700.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 300.0f)));
    platforms.push_back(Platform(&blocktexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(900.0f, 300.0f)));
    //world
    


    Collider playercollider = player.GetCollider(); 

    float deltaTime = 0.0f;
    sf::Clock clock;

    sf::Event ev;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

        while(window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;  
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }
        }


        
        player.Update(deltaTime);

        sf::Vector2f direction;


        for(Platform& platform : platforms)
        {
            if (platform.GetCollider().CheckCollision(playercollider, direction,1.0f))
            {
                player.OnCollision(direction);
            }   
        }

        view.setCenter(player.Getposition());

        window.clear(sf::Color(143, 184, 234));
        window.setView(view);
        player.Draw(window);
        

        for(Platform& platform : platforms)
            platform.Draw(window);

        window.display();
    }
    
    return 0;
}
