#include <iostream>
#include <string>
#include <set>
std::multiset<double> setOfIntegers;
using namespace std;
void queryBag(double number){
    if(setOfIntegers.find(number) != setOfIntegers.end()){
        cout << "T";
    } else{
        cout << "F";    
    }
}

void addToBag(double number){
    setOfIntegers.insert(number);
}

void deleteNumberInBag(double number){
    int count = setOfIntegers.count(number);
    setOfIntegers.erase(number);
    if(count > 1){
        for(int i = 0; i < count-1; i++){
            setOfIntegers.insert(number);    
        }
    }
    
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
            double numberInput;
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
