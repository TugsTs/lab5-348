#include <stdio.h>

//size def
#define SIZE 5
//function defnitions
//takes in matrix as input and outputs a user friendly representation
void printMatrix(int matrix[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0;j<SIZE;j++){
            printf("%4d ",matrix[i][j]);
        }
        
        printf("\n");
    }
}
void MultiplyMatrices(int mtrx1[SIZE][SIZE], int mtrx2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            result[i][j] = 0;
            //mutiply row of m1 with column of m2
            for(int k=0;k<SIZE;k++){
                result[i][j] += mtrx1[i][k]*mtrx2[k][j];
            }
        }
    }
}
void addMatrices(int mtrx1[SIZE][SIZE], int mtrx2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
         for(int j=0;j<SIZE;j++){
            result[i][j] = mtrx1[i][j]+ mtrx2[i][j];
        }
    }
}


void transposeMatrix(int matrix[SIZE][SIZE],int result[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        // (row,col) to (col,row)
        for(int j=0;j<SIZE;j++){
            result[j][i] = matrix[i][j];
        }
    }
}


//main function and given matrix sizes
int main(){
    //5x5 matrixes given to us
    int mtrx1[SIZE][SIZE]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int mtrx2[SIZE][SIZE] ={
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
    };
    //define the size of our result matrix
    int result[SIZE][SIZE];
    //print our results following the given output format and defined printmatrix func
    

    addMatrices(mtrx1,mtrx2,result);
    printf("\nmatrix 1 and 2 add result:\n");
    printMatrix(result);

    MultiplyMatrices(mtrx1,mtrx2,result);
    printf("\nMatrix 1 and 2 multiplication result:\n");
    printMatrix(result);

    transposeMatrix(mtrx2,result);
    printf("\nTranspose of matrix 2 result:\n");
    printMatrix(result);
    
    printf("Given Matrix 1:\n");
    printMatrix(mtrx1);

    printf("\nGiven Matrix 2:\n");
    printMatrix(mtrx2);
    return 0;
}