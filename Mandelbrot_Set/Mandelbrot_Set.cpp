// Mandelbrot Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include "ComplexNumbers.h"

const int width = 960;
const int height = 544;
const int num_iterations = 40;

float minx = -2.5f;
float maxx = 1.0f;
float miny = -1.0f;
float maxy = 1.0f;

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int iterate(ComplexFloat c) {
	ComplexFloat z = 0.0f;

	for (int i = 0; i < num_iterations; i++) {
		z = (z * z) + c;

		if (z.real * z.real + z.imaginary * z.imaginary > 4) {
			return i;
		}
	}

	return num_iterations;
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Mandelbrot set", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	bool quit = false;
	while (!quit) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				float real = map(x, 0, width, minx, maxx);
				float imaginary = map(y, 0, height, miny, maxy);

				int n = iterate(ComplexFloat(real, imaginary));

				int b = map(n, 0, num_iterations, 255, 0);
				SDL_SetRenderDrawColor(renderer, b, b, b, 255);

				SDL_RenderDrawPoint(renderer, x, y);
			}
		}

		SDL_RenderPresent(renderer);

		SDL_Event e;
		while (SDL_PollEvent(&e) > 0) {
			if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				quit = true;
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

