/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** Gomoku
*/

#ifndef Gomoku_HPP_
#define Gomoku_HPP_
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <iostream>

enum type
{
    WHITE = -2,
    FREE = 0,
    BLACK = 2,
};

class Gomoku
{
protected:
    unsigned int size;
    type **bord;
    type turn = BLACK;

public:
    bool empty = true;

    Gomoku(int _size);
    void print();
    type **getBord() { return bord; }
    void removeUnit(unsigned int y, unsigned int x);
    void resetBoard();
    bool placeUnit(unsigned int y, unsigned int x, type val);
    ~Gomoku();
};

#endif /* !Gomoku_HPP_ */
