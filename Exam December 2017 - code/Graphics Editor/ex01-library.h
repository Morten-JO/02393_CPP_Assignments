#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_
#include <vector>
#include <string>
using namespace std;
int ** createMatrix(unsigned int n, unsigned int m);
int ** duplicateMatrix(int ** A, unsigned int n, unsigned int m);
void initMatrix(int ** A, unsigned int n, unsigned int m);
void deallocateMatrix(int ** A, unsigned int n);
int ** makeBitonal(int ** A, unsigned int n, unsigned int m,
int threshold);
void printMatrix(int ** A, unsigned int n, unsigned int m,
string description);
#endif /* EX01_LIBRARY_H_ */