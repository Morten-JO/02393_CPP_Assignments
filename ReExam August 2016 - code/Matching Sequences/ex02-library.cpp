#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

// Exercise 2
vector<string> match(vector<string> & u, vector<string> & v){
    vector<string> returnVector;
    if(u.empty() || v.empty()){
      return returnVector;
    }
    if(u[u.size()-1] == v[v.size()-1]){
      vector<string> subVectorU(u.begin(), u.end()-1);
      vector<string> subVectorV(v.begin(), v.end()-1);
      returnVector = match(subVectorU, subVectorV);
      returnVector.push_back(u[u.size()-1]);
      return returnVector;
    }
    vector<string> subVectorV(v.begin(), v.end()-1);
    vector<string> subVectorU(u.begin(), u.end()-1);
    if(match(u, subVectorV).size() >= match(subVectorU, v).size()){
      returnVector = match(u, subVectorV);
    } else{
      returnVector = match(subVectorU, v);
    }
    return returnVector;
}

// Do not modify
vector<string> read_until(string stop){
    vector<string> u;
    string e;
    while(true){
        cin >> e;
        if(cin.fail() || e == stop) break;
        u.push_back(e);
    }
    return u;
}

// Do not modify
void display(vector<string> & u){
    for(unsigned int i=0; i<u.size(); i++)
        cout << u[i] << " " ;
    cout << endl;
}
