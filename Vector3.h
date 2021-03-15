#pragma once
#include <iostream>
#include <math.h>

class Vector3
{
private:
	double u, v, w;

public:
	Vector3(double x = 0.0, double y = 0.0, double z = 0.0) { u = x; v = y; w = z; }

	double operator*(Vector3 v3) { return u * v3.u + v * v3.v + w * v3.w; }
	Vector3 operator+(Vector3 v3) { return Vector3(u + v3.u, v + v3.v, w + v3.w); }
	Vector3 operator-(Vector3 v3) { return Vector3(u - v3.u, v - v3.v, w - v3.w); }
	Vector3 operator/(double divisor) { return Vector3(u / divisor, v / divisor, w / divisor); }
	Vector3 operator*(double factor) { return Vector3(u * factor, v * factor, w * factor); }
	Vector3 crossProduct(Vector3 v3) { return Vector3(u * v3.u, v * v3.v, w * v3.w); }
	double modulus() { return sqrt(u * u + v * v + w * w); }
	Vector3 normalizer();
	void print() { std::cout << "( " << u << " , " << v << " , " << w << " )" << std::endl; }
};

Vector3 Vector3::normalizer()
{
	double _modulus = modulus();
	return Vector3(u / _modulus, v / _modulus, w / _modulus);
}