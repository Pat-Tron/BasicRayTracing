#include <fstream>
#include "aaa.h"
#include "Ray.h"
#include "Surfaces.h"
#include "Color.h"
#include "LightSource.h"

// Camera and image initialization
// Perspective views
// basis: w = u x v, origin: e (camera position)
// u(1.0, 0.0, 0.0), v(0.0, 1.0, 0.0), w(0.0, 0.0, -1.0);
int const resolutionWidth = 1500;
int const resolutionHeight = 1000;
double const focalLenth = 10.0;

// Square pixels
double const imageWidth = 20.0;
double const imageHeight = imageWidth / (double(resolutionWidth) / resolutionHeight);
double const rightEdge = imageWidth / 2.0;
double const leftEdge = -rightEdge;
double const topEdge = imageHeight / 2.0;
double const bottomEdge = -topEdge;


int main()
{
    // Image initialization
    std::ofstream outf{ "pictures/singleLightSourceShadingWithReflection.ppm" };
    outf << "P3\n" << resolutionWidth << '\t' << resolutionHeight << '\n' << 255 << '\n';

    // Objects initialization
    Sphere sphereBig(Vector3(0, 0, 15), 6);
    LightSource lightSource(Ray(Vector3(10, 10, 17), Vector3(0, 0, 0)), Color(250, 250, 250));

    // Specular
    int PhongExponent = 200;
    Color SpecularColor(200, 250, 250);
    // mainloop of sitting pixels
    Color finalColor(0, 0, 0);
    Color SpecularColorTemp(0, 0, 0);

    //for (int vIndex = resolutionHeight - 1; vIndex >= 0; vIndex--)
    for (int vIndex = 0; vIndex < resolutionHeight; vIndex++)
    {
        for (int uIndex = resolutionWidth - 1; uIndex >= 0; uIndex--)
        {
            Ray ray(uIndex, vIndex);
            
            Vector3 hitPoint;

            if (sphereBig.hit(ray, 0, 100, hitPoint)) {
                sphereBig.color(hitPoint, finalColor);
                finalColor.normalizer();

                // Lambertian Shading
                Vector3 normal = sphereBig.normalVector(hitPoint).normalizer();
                Vector3 lightRay = (hitPoint - lightSource.ray.origin).normalizer();
                double cosine1 = normal * lightRay;
                // Only acute angle matters.
                if (cosine1 < 0) { cosine1 = 0; }
                
                //Blinn-Phong Shading
                Vector3 viewRay = (hitPoint * -1).normalizer();
                Vector3 bisector = (viewRay + lightRay).normalizer();
                double cosine2 = normal * bisector;
                // Only acute angle matters.
                if (cosine2 < 0) { cosine2 = 0; }
                cosine2 = pow(cosine2, PhongExponent);
                SpecularColorTemp = SpecularColor * lightSource.intensity * cosine2;
                SpecularColorTemp.denormalizer();
                

                //Ambient Shading

                // Multiple Point Lights


                finalColor = finalColor * lightSource.intensity * cosine1;
                finalColor = finalColor + SpecularColorTemp;
            }
            else {
                background2(uIndex, vIndex, finalColor);
            }
            
            outf << finalColor.R << ' ' << finalColor.G << ' ' << finalColor.B << '\t';
        }
        outf << '\n';
    }

    return 0;
}
