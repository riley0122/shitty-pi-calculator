#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int i = 0;
float pi = 0.0;
float term;
int ending = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows method
    #else
        printf("\033[2J\033[1;1H");  // Unix/Linux method
    #endif
}

void end(){
    ending = 1;
    printf("\n");
    exit(0);
}

int main(){
    signal(SIGINT, end);

    while (!ending)
    {
        term = (i % 2 == 0) ? 1.0 / (2 * i + 1) : -1.0 / (2 * i + 1);
        pi += term;
        printf("%.100f @ %d\r", 4 * pi, i);
        i++;
    }

    return 0;
}