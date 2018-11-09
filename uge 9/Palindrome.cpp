#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool recursiveVectorComparison(vector<int> a, vector<int> b, int index){
	if(index < a.size() && index < b.size()){
		if(a.at(index) == b.at(index)){
			return recursiveVectorComparison(a, b, index+1);
		} else{
			return false;
		}
	} else{
		return true;
	}
}

int main() {
  vector<int> data_storage;
  vector<int> reverse_data_storage;
  
  string cin_buffer_data = "";
  getline(cin, cin_buffer_data);

  stringstream stream(cin_buffer_data);
  while(1){
	  int value;
	  stream >> value;
	  if(!stream){
		  break;
	  }
	  data_storage.push_back(value);
  }
  for(int i = data_storage.size()-1; i >= 0; i--){
	reverse_data_storage.push_back(data_storage.at(i));
  }
  if(recursiveVectorComparison(data_storage, reverse_data_storage, 0)){
	  cout << "yes";
  } else{
	  cout << "no";
  }
}

