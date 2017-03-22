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
	/*bool MapOK = true;
	if (position.x + radius.x < 0)
	{
		MapOK = false;
	}
	if (position.x - radius.x > size.x)
	{
		MapOK = false;
	}
	if (position.y - radius.y < 0)
	{
		MapOK = false;
	}
	if (position.y + radius.y > size.y)
	{
		MapOK = false;
	}

	return MapOK;*/
	Vector2 bulletPosition = GetPosition();
	double bulletX = bulletPosition.x;
	double bulletY = bulletPosition.y;

	double bulletDiametr = GetRadius() * 2;
	double sizeX = size.x - bulletDiametr;
	double sizeY = size.y - bulletDiametr;

	bool boardOk = true;

	/*
	вместо кучи строк можно написать
	return bulletX >= 0 && bulletX <= sizeX && bulletY >= 0 && bulletY <= sizeY;
	*/
	if (bulletX < 0)
	{
		return false;
	}

	if (bulletY < 0)
	{
		return false;
	}

	/*
	Точно не bulletX >= sizeX ?
	*/
	if (bulletX > sizeX)
	{
		return false;
	}

	if (bulletY > sizeY)
	{
		return false;
	}

	return true;
}