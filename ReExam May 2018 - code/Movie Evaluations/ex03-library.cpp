#include <iostream>
#include "ex03-library.h"

//Do not modify
MovieEvaluations::MovieEvaluations() {
  movies.insert("The Godfather");
  movieToEvaluation["The Godfather"]=10;
}

//Do not modify
bool MovieEvaluations::hasEvaluation(string movie){
  if(movies.find(movie) != movies.end()){
    //I have an evaluation for the movie
    return true;
  }
  else{
    return false;
  }
}

//Exercise 3 (a) Check and correct if necessary
void MovieEvaluations::print(){
  cout << "I have the following evaluations:"<<endl;
  for (map<string,double>::iterator it=movieToEvaluation.begin(); it!=movieToEvaluation.end(); ++it){
      cout << ' '<< "movie " << it->first  << " has evaluation " << it->second << endl;
  }
}

//Exercise 3 (b) Implement this function
bool MovieEvaluations::addEvaluation(string movie,double evaluation) {
  if(hasEvaluation(movie)){
    return false;
  } else if(evaluation < 0.0 || evaluation > 10.0){
    return false;
  } else{
    movies.insert(movie);
    movieToEvaluation[movie] = evaluation;
    return true;
  }
}

//Exercise 3 (c) Implement this function
bool MovieEvaluations::updateEvaluation(string movie,double newEvaluation) {
  if(!hasEvaluation(movie)){
    return false;
  } else if(newEvaluation < 0.0 || newEvaluation > 10.0){
    return false;
  } else{
    movieToEvaluation[movie] = newEvaluation;
    return true;
  }
}

//Exercise 3 (d) Implement this function
string MovieEvaluations::computeVerboseEvaluation(string movie) {
  if(!hasEvaluation(movie)){
    return "not evaluated";
  }
  double movieEvaluation = movieToEvaluation[movie];
  if(movieEvaluation <= 2.5){
    return "very bad";
  } else if(movieEvaluation > 2.5 && movieEvaluation <= 5.0){
    return "bad";
  } else if(movieEvaluation > 5.0 && movieEvaluation <= 7.5){
    return "good";
  } else{
    return "very good";
  }
}
