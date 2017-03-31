#pragma once
#include "includes.h"

class Hero
{
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 direction;
	double  radius;

	Hero(double rad = HERO_RADIUS);

	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
	Vector2 GetDirection() const;
	double  GetRadius() const;

	void    SetPosition (const Vector2& pos);
	void    SetVelocity (const Vector2& vel);
	void    SetDirection(const Vector2& dir);
	void    SetRadius   (const double   rad);

	Vector2 rotate(double k);

	void    update(double dt);
};