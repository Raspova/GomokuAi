/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** EvalRes
*/

#ifndef EVALRES_HPP_
#define EVALRES_HPP_
#include <iostream>
#include <vector>

void deleteAAInt(int **&ptr, int size);

//struct sum {
//  sum(int _h, int _v, int _tr, int _tl) : h(_h),v(_v),tr(_tr),tl(_tl){}
//  void print(){ std::cout << " " << h << " " << v << " " << tr << " " << tl << "\n";}
//  int h;
//  int v;
//  int tr;
//  int tl;
//};

struct MaxPos
{
  MaxPos(int _type) : type(_type){}
  int value = -1;
  int type;
  std::vector<int> x;
  std::vector<int> y;
};


struct evalRes
{
    int **horiz;
    int **vert;
    int **transl;
    int **transr;
    MaxPos max_horiz = MaxPos(0);
    MaxPos max_vert = MaxPos(1);
    MaxPos max_transl = MaxPos(2);
    MaxPos max_transr = MaxPos(3);
    int size;
    evalRes(){};
    evalRes(int size);
    evalRes(const evalRes &cp);
    ~evalRes();
    void findMax(int **&evalRes, int &res, MaxPos &maxret,int x, int y );
    void getSum();
    void print();
    void printAAInt(int **&ptr, int size,const std::string &pres);
};



#endif /* !EVALRES_HPP_ */
