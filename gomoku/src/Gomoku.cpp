/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** Gomoku
*/

#include "Gomoku.hpp"

void Gomoku::print()
{
    for (int y = 0; y < size; y++)
    {
        std::cout << "|\t\t";
        for (int x = 0; x < size; x++)
            std::cout << (bord[y][x] == WHITE ? "W" : (bord[y][x] == BLACK ? "B" : ".")) << " ";
        std::cout << "\t\t|\n";
    }
    std::cout << "=================================================\n";
}

Gomoku::~Gomoku()
{
    for (int i = 0; i < size; i++)
        delete[] bord[i];
    delete[] bord;
}

Gomoku::Gomoku(int _size) : size(_size)
{
    bord = new type *[size];
    for (int i = 0; i < size; i++)
        bord[i] = new type[size];

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            bord[y][x] = FREE;
}

void Gomoku::removeUnit(unsigned int y, unsigned int x)
{
    if (bord[y][x] == FREE)
        std::cerr << "ALREADY FREE";
    else
        bord[y][x] = FREE;
}

void Gomoku::resetBoard()
{
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            bord[y][x] = FREE;
}

bool Gomoku::placeUnit(unsigned int y, unsigned int x, type val)
{
    if (y >= size || x >= size)
    {
        std::cerr << "size error : " << y << " " << x << "\n";
        return false;
    }
    else if (bord[y][x] != FREE)
    {
        std::cerr << "Placement Error";
        return false;
    }
    empty = false;
    bord[y][x] = val;
    turn = val == BLACK ? WHITE : BLACK;
    return true;
}
