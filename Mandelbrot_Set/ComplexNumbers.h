#pragma once

class ComplexFloat {
public:
	float real;
	float imaginary;

	ComplexFloat();
	ComplexFloat(float real);
	ComplexFloat(float real, float imaginary);

	ComplexFloat operator*(ComplexFloat);
	ComplexFloat operator+(ComplexFloat);
};