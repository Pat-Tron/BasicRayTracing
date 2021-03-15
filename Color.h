#pragma once
#include <iostream>

class Color
{
public:
	int R, G, B;
	double nR, nG, nB;

	Color(int r = 0, int g = 0, int b = 0):R(r), G(g), B(b) { normalizer();}
	Color(double nr = 0, double ng = 0, double nb = 0, bool doubleOrNot = true)
		:nR(nr), nG(ng), nB(nb) { denormalizer(); }

	Color operator * (Color c) { return Color(nR * c.nR, nG * c.nG, nB * c.nB, true); }
	Color operator * (double x) { return Color(nR * x, nG * x, nB * x, true); }
	Color operator + (Color c) 
	{ 
		return Color(min(R + c.R, 255), min(G + c.G, 255), min(B + c.B, 255)); }

	void normalizer() { nR = R / 255.0; nG = G / 255.0; nB = B / 255.0; }
	void denormalizer() { R = nR * 255.0; G = nG * 255.0; B = nB * 255.0; }
	int min(int x, int y) { if (x < y) { return x; } else { return y; } }

	//friend std::ostream& operator << (std::ostream& output, const Color& color);
};

//std::ostream& operator << (std::ostream& output, const Color& c) {
//	output << "Color: ( " << c.R << ' ' << c.G << ' ' << c.B << "), ( "
//		<< c.nR << ' ' << c.nG << ' ' << c.nB << " )";
//	return output;
//}