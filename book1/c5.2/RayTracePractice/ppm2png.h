#pragma once
#include<vector>
#include "lodepng.h"
#include<iostream>
struct RGB {
	int r;
	int g;
	int b;
};

class ppm2png
{
public:
	ppm2png()=default;
	~ppm2png()=default;

	void encodeTwoSteps(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
	{
		std::vector<unsigned char> png;
		unsigned error = lodepng::encode(png, image, width, height);
		if (!error)
			lodepng::save_file(png, filename);
		if (error)
			std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	}

	void get_image(std::vector<RGB> image, float width, float height)
	{
		std::vector<unsigned char> png;
		png.resize(width * height * 4);
		int x = 0, y = 0;
		for(auto rgb:image)
		{
			png[4 * width * y + 4 * x + 0] = rgb.r;
			png[4 * width * y + 4 * x + 1] = rgb.g;
			png[4 * width * y + 4 * x + 2] = rgb.b;
			png[4 * width * y + 4 * x + 3] = 255;
			x++;
			if (x == width)
			{
				x = 0;
				y++;
			}
		}
		encodeTwoSteps("out.png", png, width, height);
	}
};

