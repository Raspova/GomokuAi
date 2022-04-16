/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** GomokuAi
*/

#ifndef GOMOKUAI_HPP_
#define GOMOKUAI_HPP_
#include "Gomoku.hpp"
#include "EvalRes.hpp"

class GomokuAi : public Gomoku
{
public:
    GomokuAi(int size);
    ~GomokuAi();
    int **bordBufferH;
    int **bordBufferV;
    int **bordBufferTr;
    int **bordBufferTl;
    int **validBufferH;
    int **validBufferV;
    int **validBufferTl;
    int **validBufferTr;

    int **evalute(const type eval, int type);
    evalRes evalute(const type eval);
    int **evaluteH(const type eval, evalRes &buff);
    int **evaluteV(const type eval, evalRes &buff);
    int **evaluteTr(const type eval, evalRes &buff);
    int **evaluteTl(const type eval, evalRes &buff);
    void prepH(const type eval, evalRes &buff);
    void prepV(const type eval, evalRes &buff);
    void prepTr(const type eval, evalRes &buff);
    void prepTl(const type eval, evalRes &buff);
    void tranversal(const type val, evalRes &buff);
    void tranversalprep(const type val);
    void prepBordBuffer(const type val,evalRes &buff);
    
   //oid prepValidBuffer();
protected:
    evalRes blackEval;
    evalRes whiteEval;
private:
   
};

#endif /* !GOMOKUAI_HPP_ */
