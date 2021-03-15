#include "aaa.h"
#include "Color.h"

void background(const int& uIndex, const int& vIndex, Color& color)
{
    color.R = 0;
    color.G = int(double(uIndex) / resolutionWidth * 255.0);
    color.B = int(double(vIndex) / resolutionHeight * 255.0);
}

void background2(const int& uIndex, const int& vIndex, Color& color)
{
    color.R = int(double(uIndex) / resolutionWidth * 0.7 * 255.0);
    color.G = 0;
    color.B = int(double(vIndex) / resolutionHeight * 0.7 * 255.0);
}

//// 截取脚本名为输出图片名
// int main(int argc, char** argv)
//// C:\Users\Administrator\Desktop\simpleShader\Debug\....exe
//std::string filename{ argv[0] };
//filename = filename.substr(filename.rfind('\\') + 1);
//filename.erase(filename.find('.'), 4);
//filename += ".ppm";