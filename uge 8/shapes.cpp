#include "shapes.h"
#include <cmath>
#include <iostream>

using namespace std;

Rectangle::Rectangle(double h, double w){
	var_height = h;
	var_width = w;
}

double Rectangle::area(){
	return var_height * var_width;
}

double Rectangle::perimeter(){
	double peri = var_height * 2 + var_width * 2;
	return peri;
}

double Rectangle::height(){
	return var_height;
}

double Rectangle::width(){
	return var_width;
}

void Rectangle::rotate(){
	double old_width = var_width;
	var_width = var_height;
	var_height = old_width;
}

Square::Square(double l){
	var_length = l;
}

double Square::area(){
	return var_length * var_length;
}

double Square::perimeter(){
	double peri = var_length * 4;
	return peri;
}

double Square::height(){
	return var_length;
}

double Square::width(){
	return var_length;
}

Circle::Circle(double r){
	var_radius = r;
}

double Circle::area(){
	double length_pow = pow(var_radius, 2);
	return length_pow * M_PI;
}

double Circle::perimeter(){
	double peri = 2 * M_PI * var_radius;
	return peri;
}

double Circle::height(){
	return var_radius * 2;
}

double Circle::width(){
	return var_radius * 2;
}


