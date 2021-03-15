#pragma once
#include "aaa.h"
#include "Vector3.h"

class Ray
{
public:
	Vector3 origin;
	Vector3 direction;
private:
	int uIndex = 0;
	int vIndex = 0;
	double pixelPosition_u = 0.0;
	double pixelPosition_v = 0.0;

public:
	Ray() { origin = Vector3(0, 0, 0); direction = Vector3(1, 0, 0); }
	Ray(Vector3 orgn, Vector3 drct) { origin = orgn; direction = drct; }
	Ray(int uIndex, int vIndex);
	void print()
	{
		std::cout << "Ray direction in ( " << uIndex << " , " << vIndex << " ) is : ";
		direction.print();
	}
};

Ray::Ray(int uIndex_temp, int vIndex_temp)
{
	uIndex = uIndex_temp;
	vIndex = vIndex_temp;
	// Image coodinates of pixel at position (uIndex, vIndex)
	pixelPosition_u = leftEdge + (uIndex_temp + 0.5) * imageWidth / resolutionWidth;
	pixelPosition_v = bottomEdge + (vIndex_temp + 0.5) * imageHeight / resolutionHeight;
	// direction = -base_w * focalLenth + base_u * pixelPosition_u + base_v * pixelPosition_v;
	direction = Vector3(pixelPosition_u, pixelPosition_v, focalLenth);
	origin = Vector3(0, 0, 0);
}