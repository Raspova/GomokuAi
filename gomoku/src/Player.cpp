/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(const size_t size, const type _id, const int **map) : GomokuAi(size), id(_id)
{
    if (map)
        empty = false;
    oposite = (_id == BLACK ? WHITE : BLACK);
}
std::string Player::prepRet(int y, int x)
{
    std::string res;

    res += std::to_string(x) + "," + std::to_string(y) + "\n";
    placeUnit(y, x, id);
    std::cout << res;
    return res;
}

std::vector<MaxPos> Player::getMaxEvals(evalRes res)
{
    int buff;
    std::vector<int> buffindex = {0};
    std::vector<int> buffvalue;
    std::vector<MaxPos> ret;
    std::vector<MaxPos> buffRet;

    res.getSum();
    buff = res.max_horiz.value;
    buffvalue.push_back(res.max_vert.value);
    buffvalue.push_back(res.max_transl.value);
    buffvalue.push_back(res.max_transr.value);
    buffRet = {res.max_horiz, res.max_vert, res.max_transl, res.max_transr};

    for (int i = 0; i < buffvalue.size(); i++)
    {
        if (buffvalue[i] > buff)
        {
            buffindex.clear();
            buff = buffvalue[i];
        }
        if (buffvalue[i] == buff)
            buffindex.push_back(i + 1);
    }
    for (int i : buffindex)
        ret.push_back(buffRet[i]);
    return ret;
}

std::array<int, 2> Player::bestPos(std::vector<MaxPos> max, const type val)
{
    std::array<int, 2> ret = {-1, -1};
    int **buff;
    int buffSum = 0;
    int supSum = 0;

    if (max.size() == 1 && max[0].x.size() == 1)
    {
        ret[0] = max[0].y[0];
        ret[1] = max[0].x[0];
        return ret;
    }
    for (MaxPos pos : max)
    {
        for (size_t i = 0; i < pos.x.size(); i++)
        {
            buffSum = 0;
            placeUnit(pos.y[i], pos.x[i], val);
            buff = evalute(val, pos.type);
            for (int y = 0; y < size; y++)
                for (int x = 0; x < size; x++)
                    if (buff[y][x] != 0)
                        buffSum += buff[y][x];
            if (buffSum > supSum)
            {
                ret[0] = pos.y[i];
                ret[1] = pos.x[i];
            }
            removeUnit(pos.y[i], pos.x[i]);
        }
    }
    if (ret[0] == -1)
    {
        ret[0] = max[0].y[0];
        ret[1] = max[0].x[0];
    }
    return ret;
}
std::string Player::play()
{
    std::vector<MaxPos> myMax;
    std::vector<MaxPos> opMax;
    std::array<int, 2> buff;

    if (empty)
    {
        empty = false;
        return prepRet(size / 2, size / 2);
    }
    evalRes me = evalute(id);
    evalRes op = evalute(oposite);
    myMax = getMaxEvals(me);
    opMax = getMaxEvals(op);

    for (MaxPos res : myMax)
    {
        if (res.value == 4)
            return prepRet(res.y[0], res.x[0]); // VICTORY
    }
    if (opMax[0].value > myMax[0].value)
        buff = bestPos(opMax, oposite);
    else
        buff = bestPos(myMax, id);
    return prepRet(buff[0], buff[1]);
}

std::string Player::prepRetV(int y, int x, int typeOfPlay, int Value_of_Play)
{
    std::string res;

    res += std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(Value_of_Play) + " " + std::to_string(typeOfPlay) + "\n";
    placeUnit(y, x, id);
    return res;
}

std::string Player::playV()
{
    std::vector<MaxPos> myMax;
    std::vector<MaxPos> opMax;
    std::array<int, 2> buff;

    if (empty)
    {
        empty = false;
        return prepRet(size / 2, size / 2);
    }
    evalRes me = evalute(id);
    evalRes op = evalute(oposite);
    myMax = getMaxEvals(me);
    opMax = getMaxEvals(op);

    for (MaxPos res : myMax)
    {
        if (res.value == 4)
            return prepRetV(res.y[0], res.x[0], 0, 4); // VICTORY
    }
    if (opMax[0].value > myMax[0].value)
    {
        buff = bestPos(opMax, oposite);
        return prepRetV(buff[0], buff[1], 1, myMax[0].value);
    }
    else
    {
        buff = bestPos(myMax, id);
        return prepRetV(buff[0], buff[1], 0, myMax[0].value);
    }
}

Player::~Player()
{
}
