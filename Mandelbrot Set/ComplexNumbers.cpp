#include "pch.h"
#include "ComplexNumbers.h"

ComplexFloat::ComplexFloat() {
	real = 0.0f;
	imaginary = 0.0f;
}

ComplexFloat::ComplexFloat(float f) {
	real = f;
	imaginary = 0.0f;
}

ComplexFloat::ComplexFloat(float real, float imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

ComplexFloat ComplexFloat::operator*(ComplexFloat other) {
	ComplexFloat result;

	result.real = (real * other.real) - (imaginary * other.imaginary);
	result.imaginary = (imaginary * other.real) + (real * other.imaginary);

	return result;
}

ComplexFloat ComplexFloat::operator+(ComplexFloat other) {
	ComplexFloat result;

	result.real = real + other.real;
	result.imaginary = imaginary + other.imaginary;

	return result;
}