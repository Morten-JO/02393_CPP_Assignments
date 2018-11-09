#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  vector<int> a_data_storage;
  vector<int> b_data_storage;

  cin.clear();
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

  sort(a_data_storage.begin(), a_data_storage.end());
  sort(b_data_storage.begin(), b_data_storage.end());

  for (int i = 0; i < a_data_storage.size(); i++) {
    cout << a_data_storage.at(i) << " ";
  }

  for (int i = 0; i < b_data_storage.size(); i++) {
  	cout << b_data_storage.at(i) << " ";
  }
}

