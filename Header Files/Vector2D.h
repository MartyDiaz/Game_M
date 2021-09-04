#pragma once

class Vector2D
{

public:
	float x_;
	float y_;
	
	Vector2D();
	Vector2D(float x, float y);

	void zero();
	
	Vector2D& operator=(const Vector2D& other_v);
	
	bool operator ==(const Vector2D& other_v) const ;

	Vector2D operator+(const Vector2D& other_v);

	Vector2D operator-(const Vector2D& other_v);

	Vector2D& operator+=(const Vector2D& other_v);

	Vector2D& operator-=(const Vector2D& other_v);

	Vector2D operator*(const float& scaler);

	Vector2D operator/(const float& sclaer);

	Vector2D& operator*=(const float& scaler);

	Vector2D& operator/=(const float& sclaer);

	friend Vector2D operator*(const float& scaler, const Vector2D& other_v);
	
	friend Vector2D operator/(const float& scaler, const Vector2D& other_v);

};


