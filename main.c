#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265359

int count = 10000;
float pi = 0.0;
float term;

int main(int argc, char* argv[]){
    clock_t start_time = clock();

    if(argc == 2){
        count = atoi(argv[1]);
    }
    // π/4 = Σ((-1)^(n+1) / (2n-1))
    for(int i = 0; i < count; i++){
        term = (i % 2 == 0) ? 1.0 / (2 * i + 1) : -1.0 / (2 * i + 1);
        pi += term;
        int barWidth = 40;
        int filledWidth = (i * barWidth) / count;
        int emptyWidth = barWidth - filledWidth;
        printf("[Current aproximation] %.5f", 4*pi);
        char* buffer[filledWidth + 1];
        memset(buffer, '=', filledWidth);
        buffer[filledWidth] = 0;

        char* buffer1[emptyWidth + 1];
        memset(buffer1, '-', emptyWidth);
        buffer1[emptyWidth] = 0;

        printf("[%s%s] %d%% iteration: %d                                                    \r", buffer, buffer1, (i * 100) / count, i);

    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double iterations_per_second = count / elapsed_time;

    printf("[Final aproximation] %.100f\n(for %d iterations)\n", 4*pi, count);
    printf("[Actual pi] %f\n", PI);
    printf("[Iterations per second] %.2f\n", iterations_per_second);

    return 0;
}