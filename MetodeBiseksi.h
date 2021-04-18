#pragma once
#include <iostream>
#include <iomanip>
#include <functional>

class Biseksi {
private:
	// Untuk Menyimpan Input -> Iterasi Maksimum
	int iterasiMax;
	// Batas Bawah, Batas Atas, Nilai Error
	double xBottom, xTop, nilaiErr;
	
	// Untuk Data Tabel -> Batas Bawah, Batas Atas, Nilai x, nilai f(X)
	double a[1000], b[1000], x[1000], fX[1000], fa[1000], fb[1000];
	// Jumlah Iterasi yang dilakukan
	int iterasi = 0;

public:
	Biseksi() = default;

	void GetInput();

	void RunMethod(std::function<double(double)> functionX);

	void ShowTable();
};

