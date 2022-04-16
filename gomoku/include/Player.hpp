/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "GomokuAi.hpp"
#include <array>

class Player : public GomokuAi
{
public:
    Player(const size_t size = 20, const type _id = BLACK, const int **map = nullptr);
    ~Player();
    std::string prepRet(int y, int x);
    std::string play();
    std::string prepRetV(int y, int x, int value, int type);
    std::string playV();
    std::vector<MaxPos> getMaxEvals(evalRes res);
    type oposite;
    type id;

protected:
private:
    std::array<int, 2> bestPos(std::vector<MaxPos> myMax, const type id);
};

#endif /* !PLAYER_HPP_ */
