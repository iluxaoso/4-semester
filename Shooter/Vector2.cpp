#include "Vector2.h"

Vector2::Vector2 (double _x, double _y):
	x(_x),
	y(_y)
{}

Vector2::~Vector2() {}

//======================
Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator+=(const Vector2& other)
{
	return Vector2(x += other.x, y += other.y);
}

Vector2 Vector2::operator-=(const Vector2& other)
{
	return Vector2(x -= other.x, y -= other.y);
}



double Vector2::operator* (const Vector2& other) const
{
	return (x * other.x + y * other.y);
}

double Vector2::operator^ (const Vector2& other) const
{
	return x * other.y - y * other.x;
}



Vector2 Vector2::operator* (const double k) const
{
	return Vector2(x * k, y * k);
}

Vector2 Vector2::operator/ (const double k) const
{
	return Vector2(x / k, y / k);
}



Vector2 Vector2::operator-()
{
	return Vector2(x * (-1), y * (-1));
}

//======================
Vector2 Vector2::rotate(double k)//!угол в радианах
{
	double new_x = x;
	double new_y = y;

	k = k * 180 / M_PI;//!угол в градусах

	x = new_x * cos(k) - new_y * sin(k);
	y = new_x * sin(k) + new_y * cos(k);

	return Vector2(x, y);
}

Vector2 Vector2::getRotated(double k) const //!угол в радианах
{
	return Vector2(x, y).rotate(k * 180 / M_PI);//!угол в градусах
}



double Vector2::angle180(const Vector2& other) const
{
	return acos((x * other.x + y * other.y) / (sqrt(x * x + y * y) * sqrt(other.x * other.x + other.y * other.y)));
}

double Vector2::angle360(const Vector2& other) const
{
	double angle = angle180(other);
	angle *= 180. / M_PI;

	if (((*this) ^ other) < 0)
	{
		angle = 360. - angle;
	}

	return angle;
}

//======================
double Vector2::len() const
{
	return (sqrt(x * x + y * y));
}

Vector2 Vector2::norm() const
{
	return Vector2(x / len(), y / len());
}

Vector2 Vector2::perp() const
{
	return Vector2(x / len(), (-x) / tan(y / x) / len());
}

//======================
int Vector2::vector2DMP()
{
	std::ofstream dump("dump.vectordmp", std::ofstream::app);
	dump << x << " " << y << "/n";
	dump.close();
	return 0;
}

bool Vector2::vector2OK()
{
	return true;
}

//======================
std::ostream& operator <<(std::ostream& stream, const Vector2& v)
{
	stream << "(" << v.x << " " << v.y << ")";

	return stream;
}

std::istream& operator >> (std::istream& stream, Vector2& v)
{
	stream >> v.x;
	stream >> v.y;

	return stream;
}



Vector2 operator * (const double k, const Vector2& other)
{
	return other * k;
}