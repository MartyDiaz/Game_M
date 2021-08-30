#pragma once

class Vector2D
{
private:
	float x_;
	float y_;

public:
	Vector2D();
	Vector2D(float x, float y);

	void zero();

	Vector2D& operator+(const Vector2D& other_v);

	Vector2D& operator-(const Vector2D& other_v);

	Vector2D& operator*(const Vector2D& other_v);

	Vector2D& operator/(const Vector2D& other_v);

	Vector2D& operator+=(const Vector2D& other_v);

	Vector2D& operator-=(const Vector2D& other_v);

	Vector2D& operator*=(const Vector2D& other_v);

	Vector2D& operator/=(const Vector2D& other_v);

	bool operator ==(const Vector2D& other_v) const ;

	float get_x();

	float get_y();

	float x();

	float y();

};


