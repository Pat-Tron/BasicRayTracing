#pragma once
#include "Ray.h"
#include "Color.h"

class Sphere
{
public:
	Vector3 center;
	double radius;

	Sphere() { center = Vector3(0, 0, 0); radius = 1.0; }
	Sphere(Vector3 c, double r) { center = c; radius = r; }

	bool hit(Ray& ray, double hitLowerBound, double hitUpperBound, Vector3& hitRecord);
	void color(Vector3& hitPoint, Color& c);
	Vector3 normalVector(Vector3& hitPoint) { return hitPoint - center; }
};

bool Sphere::hit(Ray& ray, double hitLowerBound, double hitUpperBound, Vector3& hitPoint)
{
	Vector3 originMinusCenter = ray.origin - center;
	double squareOfDirction = ray.direction * ray.direction;
	double discriminant = pow(ray.direction * originMinusCenter, 2) - squareOfDirction * (
		originMinusCenter * originMinusCenter - pow(radius, 2));

	double root = 0;

	if (discriminant < 0) { return false; }
	else if (discriminant == 0){
		root = ray.direction * (originMinusCenter * -1) / squareOfDirction;
		hitPoint = ray.origin + ray.direction * root;
		return true;
	}
	else {
		double sqrtOfDiscriminant = sqrt(discriminant);
		double root1 = ((ray.direction * originMinusCenter) * -1 + sqrtOfDiscriminant) / squareOfDirction;
		double root2 = ((ray.direction * originMinusCenter) * -1 - sqrtOfDiscriminant) / squareOfDirction;

		if (root1 < root2) { root = root1; }
		else { root = root2; }

		if ( hitLowerBound <= root && hitUpperBound >= root ) {
			hitPoint = ray.origin + ray.direction * root;
			return true;
		}
		else { return false; }
	}
}

void Sphere::color(Vector3& hitPoint, Color& c)
{
	c.R = 79;
	c.G = 63;
	c.B = 204;
}