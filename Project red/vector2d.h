#pragma once
#include <iostream>

class vector2D
{
public:
	float x;
	float y;

	vector2D();
	vector2D(float x, float y);

	vector2D& Add(const vector2D& vect);
	vector2D& subtract(const vector2D& vect);
	vector2D& multiply(const vector2D& vect);
	vector2D& divide(const vector2D& vect);

	friend vector2D& operator+(vector2D v1, const vector2D& v2);
	friend vector2D& operator-(vector2D v1, const vector2D& v2);
	friend vector2D& operator*(vector2D v1, const vector2D& v2);
	friend vector2D& operator/(vector2D v1, const vector2D& v2);

	vector2D& operator+= (const vector2D& vect);
	vector2D& operator-= (const vector2D& vect);
	vector2D& operator*= (const vector2D& vect);
	vector2D& operator/= (const vector2D& vect);

	friend std::ostream& operator<<(std::ostream stream, const vector2D vect);
};