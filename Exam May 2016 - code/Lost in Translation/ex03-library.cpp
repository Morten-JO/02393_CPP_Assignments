#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
Dictionary::Dictionary(void){
  //words
  map<string, string> map1;
  map<string, string> map2;
  words.push_back(map1);
  words.push_back(map2);
  //synonyms
  map<string,set<string>> map3;
  map<string,set<string>> map4;
  synonyms.push_back(map3);
  synonyms.push_back(map4);
}

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
  words[0][u] = v;
  words[1][v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(int lang, string u){
  if(lang < 0 || lang > 1){
    return "";
  } else{
    return words[lang][u];
  }
}

// Exercise 3(c)
void Dictionary::insert_synonym(int lang, string u,string v){
    if(lang < 0 || lang > 1){
      return;
    }
    synonyms[lang][u].insert(v);
    synonyms[lang][v].insert(u);
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(int lang, string u){
  if(lang < 0 || lang > 1){
    set<string> emptySet;
    return emptySet;
  } else{
    return synonyms[lang][u];
  }
}

// Exercise 3(e)
set<string> Dictionary::translate(int lang, string u){
    set<string> returnSet;
    if(words[lang].find(u) != words[lang].end()){
      string translatedWord = get_word(lang, u);
      returnSet.insert(translatedWord);
      int translatedLang = 0;
      if(lang == 0){
        translatedLang = 1;
      }
      set<string> translationSet = get_synonyms(translatedLang, translatedWord);
      for(set<string>::iterator it = translationSet.begin(); it != translationSet.end(); it++){
        returnSet.insert(*it);
      }
      set<string> synonymSet = get_synonyms(lang, u);
      for(set<string>::iterator it = synonymSet.begin(); it != synonymSet.end(); it++){
        string value = *it;
        string translatedValue = words[lang][value];
        returnSet.insert(translatedValue);
        set<string> translationOfSynonymSet = get_synonyms(translatedLang, translatedValue);
        for(set<string>::iterator ita = translationOfSynonymSet.begin(); ita != translationOfSynonymSet.end(); ita++){
          returnSet.insert(*ita);
        }
      }
    }

    //1. translate
    //2. synonym of tranlated
    //3. synonym of original word
    //4. translation

    return returnSet;
}
