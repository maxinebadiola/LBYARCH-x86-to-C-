#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

clock_t start, end;
double executionTime;
extern float dotProduct64(int n, float sdot, float* A, float* B);

//generate set vectors [1,2,3,4...]
void fillTest(float vectorA[], float vectorB[], int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        vectorA[i] = (float)(i + 1);
        vectorB[i] = (float)(i + 1);
    }
}
// n = vector size, sdot = output, 
float dotProductC(int n, float sdot, float A[], float B[]) {
    start = clock();
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    end = clock();
    executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("n = %d, sdot = %.2f, t = %f\n", n, sdot, executionTime);
    return sdot;
}

int main() {
    //2^20, 2^24, 2^30
    int sizes[] = { 1048576 , 16777216, 1073741824 };
    //stores execution time for each function
    double timeC[90];
    double time64[90];
    double totalC = 0.0;
    double total64 = 0.0;
    boolean noErrors = 1;

    for (int i = 0; i < 3; i++)
    {
        int n = sizes[i];
        float* A = malloc(n * sizeof(float));
        float* B = malloc(n * sizeof(float));
        fillTest(A, B, n);

        for (int j = 0; j < 30; j++) {
            //sdotC
            float sdotC = dotProductC(n, 0.0f, A, B, timeC, j);
            totalC += timeC[j];

            //sdot64
            // start = clock();
            // float sdot64 = dotProduct64(n, 0.0f, A, B);
            // end = clock();
            // time64[j] = ((double)(end - start)) / CLOCKS_PER_SEC;
            // total64 += time64[j];

            // printf("n = %d, sdot64 = %.2f, t = %f\n", n, sdot64, time64[j]);

            // //compare sdotC and sdot64
            // if (sdotC != sdot64) {
            //     printf("ERROR: mismatch at iteration %d: sdotC = %f, sdot64 = %f\n", j, sdotC, sdot64);
            //     noErrors = 0;
            // }
            // else
            //     printf("VALID: match at iteration %d: sdotC = %f, sdot64 = %f\n", j, sdotC, sdot64);
        }
    }

    //PRINT AVERAGE (3 values of n, 30 times each = 90 total times)
    double averageC = totalC / 90;
    double average64 = total64 / 90;
    printf("\n============================================================\n");
    printf("Test run is %s\n", noErrors == 1 ? "VALID" : "INVALID");
    printf("Average execution time in C: %f\n", averageC);
    printf("Average execution time in 64: %f\n", average64);
    printf("============================================================\n");

    return 0;
}

