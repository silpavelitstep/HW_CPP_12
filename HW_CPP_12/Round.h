#pragma once
#include <iostream>
using namespace std;
#ifndef ROUND_H
#define ROUND_H
class Point {
protected:
	double x, y;
	
public:
	Point() :x(0), y(0) {}
	Point(double xx, double yy) :x(xx), y(yy) {}
	double getX() { return x; }
	double getY() { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void show() { cout << "( " << x << ", " << y << " )\n"; }
};
class Round:public Point{
protected:
	double radius;
public:
	Round() :radius(0) {}
	Round(double r) :radius(r) {}
	Round(double xx, double yy, double r) :Point(xx, yy), radius(r) {}
	double getRadius() { return radius; }
	void setRadius(double r) { radius = r; }
	double getSquare() { return 3.1415926 * radius * radius; }
	void show() { cout << "( " << x << ',' << y << ',' << radius << " )\n"; }
};
class Square:public Point {
protected:
	double side;
public:
	Square() :side(0) {}
	Square(double s) :side(s) {}
	Square(double xx, double yy, double s): Point(xx,yy), side(s) {}
	double getSide() { return side; }
	void setSide(double s) { side = s; }
	double getSquare() { return side * side; }
	void show() { cout << "( " << x << ',' << y << " ) " << "side=" << side << endl; }
};
class RoundInscribeSquare:public Square, public Round {
	
public:
	RoundInscribeSquare() {};
	RoundInscribeSquare(double r) :Round(r) {}
	RoundInscribeSquare(double xx, double yy, double r) :Round(xx, yy, r) {}
	//void show() { cout << "( " << x << ',' << y << ',' << radius << " )\n"; }
	void show() { cout << "( " << Round::x << ',' << Round::y << ',' << radius << " )\n"; }
	void setSideSquare(double s) {
		side = s;
		//radius round is changed
		radius = s / 2;
	}
	void setXYSquare(double xx, double yy) {
		Square::x = xx;
		Round::x = (Square::x + side) / 2;
		Square::y = yy;
		Round::y = (Square::y + side) / 2;
	}
	void setXYSideSquare(double xx, double yy, double s) {
		setSideSquare(s);
		setXYSquare(xx, yy);
	}
};
//next for unit 4
class Triangle {
	Point top[3];//composition
public:

};
//next some compositions
class Picture {
	//next array
	Point points[20000];
	Round rounds[15];
	Square squares[50];
	Triangle tri[500];
	//else
	/*
	Point *points;
	Round *rounds;
	Square *squares;
	Triangle *tri;
	
	*/
public:
};
#endif // !ROUND_H
