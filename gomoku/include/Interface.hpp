#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#include "Player.hpp"

class Interface
{
public:
    Interface();
    ~Interface();

    void ParseCmd();
    void start();
    void turn();
    void begin();
    void board();
    void info();
    void end();
    void about();
    void takeback();
    void print();
    void restart();

private:
    std::string _cmd;
    std::vector<int> _vals;
    std::map<std::string, void (Interface::*)()> _funcs;
    std::vector<std::vector<int>> _map;
    bool set = false;

protected:
    Player *player = nullptr;
};

#endif
