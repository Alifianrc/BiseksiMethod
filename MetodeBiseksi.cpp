#include "MetodeBiseksi.h"

void Biseksi::GetInput() {
	std::cout << "Masukkan Batas Bawah       : "; std::cin >> xBottom;
	std::cout << "Masukkan Batas Atas        : "; std::cin >> xTop;
	std::cout << "Masukkan Toleransi Error   : "; std::cin >> nilaiErr;
	std::cout << "Masukkan Iterasi Maksimum  : "; std::cin >> iterasiMax;
	std::cout << std::endl;
}

void Biseksi::RunMethod(std::function<double(double)> functionX) {
    // Cek apakah ada akar
    if (functionX(xBottom) * functionX(xTop) > 0) {
        std::cout << "Tidak ada akar\n";
    }
    else {
        bool condition = false;
        double xr;

        while (!condition) {
            iterasi++;
            xr = (xBottom + xTop) / 2;

            // Menyimpan data
            x[iterasi] = xr;
            a[iterasi] = xBottom;
            b[iterasi] = xTop;
            fX[iterasi] = functionX(xr);
            fa[iterasi] = functionX(a[iterasi]);
            fb[iterasi] = functionX(b[iterasi]);

            // Nilai error, Iterasi maksimum
            if ((abs(xTop - xBottom) - nilaiErr) < nilaiErr || iterasi >= iterasiMax) {
                condition = true;
            }
            else {
                if (functionX(xBottom) * functionX(xr) < 0) {
                    xTop = xr;
                }
                else {
                    xBottom = xr;
                }
            }
        }

        std::cout << "Nilai Akar    : " << xr << std::endl;
        std::cout << std::fixed << std::setprecision(15) << "Nilai Error   : " << abs(xTop - xBottom) << std::endl;
        std::cout << "Iterasi Total : " << (iterasi) << "\n\n";
    }
}

void Biseksi::ShowTable() {
    std::cout << "                        Tabel Iterasi\n";
    std::cout << "Iterasi     a               b                  f(a)               f(b)              xr                 f(xr)\n";

    std::cout << std::fixed << std::setprecision(9);
    for (int i = 1; i <= iterasi; i++) {
        std::cout << i << "           " << a[i] << "     " << b[i] << "        " << fa[i] << "        " << fb[i] << "      " << x[i] << "        " << fX[i]  << std::endl;
    }
}