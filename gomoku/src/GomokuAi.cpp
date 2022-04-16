/*
** EPITECH PROJECT, 2022
** Gomoku
** File description:
** GomokuAi
*/

#include "GomokuAi.hpp"

void deleteAAInt(int **&ptr, int size)
{
    for (int i = 0; i < size; i++)
        delete[] ptr[i];
    delete[] ptr;
}

void GomokuAi::tranversalprep(const type val)
{
    for (int x = size - 5 ; x >= 0; x--)
        for (int i = 0 ; x + i + 4 < size; i++)
            if ((bord[i][x + i] == FREE || bord[i][x + i] == val)
                && (bord[1 + i][x + 1 + i] == FREE || bord[1 + i][x + 1 + i] == val)
                && (bord[2 + i][x + 2 + i] == FREE || bord[2 + i][x + 2 + i] == val)
                && (bord[3 + i][x + 3 + i] == FREE || bord[3 + i][x + 3 + i] == val)
                && (bord[4 + i][x + 4 + i] == FREE || bord[4 + i][x + 4 + i] == val)) {
                    validBufferTr[i][x + i] = 1;
                    validBufferTr[1 + i][x + 1 + i] = 1;
                    validBufferTr[2 + i][x + 2 + i] = 1;
                    validBufferTr[3 + i][x + 3 + i] = 1;
                    validBufferTr[4 + i][x + 4 + i] = 1;
            }
    for (int y = 0 ; y < size - 4 ; y++)
        for (int i = 0 ; y + i + 4 < size; i++)
            if ((bord[y + i][i] == FREE || bord[y + i][i] == val)
                && (bord[y + 1 + i][1 + i] == FREE || bord[y + 1 + i][1 + i] == val)
                && (bord[y + 2 + i][2 + i] == FREE || bord[y + 2 + i][2 + i] == val)
                && (bord[y + 3 + i][3 + i] == FREE || bord[y + 3 + i][3 + i] == val)
                && (bord[y + 4 + i][4 + i] == FREE || bord[y + 4 + i][4 + i] == val)) {
                    validBufferTr[y + i][i] = 1;
                    validBufferTr[y + 1 + i][1 + i] = 1;
                    validBufferTr[y + 2 + i][2 + i] = 1;
                    validBufferTr[y + 3 + i][3 + i] = 1;
                    validBufferTr[y + 4 + i][4 + i] = 1;
                }
    for (int x = 4; x < size; x++)
        for (int i = 0; x - i - 4  >= 0; i++)
             if ((bord[i][x - i] == FREE || bord[i][x - i] == val)
                && (bord[1 + i][x - 1 - i] == FREE || bord[1 + i][x - 1 - i] == val)
                && (bord[2 + i][x - 2 - i] == FREE || bord[2 + i][x - 2 - i] == val)
                && (bord[3 + i][x - 3 - i] == FREE || bord[3 + i][x - 3 - i] == val)
                && (bord[4 + i][x - 4 - i] == FREE || bord[4 + i][x - 4 - i] == val)) {
                    validBufferTl[i][x - i] = 1;
                    validBufferTl[1 + i][x - 1 - i] = 1;
                    validBufferTl[2 + i][x - 2 - i] = 1;
                    validBufferTl[3 + i][x - 3 - i] = 1;
                    validBufferTl[4 + i][x - 4 - i] = 1;
                }
    for (int y = 0; y < size - 4; y++) {
        for (int i = 0 ; (y + i + 4) < size && (size - 4 - i) > 0 ; i++)
            if ((bord[y + i][size -i -1] == FREE || bord[y + i][size -i -1] == val)
                && (bord[y + 1 + i][size - 1 - i - 1] == FREE || bord[y + 1 + i][size - 1 - i -1] == val)
                && (bord[y + 2 + i][size - 2 - i - 1] == FREE || bord[y + 2 + i][size - 2 - i -1] == val)
                && (bord[y + 3 + i][size - 3 - i - 1] == FREE || bord[y + 3 + i][size - 3 - i -1] == val)
                && (bord[y + 4 + i][size - 4 - i - 1] == FREE || bord[y + 4 + i][size - 4 - i -1] == val)) {
                    validBufferTl[y + i][size -i -1] = 1;
                    validBufferTl[y + 1 + i][size - 1 - i -1] = 1;
                    validBufferTl[y + 2 + i][size - 2 - i -1] = 1;
                    validBufferTl[y + 3 + i][size - 3 - i -1] = 1;
                    validBufferTl[y + 4 + i][size - 4 - i -1] = 1;
                }
    }
}

void GomokuAi::tranversal(const type val, evalRes &buff)
{
    int count = 0;

    for (int x = size - 5 ; x >= 0; x--)
        for (int i = 0 ; x + i < size; i++)
            if(bordBufferTr[i][x + i] ==  val) {
                for (count = 0;x + i < size && bordBufferTr[i][x + i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transr[(i - count - 1)][x + (i - count - 1)] != -1)
                    buff.transr[(i - count - 1)][x + (i - count - 1)] += count;
                if (i + x < size && buff.transr[i][i + x] != -1)
                    buff.transr[i][x + i] += count;
            }
    for (int y = 0 ; y < size - 4 ; y++)
        for (int i = 0 ; y + i < size; i++)
            if  (bordBufferTr[y + i][i] == val) {
                for (count = 0;y + i < size && bordBufferTr[y + i][i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transr[y + (i - count - 1)][(i - count - 1)] != -1)
                    buff.transr[(y + i - count - 1)][(i - count - 1)] += count;
                if (i + y < size && buff.transr[i + y][i] != -1)
                    buff.transr[y + i][i] += count;
            }
    for (int x = 4; x < size; x++)
        for (int i = 0; x - i >= 0; i++)
             if(bordBufferTl[i][x - i] ==  val) {
                for (count = 0; x - i >= 0 && bordBufferTl[i][x - i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transl[(i - count - 1)][x - (i - count - 1)] != -1)
                    buff.transl[(i - count - 1)][x - (i - count - 1)] += count;
                if (x - i >= 0 && buff.transl[i][x- i ] != -1 )
                    buff.transl[i][x - i] += count;
            }
    for (int y = 0; y  < size - 4; y++)
        for (int i = 0 ; (y + i) < size && int(size - 1 - i) >= 0 ; i++)
            if ((bord[y + i][size - 1 - i] ==  val)) {
                for (count = 0; (y + i) < size && int(size - 1 - i) >= 0 && bordBufferTl[y + i][size - 1 - i] == val ; i++, count++);
                if (((i - count - 1) + y) < size && (int(size) - 1 - (i - count - 1)) >= 0 && buff.transl[y + (i - count - 1)][size - 1 - (i - count - 1)])
                    buff.transl[y + (i - count - 1)][size - 1 - (i - count - 1)]  += count;
                if (y + i < size && (int(size - 1 - i) >= 0) && buff.transl[y + i][size - 1 - i] != -1)
                    buff.transl[y + i][size - 1 - i] += count;
            }
}

void GomokuAi::prepH(const type  val, evalRes &buff)
{
    int oposite = (val == BLACK ? WHITE : BLACK);

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            validBufferH[y][x] = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size - 4; x++)
            if ((bord[y][x] == FREE || bord[y][x] == val)
                && (bord[y][x + 1] == FREE || bord[y][x + 1] == val)
                && (bord[y][x + 2] == FREE || bord[y][x + 2] == val)
                && (bord[y][x + 3] == FREE || bord[y][x + 3] == val)
                && (bord[y][x + 4] == FREE || bord[y][x + 4] == val) ){
                validBufferH[y][x] = 1;
                validBufferH[y][x + 1] = 1;
                validBufferH[y][x + 2] = 1;
                validBufferH[y][x + 3] = 1;
                validBufferH[y][x + 4] = 1;
            }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            bordBufferH[y][x] = (validBufferH[y][x] == 0) ? -1 : bord[y][x];
            buff.horiz[y][x] = (validBufferH[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
        }
}
int **GomokuAi::evaluteH(const type eval, evalRes &buff)
{
    int count = 0;

    prepH(eval, buff);
    for (int y = 0 ; y < size; y++)
        for (int x = 0 ; x < size; x++)
            if(bordBufferH[y][x] == eval) {
                for (count = 0; x < size && bordBufferH[y][x] == eval;  count++, x++);
                if ((x - count - 1) >= 0 && buff.horiz[y][x - count - 1] != -1)
                    buff.horiz[y][x - count - 1] += count;
                if (x < size && buff.horiz[y][x] != -1)
                    buff.horiz[y][x] += count;
            }
    return buff.horiz;
}

void GomokuAi::prepV(const type val, evalRes &buff)
{
    int oposite = (val == BLACK ? WHITE : BLACK);

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            validBufferV[y][x] = 0;
    for (int y = 0; y < size - 4; y++)
        for (int x = 0; x < size; x++)
            if ((bord[y][x] == FREE || bord[y][x] == val)
                && (bord[y + 1][x] == FREE || bord[y + 1][x] == val)
                && (bord[y + 2][x] == FREE || bord[y + 2][x] == val)
                && (bord[y + 3][x] == FREE || bord[y + 3][x] == val)
                && (bord[y + 4][x] == FREE || bord[y + 4][x] == val)) {
                validBufferV[y][x] = 1;
                validBufferV[y + 1][x] = 1;
                validBufferV[y + 2][x] = 1;
                validBufferV[y + 3][x] = 1;
                validBufferV[y + 4][x] = 1;
            }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            bordBufferV[y][x] = (validBufferV[y][x] == 0) ? -1 : bord[y][x];
            buff.vert[y][x] = (validBufferV[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
        }
}
int **GomokuAi::evaluteV(const type eval, evalRes &buff)
{
    int count = 0;

    prepV(eval, buff);
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            if(bordBufferV[y][x] == eval) {
                for (count = 0;y < size && bordBufferV[y][x] == eval ;  count++, y++);
                if ((y - count - 1) >= 0 &&  buff.vert[y - count - 1][x] != -1)
                    buff.vert[y - count - 1][x] += count;
                if (y < size &&  buff.vert[y][x] != -1)
                    buff.vert[y][x] += count;
            }
    return buff.vert;
}

void GomokuAi::prepTr(const type val, evalRes &buff)
{
    int oposite = (val == BLACK ? WHITE : BLACK);

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            validBufferTr[y][x] = 0;
    for (int x = size - 5 ; x >= 0; x--)
        for (int i = 0 ; x + i + 4 < size; i++)
            if ((bord[i][x + i] == FREE || bord[i][x + i] == val)
                && (bord[1 + i][x + 1 + i] == FREE || bord[1 + i][x + 1 + i] == val)
                && (bord[2 + i][x + 2 + i] == FREE || bord[2 + i][x + 2 + i] == val)
                && (bord[3 + i][x + 3 + i] == FREE || bord[3 + i][x + 3 + i] == val)
                && (bord[4 + i][x + 4 + i] == FREE || bord[4 + i][x + 4 + i] == val)) {
                    validBufferTr[i][x + i] = 1;
                    validBufferTr[1 + i][x + 1 + i] = 1;
                    validBufferTr[2 + i][x + 2 + i] = 1;
                    validBufferTr[3 + i][x + 3 + i] = 1;
                    validBufferTr[4 + i][x + 4 + i] = 1;
            }
    for (int y = 0 ; y < size - 4 ; y++)
        for (int i = 0 ; y + i + 4 < size; i++)
            if ((bord[y + i][i] == FREE || bord[y + i][i] == val)
                && (bord[y + 1 + i][1 + i] == FREE || bord[y + 1 + i][1 + i] == val)
                && (bord[y + 2 + i][2 + i] == FREE || bord[y + 2 + i][2 + i] == val)
                && (bord[y + 3 + i][3 + i] == FREE || bord[y + 3 + i][3 + i] == val)
                && (bord[y + 4 + i][4 + i] == FREE || bord[y + 4 + i][4 + i] == val)) {
                    validBufferTr[y + i][i] = 1;
                    validBufferTr[y + 1 + i][1 + i] = 1;
                    validBufferTr[y + 2 + i][2 + i] = 1;
                    validBufferTr[y + 3 + i][3 + i] = 1;
                    validBufferTr[y + 4 + i][4 + i] = 1;
                }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            bordBufferTr[y][x] = (validBufferTr[y][x] == 0) ? -1 : bord[y][x];
            buff.transr[y][x] = (validBufferTr[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
        }
}
int **GomokuAi::evaluteTr(const type val, evalRes &buff)
{
    int count = 0;

    prepTr(val, buff);
    for (int x = size - 5 ; x >= 0; x--)
        for (int i = 0 ; x + i < size; i++)
            if(bordBufferTr[i][x + i] ==  val) {
                for (count = 0;x + i < size && bordBufferTr[i][x + i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transr[(i - count - 1)][x + (i - count - 1)] != -1)
                    buff.transr[(i - count - 1)][x + (i - count - 1)] += count;
                if (i + x < size && buff.transr[i][i + x] != -1)
                    buff.transr[i][x + i] += count;
            }
    for (int y = 0 ; y < size - 4 ; y++)
        for (int i = 0 ; y + i < size; i++)
            if  (bordBufferTr[y + i][i] == val) {
                for (count = 0;y + i < size && bordBufferTr[y + i][i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transr[y + (i - count - 1)][(i - count - 1)] != -1)
                    buff.transr[(y + i - count - 1)][(i - count - 1)] += count;
                if (i + y < size && buff.transr[i + y][i] != -1)
                    buff.transr[y + i][i] += count;
            }
    return buff.transr;
}


void GomokuAi::prepTl(const type val, evalRes &buff)
{
    int oposite = (val == BLACK ? WHITE : BLACK);

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            validBufferTl[y][x] = 0;
    for (int x = 4; x < size; x++)
        for (int i = 0; x - i - 4  >= 0; i++)
             if ((bord[i][x - i] == FREE || bord[i][x - i] == val)
                && (bord[1 + i][x - 1 - i] == FREE || bord[1 + i][x - 1 - i] == val)
                && (bord[2 + i][x - 2 - i] == FREE || bord[2 + i][x - 2 - i] == val)
                && (bord[3 + i][x - 3 - i] == FREE || bord[3 + i][x - 3 - i] == val)
                && (bord[4 + i][x - 4 - i] == FREE || bord[4 + i][x - 4 - i] == val)) {
                    validBufferTl[i][x - i] = 1;
                    validBufferTl[1 + i][x - 1 - i] = 1;
                    validBufferTl[2 + i][x - 2 - i] = 1;
                    validBufferTl[3 + i][x - 3 - i] = 1;
                    validBufferTl[4 + i][x - 4 - i] = 1;
                }
    for (int y = 0; y < size - 4; y++) {
        for (int i = 0 ; (y + i + 4) < size && ((int)size - 4 - i) >= 0 ; i++)
            if ((bord[y + i][size -i -1] == FREE || bord[y + i][size -i -1] == val)
                && (bord[y + 1 + i][size - 1 - i - 1] == FREE || bord[y + 1 + i][size - 1 - i -1] == val)
                && (bord[y + 2 + i][size - 2 - i - 1] == FREE || bord[y + 2 + i][size - 2 - i -1] == val)
                && (bord[y + 3 + i][size - 3 - i - 1] == FREE || bord[y + 3 + i][size - 3 - i -1] == val)
                && (bord[y + 4 + i][size - 4 - i - 1] == FREE || bord[y + 4 + i][size - 4 - i -1] == val)) {
                    validBufferTl[y + i][size -i -1] = 1;
                    validBufferTl[y + 1 + i][size - 1 - i -1] = 1;
                    validBufferTl[y + 2 + i][size - 2 - i -1] = 1;
                    validBufferTl[y + 3 + i][size - 3 - i -1] = 1;
                    validBufferTl[y + 4 + i][size - 4 - i -1] = 1;
                }
    }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            bordBufferTl[y][x] = (validBufferTl[y][x] == 0) ? -1 : bord[y][x];
            buff.transl[y][x] = (validBufferTl[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
        }
}
int **GomokuAi::evaluteTl(const type val, evalRes &buff)
{
    int count = 0;

    prepTl(val, buff);
    for (int x = 4; x < size; x++)
        for (int i = 0; x - i >= 0; i++)
             if(bordBufferTl[i][x - i] ==  val) {
                for (count = 0; x - i >= 0 && bordBufferTl[i][x - i] == val; i++, count++);
                if ((i - count - 1) >= 0 && buff.transl[(i - count - 1)][x - (i - count - 1)] != -1)
                    buff.transl[(i - count - 1)][x - (i - count - 1)] += count;
                if (x - i >= 0 && buff.transl[i][x- i ] != -1)
                    buff.transl[i][x - i] += count;
            }
    for (int y = 0; y  < size - 4; y++)
        for (int i = 0 ; (y + i) < size && int(size - 1 - i) >= 0 ; i++)
            if ((bord[y + i][size - 1 - i] ==  val)) {
                for (count = 0; (y + i) < size && int(size - 1 - i) >= 0 && bordBufferTl[y + i][size - 1 - i] == val ; i++, count++);
                if (((i - count - 1) + y) < size && (int(size) - 1 - (i - count - 1)) >= 0 && buff.transl[y + (i - count - 1)][size - 1 - (i - count - 1)]  != -1)
                    buff.transl[y + (i - count - 1)][size - 1 - (i - count - 1)]  += count;
                if (y + i < size && (int(size - 1 - i) >= 0) && buff.transl[y + i][size - 1 - i] != -1)
                    buff.transl[y + i][size - 1 - i] += count;
            }
    return buff.transl;
}

int **GomokuAi::evalute(const type eval, int type)
{
    evalRes &buff = (eval == BLACK ? blackEval : whiteEval);

    if (type == 0)
        return evaluteH(eval, buff);
    if (type == 1)
        return evaluteV(eval, buff);
    if (type == 2)
        return evaluteTr(eval, buff);
    if (type == 3)
        return evaluteTl(eval, buff);
    return nullptr;
}

evalRes GomokuAi::evalute(const type eval)
{
    int count = 0;

    evalRes &buff = (eval == BLACK ? blackEval : whiteEval);
    prepBordBuffer(eval, buff);
    for (int y = 0; y < size; y++)
        for ( int x = 0 ; x < size; x++)
            if(bordBufferH[y][x] == eval) {
                for (count = 0; x < size && bordBufferH[y][x] == eval;  count++, x++);
                if ((x - count - 1) >= 0 && buff.horiz[y][x - count - 1] != -1)
                    buff.horiz[y][x - count - 1] += count;
                if (x < size && buff.horiz[y][x] != -1)
                    buff.horiz[y][x] += count;
            }
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            if(bordBufferV[y][x] == eval) {
                for (count = 0;y < size && bordBufferV[y][x] == eval ;  count++, y++);
                if ((y - count - 1) >= 0 &&  buff.vert[y - count - 1][x] != -1)
                    buff.vert[y - count - 1][x] += count;
                if (y < size &&  buff.vert[y][x] != -1)
                    buff.vert[y][x] += count;
            }
    tranversal(eval, buff);
    return buff;
}

GomokuAi::GomokuAi(int size) : Gomoku(size), blackEval(size), whiteEval(size)
{
    bordBufferTr = new int*[size];
    for (int i = 0; i < size; i++)
        bordBufferTr[i] = new int[size];
    bordBufferTl = new int*[size];
    for (int i = 0; i < size; i++)
        bordBufferTl[i] = new int[size];
    bordBufferH = new int*[size];
    for (int i = 0; i < size; i++)
        bordBufferH[i] = new int[size];
    bordBufferV = new int*[size];
    for (int i = 0; i < size; i++)
        bordBufferV[i] = new int[size];
    validBufferH = new int*[size];
    for (int i = 0; i < size; i++)
        validBufferH[i] = new int[size];
    validBufferV = new int*[size];
    for (int i = 0; i < size; i++)
        validBufferV[i] = new int[size];
    validBufferTl = new int*[size];
    for (int i = 0; i < size; i++)
        validBufferTl[i] = new int[size];
    validBufferTr = new int*[size];
    for (int i = 0; i < size; i++)
        validBufferTr[i] = new int[size];
}

void GomokuAi::prepBordBuffer(const type val, evalRes &buff)
{
    int oposite = (val == BLACK ? WHITE : BLACK);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++) {
            validBufferH[y][x] = 0;
            validBufferV[y][x] = 0;
            validBufferTr[y][x] = 0;
            validBufferTl[y][x] = 0;
        }
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size - 4; x++)
            if ((bord[y][x] == FREE || bord[y][x] == val)
                && (bord[y][x + 1] == FREE || bord[y][x + 1] == val)
                && (bord[y][x + 2] == FREE || bord[y][x + 2] == val)
                && (bord[y][x + 3] == FREE || bord[y][x + 3] == val)
                && (bord[y][x + 4] == FREE || bord[y][x + 4] == val) ){
                validBufferH[y][x] = 1;
                validBufferH[y][x + 1] = 1;
                validBufferH[y][x + 2] = 1;
                validBufferH[y][x + 3] = 1;
                validBufferH[y][x + 4] = 1;
            }
    for (int y = 0; y < size - 4; y++)
        for (int x = 0; x < size; x++)
            if ((bord[y][x] == FREE || bord[y][x] == val)
                && (bord[y + 1][x] == FREE || bord[y + 1][x] == val)
                && (bord[y + 2][x] == FREE || bord[y + 2][x] == val)
                && (bord[y + 3][x] == FREE || bord[y + 3][x] == val)
                && (bord[y + 4][x] == FREE || bord[y + 4][x] == val)) {
                validBufferV[y][x] = 1;
                validBufferV[y + 1][x] = 1;
                validBufferV[y + 2][x] = 1;
                validBufferV[y + 3][x] = 1;
                validBufferV[y + 4][x] = 1;
            }
    tranversalprep(val);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size ; x++) {
            bordBufferH[y][x] = (validBufferH[y][x] == 0) ? -1 : bord[y][x];
            bordBufferV[y][x] = (validBufferV[y][x] == 0) ? -1 : bord[y][x];
            bordBufferTl[y][x] = (validBufferTl[y][x] == 0) ? -1 : bord[y][x];
            bordBufferTr[y][x] = (validBufferTr[y][x] == 0) ? -1 : bord[y][x];
            buff.horiz[y][x] = (validBufferH[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
            buff.vert[y][x] = (validBufferV[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
            buff.transl[y][x] = (validBufferTl[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
            buff.transr[y][x] = (validBufferTr[y][x] == 0) ? -1 : (bord[y][x] == oposite ? -1 : 0);
        }
}

GomokuAi::~GomokuAi()
{
    deleteAAInt(bordBufferH, size);
    deleteAAInt(bordBufferV, size);
    deleteAAInt(bordBufferTr, size);
    deleteAAInt(bordBufferTl, size);
    deleteAAInt(validBufferH, size);
    deleteAAInt(validBufferV, size);
    deleteAAInt(validBufferTl, size);
    deleteAAInt(validBufferTr, size);
}
