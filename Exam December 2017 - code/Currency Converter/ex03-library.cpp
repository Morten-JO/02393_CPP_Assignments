#include <iostream>
#include "ex03-library.h"

//Do not modify
CurrencyConverter::CurrencyConverter() {
  currencies.insert("DKK");
  currencyToExchangeRate["DKK"]=1;
}

//Do not modify
bool CurrencyConverter::supportsCurrency(string currencyCode){
  if(currencies.find(currencyCode) != currencies.end()){
    //I have the currency.
    return true;
  }
  else{
    return false;
  }
}

//Exercise 3 (a) Check and correct if necessary
void CurrencyConverter::print(){
  cout << "The converter supports the following currencies:"<<endl;
  for (map<string,double>::iterator it=currencyToExchangeRate.begin(); it!=currencyToExchangeRate.end(); ++it){
    cout << ' '<< "currency " << it->first << " has exchange rate " << it->second  << endl;
  }
}

//Exercise 3 (b) Check and correct if necessary
bool CurrencyConverter::addCurrency(string currencyCode,double exchangeRateToDKK) {
  if(supportsCurrency(currencyCode)){
    //I already have this element. Hence I return false
    return false;
  }
  else if(exchangeRateToDKK <= 0.0){
    //Exchange rates must be positive
    return false;
  }
  else{
    currencies.insert(currencyCode);
    currencyToExchangeRate.insert(pair<string, double>(currencyCode, exchangeRateToDKK));
    return true;
  }
}

//Exercise 3 (c) Implement this function
bool CurrencyConverter::updateExchangeRate(string currencyCode,double newExchangeRate) {
  if(!supportsCurrency(currencyCode)){
    return false;
  } else if(newExchangeRate <= 0.0){
    return false;
  } else if(currencyCode == "DKK"){
    return false;
  } else {
    currencyToExchangeRate[currencyCode] = newExchangeRate;
  }
  return true;
}

//Exercise 3 (d) Implement this function
double CurrencyConverter::convertToDKK(double amount, string currencyCodeOfSource) {
  if(!supportsCurrency(currencyCodeOfSource) || amount <= 0.0){
    return -1;
  }
  double amountInDKK = amount * currencyToExchangeRate[currencyCodeOfSource];
  return amountInDKK;
}

//Exercise 3 (e) Implement this function
double CurrencyConverter::convertFromDKK(double amountDKK,string currencyCodeOfTarget) {
  if(!supportsCurrency(currencyCodeOfTarget) || amountDKK <= 0.0){
    return -1;
  }
  double amountInCustomCurrency = amountDKK / currencyToExchangeRate[currencyCodeOfTarget];
  return amountInCustomCurrency;
}
