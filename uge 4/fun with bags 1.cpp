#include <iostream>
#include <string>
#include <set>
std::set<int> setOfIntegers;
using namespace std;
void queryBag(int number){
    if(setOfIntegers.find(number) != setOfIntegers.end()){
        cout << "T";
    } else{
        cout << "F";    
    }
}

void addToBag(int number){
    setOfIntegers.insert(number);
}

void deleteNumberInBag(int number){
    setOfIntegers.erase(number);
}


int main()
{
    
    bool running = true;
    while(running){
        string textinput = "";
        cin >> textinput;
        if(textinput == "quit"){
            running = false;
        } else{
            int numberInput;
            cin >> numberInput;
            if(textinput == "add"){
                addToBag(numberInput);    
            } else if(textinput == "del"){
                deleteNumberInBag(numberInput);    
            } else if(textinput == "qry"){
                queryBag(numberInput);    
            }
        }
    }
}
