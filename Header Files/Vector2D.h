#pragma once

class Vector2D
{
private:
	int x_;
	int y_;

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


	int get_x();
	int get_y();

};


