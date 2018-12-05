#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int ** createMatrix(unsigned int n, unsigned int m){
    int** array = new int*[(int)n];
    for(int i = 0; i < (int)n; ++i){
        array[i] = new int[(int)m];
    }
    return array;
}

int ** duplicateMatrix(int ** A, unsigned int n, unsigned int m){
    int** array = new int*[(int)n];
    for(int i = 0; i < (int)n; i++){
        array[i] = new int[(int)m];
     for(int j = 0; j < (int)m; j++){
        array[i][j] = A[i][j];
     }
    }
    return array;
}

void initMatrix(int ** A, unsigned int n, unsigned int m){
    for(int i = 0; i < (int)n; i++){
     for(int j = 0; j < (int)m; j++){
      A[i][j] = *(new int(0));
     }
    }
}

void deallocateMatrix(int ** A, unsigned int n){
 for(int i = 0; i < (int) n; i++){
    delete[] A[i];
 }
 delete [] A;
}

int ** makeBitonal(int ** A, unsigned int n, unsigned int m,
int threshold){
    int** array = new int*[(int)n];
    for(int i = 0; i < (int)n; i++){
        array[i] = new int[(int)m];
        for(int j = 0; j < (int)m; j++){
            if(A[i][j] < threshold){
                array[i][j] = *(new int(0));
            } else{
                array[i][j] = *(new int(255));
            }
        }
    }
    return array;
}

void printMatrix(int ** A, unsigned int n, unsigned int m, string description){
    cout<< "Printing: " << description << endl;
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < m; j++){
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }
}