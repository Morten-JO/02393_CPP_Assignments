#ifndef SHAPES_H
#define SHAPES_H

class Shape {
	public:
		virtual double area(){};
		virtual double perimeter(){};
		virtual double height(){};
		virtual double width(){};
		virtual void rotate(){};
	
	
};

class Rectangle: public Shape {
	double var_height, var_width;
	public:
		Rectangle(double h, double w);
		double area();
		double perimeter();
		double height();
		double width();
		void rotate();
	
};

class Square: public Shape {
	double var_length;
	public:
		Square(double l);
		double area();
		double perimeter();
		double height();
		double width();
};

class Circle: public Shape {
	double var_radius;
	public:
		Circle(double r);
		double area();
		double perimeter();
		double height();
		double width();
};

#endif