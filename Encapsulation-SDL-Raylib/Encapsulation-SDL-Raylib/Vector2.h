#pragma once

#include <iostream>

namespace Custom
{
template<typename T>
class Vector2
{
public:
	Vector2()
		: x(0)
		, y(0)
	{}
	Vector2(const T& X, const T& Y)
		: x(X)
		, y(Y)
	{}

	virtual ~Vector2() {}

	T x;
	T y;
};

/*
* Operator + / +=
*/

template<typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
Vector2<T> operator+(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.x + right, left.y + right);
}

template<typename T>
Vector2<T> operator+=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}

/*
* Operator - / -=
*/

template<typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
Vector2<T> operator-(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.x - right, left.y - right);
}

template<typename T>
Vector2<T> operator-=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

/*
* Operator * / *=
*/

template<typename T>
Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x * right.x, left.y + right.y);
}

template<typename T>
Vector2<T> operator*(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
Vector2<T> operator*=(Vector2<T>& left, const Vector2<T>& right)
{
	left.x *= right.x;
	left.y *= right.y;
	return left;
}

/*
* Operator / / /=
*/

template<typename T>
Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right)
{
	return Vector2<T>(left.x / right.x, left.y / right.y);
}

template<typename T>
Vector2<T> operator/(const Vector2<T>& left, T right)
{
	return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
Vector2<T> operator/(Vector2<T>& left, const Vector2<T>& right)
{
	left.x /= right.x;
	left.y /= right.y;
	return left;
}


template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector2<T>& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

typedef Vector2<float> Vector2f;
typedef Vector2<unsigned int> Vector2u;
}
