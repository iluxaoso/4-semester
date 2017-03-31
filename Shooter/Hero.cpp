#include "Hero.h"

Hero::Hero(double rad)
{
	position.x = MAP_SIZE_X / 2;
	position.y = MAP_SIZE_Y / 2;

	velocity.x = 0;
	velocity.y = 0;

	direction.x = 0;
	direction.y = 0;

	radius = rad;
}

void Hero::update(double dt)
{
	position += velocity * dt;
}

Vector2 Hero::GetPosition() const
{
	return position;
}

Vector2 Hero::GetVelocity() const
{
	return velocity;
}

Vector2 Hero::GetDirection() const
{
	return direction;
}

double Hero::GetRadius() const
{
	return radius;
}

void Hero::SetVelocity(const Vector2& vel)
{
	velocity = vel;
}

void Hero::SetPosition(const Vector2& pos)
{
	position = pos;
}

void Hero::SetDirection(const Vector2& dir)
{
	direction = dir;
}

void Hero::SetRadius(const double rad)
{
	radius = rad;
}

Vector2 Hero::rotate(double k)//!угол в радианах
{
	double new_x = position.x;
	double new_y = position.y;

	position.x = new_x * cos(k) - new_y * sin(k);
	position.y = new_x * sin(k) + new_y * cos(k);

	return Vector2(position.x, position.y);
}