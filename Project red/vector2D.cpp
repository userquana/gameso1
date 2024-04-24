#include "vector2d.h"

vector2D::vector2D()
{
	x = 0.0f;
	y = 0.0f;

}
vector2D::vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}
vector2D& vector2D::Add(const vector2D& vect)
{
	// TODO: insert return statement here
	this->x -= vect.x;
	this->y -= vect.y;
	return *this;
}
vector2D& vector2D::subtract(const vector2D& vect)
{
	this->x -= vect.x;
	this->y -= vect.y;
	return *this;
}
vector2D& vector2D::multiply(const vector2D& vect)
{
	this->x *= vect.x;
	this->y *= vect.y;
	return *this;
}
vector2D& vector2D::divide(const vector2D& vect)
{
	this->x /= vect.x;
	this->y /= vect.y;
	return *this;
}

vector2D& operator+(vector2D v1, const vector2D& v2)
{
	return v1.Add(v2);
}

vector2D& operator-(vector2D v1, const vector2D& v2)
{
	return v1.subtract(v2);
}

vector2D& operator*(vector2D v1, const vector2D& v2)
{
	return v1.multiply(v2);
}

vector2D& operator/(vector2D v1, const vector2D& v2)
{
	return v1.divide(v2);
}
vector2D& vector2D::operator+= (const vector2D& vect)
{
	return this->Add(vect);
}
vector2D& vector2D::operator-= (const vector2D& vect)
{
	return this->subtract(vect);
}
vector2D& vector2D::operator*= (const vector2D& vect)
{
	return this->multiply(vect);
}
vector2D& vector2D::operator/= (const vector2D& vect)
{
	return this->divide(vect);
}

vector2D& vector2D::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;
	return *this;
}

vector2D& vector2D::Zero()
{
	this->x = 0;
	this->y = 0;
	return *this;
}



std::ostream& operator<<(std::ostream stream, const vector2D vect)
{
	stream << "(" << vect.x << "," << vect.y << ")";
	return stream;

}