#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  vector<int> a_data_storage;
  vector<int> b_data_storage;

  string cin_buffer_data = "";
  getline(cin, cin_buffer_data);

  for (int i = 0; i < cin_buffer_data.length(); i++) {
    int proper_index =  i + 2;
  	if (cin_buffer_data[i] == 'b') {
  		int value = cin_buffer_data[proper_index] - '0';
  		b_data_storage.push_back(value);
  	} else if (cin_buffer_data[i] == 'a') {
  		  int value = cin_buffer_data[proper_index] - '0';
  			a_data_storage.push_back(value);
  	}
  }

  int count = 0;
  int count_value = 0;
  while(count < a_data_storage.size() && count < b_data_storage.size()){
    count_value = count_value + a_data_storage.at(count) * b_data_storage.at(count);
    count = count + 1;
  }

cout << count_value;
  
}
