#include "Interface.hpp"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void my_handler([[maybe_unused]] int s)
{
    exit(0);
}

int main()
{
    signal (SIGINT, my_handler);
    Interface i;
    while (true)
        i.ParseCmd();
    return 0;
}
