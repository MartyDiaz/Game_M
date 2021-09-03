#include "..\Header Files\Vector2D.h"

Vector2D::Vector2D() : x_{0.f}, y_{0.f}
{

}

Vector2D::Vector2D(float x, float y): x_{x}, y_{y}
{

}

void Vector2D::zero()
{
	x_ = 0.f;
	y_ = 0.f;
}

Vector2D& Vector2D::operator=(const Vector2D& other_v)
{
	x_ = other_v.x_;
	y_ = other_v.y_;
	return *this;
}

bool Vector2D::operator==(const Vector2D& other_v) const
{
	return (x_ == other_v.x_ && y_ == other_v.y_);
}

Vector2D Vector2D::operator+(const Vector2D& other_v)
{
	return Vector2D{x_ + other_v.x_ , y_ + other_v.y_};
}

Vector2D Vector2D::operator-(const Vector2D& other_v)
{
	return Vector2D{x_ - other_v.x_ , y_ - other_v.y_};
}


Vector2D& Vector2D::operator+=(const Vector2D& other_v)
{
	x_ += other_v.x_;
	y_ += other_v.y_;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other_v)
{
	x_ -= other_v.x_;
	y_ -= other_v.y_;
	return *this;
}

Vector2D Vector2D::operator*(const float& scaler)
{
	return Vector2D{ x_ * scaler, y_ * scaler };
}

Vector2D Vector2D::operator/(const float& scaler)
{
	const float r = 1 / scaler;
	return Vector2D{ x_ * r, y_ * r };
}

Vector2D operator*(const float& scaler, const Vector2D& other_v)
{
	return Vector2D{ other_v.x_ * scaler, other_v.y_ * scaler };
}

Vector2D operator/(const float& scaler, const Vector2D& other_v)
{
	const float r = 1 / scaler;
	return Vector2D{ other_v.x_ * r, other_v.y_ * r };
}

Vector2D& Vector2D::operator*=(const float& scaler)
{
	x_ *= scaler;
	y_ *= scaler;
	return *this;
}

Vector2D& Vector2D::operator/=(const float& scaler)
{
	const float r = 1 / scaler;
	x_ *= r;
	y_ *= r;
	return *this;
}



