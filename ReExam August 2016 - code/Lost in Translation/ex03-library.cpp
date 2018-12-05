#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    english2danish[u] = v;
    danish2english[v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(string lang, string u){
    if(lang == "english" && english2danish.find(u) != english2danish.end()){
      return english2danish[u];
    }
    if(lang == "danish"&& danish2english.find(u) != danish2english.end()){
      return danish2english[u];
    }
    return "#unknown#";
}

// Exercise 3(c)
void Dictionary::insert_synonym(string lang, string u, string v){
    if(lang == "danish"){
      danish_synonyms[u].insert(v);
      danish_synonyms[v].insert(u);
    }

    if(lang == "english"){
      english_synonyms[u].insert(v);
      english_synonyms[v].insert(u);
    }
    return;
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(string lang, string u){
    if(lang == "english"){
      return english_synonyms[u];
    }
    if(lang == "danish"){
      return danish_synonyms[u];
    }
    return set<string>();
}

// Exercise 3(e)
set<string> Dictionary::translate(string lang, string u){
    set<string> se;
    if(lang=="english"){
      string s = english2danish[u];
      se = danish_synonyms[s];
      se.insert(s);
    }

    if(lang=="danish"){
      string s = danish2english[u];
      se = english_synonyms[s];
      se.insert(s);
    }
    return se;
}
