#include "Interface.hpp"
#include <limits>

Interface::Interface()
{
    _funcs["START"] = &Interface::start;
    _funcs["TURN"] = &Interface::turn;
    _funcs["BEGIN"] = &Interface::begin;
    _funcs["BOARD"] = &Interface::board;
    _funcs["INFO"] = &Interface::info;
    _funcs["END"] = &Interface::end;
    _funcs["ABOUT"] = &Interface::about;
    _funcs["PRINT"] = &Interface::print;
    _funcs["TAKEBACK"] = &Interface::takeback;
    _funcs["RESTART"] = &Interface::restart;
}

Interface::~Interface()
{
    free(player);
}

void Interface::restart()
{
    player->resetBoard();
}

void Interface::takeback()
{
    if (_vals.size() != 2)
    {
        std::cerr << "TakeBack ERROR";
        return;
    }
    player->removeUnit(_vals[1], _vals[0]);
}

void Interface::print()
{
    player->print();
}

void Interface::ParseCmd()
{
    std::vector<std::string> tmp;
    char *tok;
    std::string line = "";

    _vals.clear();
    tmp.clear();
    while (line == "")
        std::getline(std::cin, line);
    tok = new char[line.size() + 1];
    std::strcpy(tok, line.c_str());
    tok = std::strtok(tok, " ,");
    while (tok != NULL)
    {
        tmp.push_back(tok);
        tok = std::strtok(NULL, " ,");
    }
    if (tmp.empty())
        return;
    _cmd = tmp[0];
    for (int i = 1; i != tmp.size(); i++)
        _vals.push_back(stoi(tmp[i]));
    if (!_funcs[_cmd])
        std::cout << "Invalid Command" << std::endl;
    else if (set || _cmd == "START")
        (this->*_funcs[_cmd])();
    else
        exit(84);
    free(tok);
}

void Interface::start()
{
    if (_vals.size() != 1 || _vals[0] < 5)
    {
        std::cout << "ERROR message - unsupported size or other error" << std::endl;
        return;
    }
    set = true;
    std::cout << "OK - everything is good" << std::endl;
    player = new Player(_vals[0]);
}

void Interface::turn()
{
    if (_vals.size() != 2)
    {
        std::cerr << "TURN ERROR";
        return;
    }
    player->placeUnit(_vals[1], _vals[0], player->oposite);
    player->play();
}

void Interface::begin()
{
    player->play();
}

void Interface::board()
{
    char *tok;
    std::string line;
    std::vector<std::string> tmp;
    std::string fst = "";
    int y;
    int x;
    type _type;

    while (true)
    {
        std::getline(std::cin, line);
        tok = new char[line.size() + 1];
        std::strcpy(tok, line.c_str());
        tok = std::strtok(tok, " ,");
        tmp.clear();
        while (tok != NULL)
        {
            tmp.push_back(tok);
            tok = std::strtok(NULL, " ,");
        }
        fst = tmp[0];
        if (fst == "DONE")
            break;
        x = stoi(tmp[0]); // check size > 3 et alphanum
        y = stoi(tmp[1]);
        _type = stoi(tmp[2]) == 1 ? BLACK : WHITE;
        player->placeUnit(y, x, _type);
        free(tok);
    }
    player->play();
}
void Interface::end()
{
    exit(0);
}
void Interface::info()
{
}

void Interface::about()
{
    std::cout << "name=\"GOMOKOOM\", version=\"1.3\", author=\"Jonathan Layundhur, Edouard Courty, Rémi Delaporte\", country=\"MAURITUS, FRANCE\"";
    // std::cout << "name=\"LEspoirMauricien\", version=\"over999\", author=\"JojoLeHeroSolitaire\", country=\"MAURITUS\"";
}
