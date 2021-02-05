#include "..\Header Files\Vector2D.h"

Vector2D::Vector2D() : x_{ 0 }, y_{0}
{

}

Vector2D::Vector2D(int x, int y): x_{x}, y_{y}
{

}

void Vector2D::zero()
{
	x_ = 0;
	y_ = 0;
}

Vector2D& Vector2D::operator+(const Vector2D& other_v)
{
	this->x_ += other_v.x_;
	this->y_ +=other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator-(const Vector2D& other_v)
{
	this->x_ -= other_v.x_;
	this->y_ -= other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator*(const Vector2D& other_v)
{
	this->x_ *= other_v.x_;
	this->y_ *= other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator/(const Vector2D& other_v)
{
	this->x_ /= other_v.x_;
	this->y_ /= other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& other_v)
{
	this->x_ += other_v.x_;
	this->y_ += other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other_v)
{
	this->x_ -= other_v.x_;
	this->y_ -= other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& other_v)
{
	this->x_ *= other_v.x_;
	this->y_ *= other_v.y_;

	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& other_v)
{
	this->x_ /= other_v.x_;
	this->y_ /= other_v.y_;

	return *this;
}

bool Vector2D::operator==(const Vector2D& other_v) const
{
	if (this->x_ == other_v.x_ && this->y_ == other_v.y_) {
		return true;
	}
	else {
		return false;
	}
}

int Vector2D::get_x()
{
	return x_;
}

int Vector2D::get_y()
{
	return y_;
}
