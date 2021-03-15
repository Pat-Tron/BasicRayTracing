#pragma once
#include "Ray.h"
#include "Color.h"

class LightSource
{
public:
	Ray ray = Ray();
	Color intensity = Color(0, 0, 0);

	LightSource(Ray ray, Color intensity) : ray(ray), intensity(intensity) {}
};