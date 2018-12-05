#include "ex02-library.h"
#include <iostream>

//Do not modify
void printSet(set<string> s){
  if(s.size()==0){
    cout << " No nodes\n";
  }
  else{
    set<string>::iterator it;
    for (it=s.begin(); it!=s.end(); ++it){
      cout << ' ' << *it << "\n";
    }
  }
  cout << "\n";
}

//Exercise 2 (a) Check and correct if necessary
void computeParentNodes(Node *n, set<string> & parents){
  if(n->left != nullptr || n->right != nullptr){
    parents.insert(n->name);
  }
  if(n->left != nullptr){
    computeParentNodes(n->left,parents);
  }
  if(n->right != nullptr){
    computeParentNodes(n->right,parents);
  }

}

void recursiveComputationOfSubTree(Node * n, set<string> & members){
  if(n->left != nullptr){
    members.insert(n->left->name);
  }
  if(n->right != nullptr){
    members.insert(n->right->name);
  }
  if(n->left != nullptr){
    recursiveComputationOfSubTree(n->left, members);
  }
  if(n->right != nullptr){
    recursiveComputationOfSubTree(n->right, members);
  }
}

//Exercise 2 (b) Implement this function
void computeMembersOfSubTree(Node * n, set<string> & members){
  members.insert(n->name);
  recursiveComputationOfSubTree(n, members);
}
