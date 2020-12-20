#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <cufft.h>
#include <math.h>

/* Sampling window */
#define MAX_THREADS 512 

/* Constants */
#define PI 3.14


/* file data input */
FILE *input  = fopen(/*change directory*/, "r");
           
          if (in_file == NULL) 
            {   
              printf("Could not open file\n"); 
              exit(-1)
            } 
           

void magn(cuDoubleComplex *FILE) {
    int ind = threadIdx.x + MAX_THREADS*blockIdx.x;
    FILE[ind].x = sqrt(FILE[ind].x * FILE[ind].x + FILE
}


void Maximum(cuDoubleComplex *FILE, long signalLength) {
    FILE[0].y = 0;
    
    int i;
    for (i = 0; i < signalLength; i++) {
        if (FILE[i].x > FILE[0].y) {
            FILE[0].y = FILE[i].x;
        }
    }
}

void calculate(long signalLength) {
    cuDoubleComplex *d_FILE;
    cufftHandle p_line;
    
    dim3 blocksParallel(ceil(((double)signalLength)/((double)MAX_THREADS)), 1, 1);
    dim3 threadsParallel(MAX_THREADS, 1, 1);
   
    dim3 blocksSequential(1, 1, 1);
    dim3 threadsSequential(1, 1, 1);
    
    host_matrix = (cuDoubleComplex *) malloc(sizeof(cuDoubleComplex) * signalLength);

    cudaMalloc((void**) &d_FILE, sizeof(cuDoubleComplex) * signalLength);
    cudaMemcpy(d_FILE, host_matrix, sizeof(cuDoubleComplex)*signalLength, cudaMemcpyHostToDevice);
    cufftPlan3d(&p_line, signalLength, 1, 1, CUFFT_Z2Z);
    cufftExecZ2Z(p_line, d_FILE, d_FILE, CUFFT_FORWARD);
    cudaThreadSynchronize();
    
    cudaMemcpy(host_matrix, d_FILE, sizeof(cuDoubleComplex) * signalLength, cudaMemcpyDeviceToHost);
    cufftDestroy(p_line);
    cudaFree(d_FILE);
    free(host_matrix);
}


int main() {

    long numIterations = 500;
    long signalLength = value;

    for (signalLength = 1; signalLength <= 4096; signalLength++) {
        if (signalLength <= 128) {
            for (iteration = 0; iteration < numIterations; iteration++) {

                vector_iter[iteration] = transform(signalLength);
            }
        }
}