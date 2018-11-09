  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <math.h>

  using namespace std;

  class fraction {
    public:
    int numerator;
    int denominator;
    // Class constructor
    fraction(int n, int d){
      numerator = n;
      denominator = d;
    }
    // Methods to update the fraction
    void add(fraction f){
      if(denominator != f.denominator){
        int new_denominator = denominator * f.denominator;
        int new_numerator = numerator * f.denominator;
        //int new_denominator_f = f.denominator * denominator;
        int new_numerator_f = f.numerator * denominator;
        numerator = new_numerator + new_numerator_f;
        denominator = new_denominator;
      } else{
        numerator = numerator + f.numerator;
      }
    }
    void mult(fraction f){
      numerator = numerator * f.numerator;
      denominator = denominator * f.denominator;
    }
    void div(fraction f){
      int new_num_f = f.denominator;
      int new_den_f = f.numerator;
      numerator = numerator * new_num_f;
      denominator = denominator * new_den_f;
    }
    // Display method
    void display(void){
      bool canSimplify = true;
      int simplifyFraccer = 2;
      while(canSimplify){
        if(numerator % simplifyFraccer == 0 && denominator % simplifyFraccer == 0){
          numerator = numerator / simplifyFraccer;
          denominator = denominator / simplifyFraccer;
        } else{
          simplifyFraccer = simplifyFraccer + 1;
        }
        if(simplifyFraccer > numerator || simplifyFraccer > denominator){
          canSimplify = false;
        }
      }
      cout << numerator << " / " << denominator << "\n";
    }
  };


  int main() {
    for (size_t i = 0; i < 3; i++) {
      int value_1;
      cin >> value_1;
      string we = "";
      cin >> we;
      int value_2;
      cin >> value_2;
      string typeCalculation = "";
      cin >> typeCalculation;
      int value_3;
      cin >> value_3;
      cin >> we;
      int value_4;
      cin >> value_4;

      fraction frac_left (value_1, value_2);
      fraction frac_right (value_3, value_4);
      if(typeCalculation == "+") {
        frac_left.add(frac_right);
      } else if(typeCalculation == "*"){
        frac_left.mult(frac_right);
      } else if(typeCalculation == "div"){
        frac_left.div(frac_right);
      }
      frac_left.display();
}
  }
