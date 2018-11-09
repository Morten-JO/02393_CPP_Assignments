#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int recursiveFibonacciAdding(int values [], int target_index, int current_index){
	int value = 0;
	for(int i = 0; i < 2; i++){
		value += values[i];
	}
	if(current_index == target_index){
		return value;
	} else{
		int new_values [2];
		new_values[0] = values[1];
		new_values[1] = value;
		return recursiveFibonacciAdding(new_values, target_index, current_index +1);
	}
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
  for(int i = 0; i < data_storage.size(); i++){
	  int index_number = data_storage.at(i);
	  int fib_value;
	  if(index_number <= 1){
		  fib_value = 1;
	  } else{
		  int value_array [2] = {1, 1}; 
		  fib_value = recursiveFibonacciAdding(value_array, index_number, 2);
	  }
	  cout << fib_value << " ";
  }
}

