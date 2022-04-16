#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "GOMOKU");
    sf::Texture bt;
    sf::Texture wt;
    sf::Texture gt;
    int size = 11;
    const std::string as = "./asset/";
    Player p(size);
    type **b;
    bool SpacePressed = false;
    bool checkmouse = false;
    int x, y;
    sf::Music mus;
    sf::SoundBuffer bsfx;
    sf::Sound sfx;
    std::string lastPlay = "";
    sf::CircleShape circle(7);
    if (!bt.loadFromFile(as + "black.png") || !wt.loadFromFile(as + "white.png") || !gt.loadFromFile(as + "grey.png"))
        return 84;
    sf::Sprite bs(bt);
    sf::Sprite ws(wt);
    sf::Sprite gs(gt);
      
    circle.setFillColor(sf::Color(250,0, 0));
    if (!mus.openFromFile(as +"bck.ogg") ||!bsfx.loadFromFile(as +"pop.ogg"))
        return 84;
    sfx.setBuffer(bsfx);
    mus.setLoop(true);
    mus.play();
   
    gs.scale(0.5,0.5);
    bs.scale(0.5,0.5);
    ws.scale(0.5,0.5);
    p.play();
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        b = p.getBord();
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++) {
                if (b[y][x]  == FREE) {
                    gs.setPosition(360  + x * 86, 60 + y * 86);
                    window.draw(gs);
                } else if (b[y][x]  == BLACK) {
                    bs.setPosition(350 + x * 86, 50 + y * 86);
                    window.draw(bs);
                } else if (b[y][x]  == WHITE) {
                    ws.setPosition(350 + x * 86 , 50 + y * 86);
                    window.draw(ws);
                }

            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            p.resetBoard();
            mus.stop();
            p.empty = true;
            p.play();
            mus.play();
        }
        if (sf::Mouse::isButtonPressed (sf::Mouse::Button::Left))
            checkmouse = true;
        if (checkmouse && event.type ==  sf::Event::MouseButtonReleased){
            checkmouse = false;
            auto mouse_pos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mouse_pos);
            x =  (translated_pos.x - 350)  / 86;
            y =  (translated_pos.y - 50)  / 86;
            if (p.placeUnit(y, x, WHITE)) {
                int bRand = std::rand() % 7000;
                bRand += 7000;
                sfx.setPitch((float)bRand / 10000.0f);
                sfx.play();
                lastPlay =  p.play();
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
            SpacePressed = true;
        if (event.type ==  sf::Event::KeyReleased && SpacePressed) {
            SpacePressed = false;
            p.id = WHITE;
            p.play();
            p.id = BLACK;
            p.play();
        }
        if (lastPlay != "") { 
            circle.setPosition(sf::Vector2f(385 + std::stoi(lastPlay.substr(0, lastPlay.find(',') + 1)) * 86
            ,82 + std::stoi(lastPlay.substr(lastPlay.find(',') + 1)) * 86 ));
            window.draw(circle);
        }
        window.display();
        window.clear(sf::Color(230, 186, 149));
    }
    mus.stop();
    return 0;
}