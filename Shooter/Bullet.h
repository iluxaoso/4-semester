#pragma once
#include "includes.h"

class Bullet
{
public:
	Vector2 position;
	Vector2 velocity;
	double radius;

	Bullet();
	Bullet(const Vector2& position, const Vector2& vel);

	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
	double  GetRadius  () const;

	Vector2 SetPosition(const Vector2& pos);
	Vector2 SetVelocity(const Vector2& vel);

	void update(double dt);
	bool onMap(const Vector2& size) const;
};