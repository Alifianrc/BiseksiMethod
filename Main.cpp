#include "MetodeBiseksi.h"

// Fungsi dapat diganti sesuai kebutuhan
// Fungsi f(x) = -4x^3 + 3
double functionX(double x) {
	double result = (-4 * pow(x, 3)) + 3;
	return result;
}


int main() {
	Biseksi biseksi;

	biseksi.GetInput();
	biseksi.RunMethod(functionX);
	biseksi.ShowTable();
}