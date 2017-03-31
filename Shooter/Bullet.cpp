#include "Bullet.h"

Bullet::Bullet()
{
	position.x = 0;
	position.y = 0;

	velocity.x = 0;
	velocity.y = 0;

	radius = BULLET_RADIUS;
}

Bullet::Bullet(const Vector2& pos, const Vector2& vel)
{
	position = pos;

	velocity = vel;

	radius = BULLET_RADIUS;
}

Vector2 Bullet::GetPosition() const
{
	return position;
}

Vector2 Bullet::GetVelocity() const
{
	return velocity;
}

double Bullet::GetRadius() const
{
	return radius;
}

Vector2 Bullet::SetPosition(const Vector2& pos)
{
	position = pos;
}

Vector2 Bullet::SetVelocity(const Vector2& vel)
{
	velocity = vel;
}

void Bullet::update(double dt)
{
	position += velocity * dt;
}

bool Bullet::onMap(const Vector2& size) const
{
	bool MapOK = true;
	if (position.x + radius < 0)
	{
		MapOK = false;
	}
	if (position.x - radius > size.x)
	{
		MapOK = false;
	}
	if (position.y - radius < 0)
	{
		MapOK = false;
	}
	if (position.y + radius > size.y)
	{
		MapOK = false;
	}

	return MapOK;
}