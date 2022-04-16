/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** EvalRes
*/

#include "EvalRes.hpp"

evalRes::evalRes(const evalRes &cp): size(cp.size)
{
    vert = new int*[size];
    horiz = new int*[size];
    transl = new int*[size];
    transr = new int*[size];

    for (int i = 0; i < size; i++) {
        vert[i] = new int[size];
        horiz[i] = new int[size];
        transl[i] = new int[size];
        transr[i] = new int[size];
    }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            vert[y][x]  = cp.vert[y][x];
            horiz[y][x]  = cp.horiz[y][x];
            transl[y][x]  = cp.transl[y][x];
            transr[y][x]  = cp.transr[y][x];
        }
}

evalRes::evalRes(int _size) : size(_size)
{
    vert = new int*[size];
    horiz = new int*[size];
    transl = new int*[size];
    transr = new int*[size];

    for (int i = 0; i < size; i++) {
        vert[i] = new int[size];
        horiz[i] = new int[size];
        transl[i] = new int[size];
        transr[i] = new int[size];
    }
}

void evalRes::printAAInt(int **&ptr, int size,const std::string &pres )
{
    std::cout << "\t\t" << pres << "\n";

    for (int y = 0; y < size; y++){
        std::cout << "|\t\t";
        for (int x = 0; x < size; x++)
            std::cout <<( ptr[y][x] == -1 ? "#" : std::to_string(ptr[y][x])) << " ";
        std::cout << "\t\t|\n";
    }
}

void evalRes::print()
{
    printAAInt(this->horiz, size, "Horizontal Print");
    printAAInt(this->vert, size, "Vertical Print");
    printAAInt(this->transr, size, "Transversal R Print");
    printAAInt(this->transl, size, "Transversal L Print");
    std::cout << "=================================================\n";
}

void evalRes::findMax(int **&evalRes, int &res, MaxPos &maxret, int x , int y)
{
    if (evalRes[y][x] > res){
        res = evalRes[y][x];
        maxret.value = res;
        maxret.x.clear();
        maxret.y.clear();
    }
    if (evalRes[y][x] && evalRes[y][x] == res){
        maxret.x.push_back(x);
        maxret.y.push_back(y);
    }
}

void evalRes::getSum()
{
    int resH = 0;
    int resV = 0;
    int resTr = 0;
    int resTl = 0;

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            findMax(horiz, resH, max_horiz, x, y);
            findMax(vert, resV, max_vert, x, y);
            findMax(transl, resTr, max_transl, x, y);
            findMax(transr, resTl, max_transr, x, y);
        }
    return ;
}


evalRes::~evalRes()
{
    deleteAAInt(horiz, size);
    deleteAAInt(vert, size);
    deleteAAInt(transl, size);
    deleteAAInt(transr, size);
}
