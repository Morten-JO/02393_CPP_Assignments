#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double *A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i*n+j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double *A, unsigned int n, double x){
    for(unsigned int i = 0; i < n*n; i++){
      A[i] = x;
    }
}

// Exercise 1 (c)
// Implement this function
void reduce(double * A, unsigned int n){
  double * newArray = new double[n*n];
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < n; j++){
      int leftIndex = (int)(i*n+j-1);
      int rightIndex = (int)(i*n+j+1);
      int downIndex = (int)((i+1)*n+j);
      int upIndex = (int)((i-1)*n+j);
      double leftValue = 0.0;
      double rightValue = 0.0;
      double downValue = 0.0;
      double upValue = 0.0;
      if(((int)j)-1 >= 0){
        leftValue = A[leftIndex];
      }
      if(((int)j)+1 < n){
        rightValue = A[rightIndex];
      }
      if(((int)i)-1 >= 0){
        upValue = A[upIndex];
      }
      if(((int)i)+1 < n){
        downValue = A[downIndex];
      }
      double totalValue = leftValue + rightValue + downValue + upValue;
      newArray[i*n+j] = totalValue;
    }
  }
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < n; j++){
      A[i*n+j] = newArray[i*n+j];
    }
  }
}

// Exercise 1 (d)
// Implement this function
vector<double> sumRows(double * A, unsigned int n){
  vector<double> returnVector;
  for(unsigned int i = 0; i < n; i++){
    double value = 0;
    for(unsigned int j = 0; j < n; j++){
      value = value + A[i*n+j];
    }
    returnVector.push_back(value);
  }
  return returnVector;
}

// Exercise 1 (e)
// Implement this function
vector<double> sumCols(double * A, unsigned int n){
  vector<double> returnVector;
  for(unsigned int i = 0; i < n; i++){
    double value = 0;
    for(unsigned int j = 0; j < n; j++){
      value = value + A[i+j*n];
    }
    returnVector.push_back(value);
  }
  return returnVector;
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
