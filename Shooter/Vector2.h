#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>





class Vector2
{
public:
	double x;
	double y;

	Vector2(double _x = 0, double _y = 0);

	~Vector2();

	//=================
	Vector2 operator +  (const Vector2& other) const;
	Vector2 operator -  (const Vector2& other) const;
	Vector2 operator += (const Vector2& other);
	Vector2 operator -= (const Vector2& other);

	double  operator *  (const Vector2& other) const;
	double  operator ^  (const Vector2& other) const;

	Vector2 operator *  (const double   k    ) const;
	Vector2 operator /  (const double   k    ) const;
	
	Vector2 operator -  (                    );

	//=================
	Vector2 rotate      (      double   k    );
	Vector2 getRotated  (      double   k    ) const;

	double  angle180    (const Vector2& other) const;
	double  angle360    (const Vector2& other) const;

	//=================
	double  len () const;
	Vector2 norm() const;
	Vector2 perp() const;

	//=================
	int   Vector2::vector2DMP();
	bool  Vector2::vector2OK();

	//=================
	friend std::ostream& operator << (std::ostream& stream, const Vector2& v);
	friend std::istream& operator >> (std::istream& stream,       Vector2& v);

	friend Vector2 operator *  (const double k, const Vector2& other);
};
