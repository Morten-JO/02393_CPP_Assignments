#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class FibonacciNode {
	public:
		FibonacciNode(int num){
			number = new int(num);
		}
		int* number;
		int* value;
		FibonacciNode* left;
		FibonacciNode* right;
		
		
		
		void callTree(){
			int tempValue = *(this->value);
			cout << " " << tempValue;
			FibonacciNode * tempNode = left;
			if(tempNode != NULL){
				left->callTree();
			}
			FibonacciNode * tempRightNode = right;
			if(tempRightNode != NULL){
				right->callTree();
			}
		}
		
		int treeSize(){
			int leftValue = 0;
			int rightValue = 0;
			if(this->left != NULL){
				leftValue = this->left->treeSize();
			}
			if(this->right != NULL){
				rightValue = this->right->treeSize();
			}
			return leftValue + rightValue + 1;
		}
		
		int depth(){
			int leftValue = 0;
			if(this->left != NULL){
				leftValue = this->left->depth();
			}
			return leftValue + 1;
		}
		
		int leafs(){
			int leafs = 0;
			if(this->left == NULL && this->right == NULL){
				leafs = 1;;
			} else {
				if(this->left != NULL){
					leafs += this->left->leafs();
				}
				if(this->right != NULL){
					leafs += this->right->leafs();
				}
			}
			
			return leafs;
		}
};

FibonacciNode* calculateFibonacciValue(int number){
	int n = number;
	FibonacciNode* toReturn = new FibonacciNode(number);
	if(n == 0 ||n == 1){
		toReturn->value = new int(1);
		toReturn->left = NULL;
		toReturn->right = NULL;
	} else{
		toReturn->left = (calculateFibonacciValue(n-1));
		toReturn->right = (calculateFibonacciValue(n-2));
		int tempVal = *(toReturn->left->value) + *(toReturn->right->value);
		toReturn->value = new int(tempVal);
	}
	return toReturn;
}



int main() {
	int inputNumber;
	cin >> inputNumber;
	FibonacciNode* node = calculateFibonacciValue(inputNumber);
	cout << "Call tree in pre-order:";
	node->callTree();
	cout << "\n";
	cout << "Call tree size: " << node->treeSize() << "\n";
	cout << "Call tree depth: " << node->depth() << "\n";
	cout << "Call tree leafs: " << node->leafs() << "\n";
	
	
}

