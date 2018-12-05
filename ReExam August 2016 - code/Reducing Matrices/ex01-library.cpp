#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double * * A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double * * A, unsigned int n, double x){
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < n; j++){
      A[i][j] = x;
    }
  }
}

// Exercise 1 (c)
// Implement this function
vector<double> sumRows(double * * A, unsigned int n){
  vector<double> values;
  for(unsigned int i = 0; i < n; i++){
    double tempValue = 0.0;
    for(unsigned int j = 0; j < n; j++){
      tempValue = tempValue + A[i][j];
    }
    values.push_back(tempValue);
  }
  return values;
}

// Exercise 1 (d)
// Implement this function
vector<double> sumCols(double * * A, unsigned int n){
    vector<double> values;
    for(unsigned int i = 0; i < n; i++){
      double tempValue = 0.0;
      for(unsigned int j = 0; j < n; j++){
        tempValue = tempValue + A[j][i];
      }
      values.push_back(tempValue);
    }
    return values;
}

// Exercise 1 (e)
// Implement this function
void reduce(double * * A, unsigned int n){
  double * * newArray = new double *[n];
  for(unsigned int i = 0; i<n; i++){
      newArray[i] = new double[n];
  }
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < n; j++){
      double leftValue = 0.0;
      double rightValue = 0.0;
      double downValue = 0.0;
      double upValue = 0.0;
      if(((int)j)-1 >= 0){
        leftValue = A[i][j-1];
      }
      if(((int)j)+1 < n){
        rightValue = A[i][j+1];
      }
      if(((int)i)-1 >= 0){
        upValue = A[i-1][j];
      }
      if(((int)i)+1 < n){
        downValue = A[i+1][j];
      }
      double totalValue = leftValue + rightValue + downValue + upValue;
      newArray[i][j] = totalValue;
    }
  }
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < n; j++){
      A[i*n+j] = newArray[i*n+j];
    }
  }
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
