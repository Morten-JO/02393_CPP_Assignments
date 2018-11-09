#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void recursivePrint(vector<int> data_storage, int current_index){
	if(data_storage.size() > current_index+1){
		recursivePrint(data_storage, current_index + 1);
	}
	if(current_index != data_storage.size() - 1){
		cout << " ";
	}
	cout << data_storage.at(current_index);
}

int main() {
  vector<int> data_storage;

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
  if(data_storage.size() > 0){
	  recursivePrint(data_storage, 0);
  }  
}

