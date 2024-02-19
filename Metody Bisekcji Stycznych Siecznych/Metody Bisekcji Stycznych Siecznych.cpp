#include <iostream>

double funkcja(double x) {
	return pow(x, 3) / 3 + 2.05 * pow(x, 2) - 9 * x + 15;
}
double pochodna(double x) {
	return pow(x, 2) + 4.1 * x - 9;
}
double pochodna2(double x) {
	return 2 * x + 4.1;
}
double pochodna3() {
	return 2;
}

void metodaBisekcji(int a, int b, double ep){
	if ((pochodna(a)*pochodna(b)) < 0) {
		double pocz = a;
		double kon = b;
		bool wyjscie = true;
		double xsr;
		int it = 1;

		while (wyjscie) {
			xsr = (pocz + kon) / 2;
			if (pochodna(xsr) == 0) {
				std::cout << "Wynik = " << xsr << std::endl;
				wyjscie = false;
				break;
			}
			if ((pochodna(xsr)*pochodna(pocz)) < 0) {
				kon = xsr;
			}
			else {
				pocz = xsr;
			}
			std::cout << "Iteracja: " << it << std::endl;
			std::cout << "Xsr = " << xsr <<  std::endl << std::endl;
			if (abs(pochodna(xsr)) < ep) {
				std::cout << "Wynik metody bisekcji = " << xsr << std::endl;
				wyjscie = false;
				break;
			}					
			it++;
		}
	}
	else {
		std::cout << "Warunek konieczny nie spelniony" << std::endl;
		return;
	}
}

void metodaStycznych(int a, int b, double ep) {
	if ((pochodna(a)*pochodna(b)) < 0) {
		if (pochodna2(a)*pochodna2(b) >= 0 && pochodna3() >= 0) {
			bool wyjscie = true;
			int it = 1;
			double x0;
			double x;

			if (pochodna3() * pochodna(a) >= 0) {
				x0 = a;
			}
			else {
				x0 = b;
			}

			while (wyjscie) {
				x = x0 - (pochodna(x0) / pochodna2(x0));

				std::cout << "Iteracja: " << it << std::endl;
				std::cout << "f'(x0) = " << pochodna(x0) << " f''(x0) = " << pochodna2(x0) << std::endl;
				std::cout << "f'(x0)/f''(x0) = "<< pochodna(x0) / pochodna2(x0) << std::endl;
				std::cout << "x = " << x << std::endl << std::endl;
				if (abs(pochodna(x)) < ep || abs(x - x0) < ep) {
					std::cout << "Pochodna x = " << abs(pochodna(x)) << "    roznica: " << abs(x - x0) << std::endl;
					std::cout << "Wynik metody stycznych = " << x << std::endl;
					wyjscie = false;
					break;
				}						
				x0 = x;
				it++;
			}
		}
	}
	else {
		std::cout << "Warunek konieczny nie spelniony" << std::endl;
		return;
	}
}

void metodaSiecznych(int a, int b, double ep){
	if ((pochodna(a)*pochodna(b)) < 0) {
		double x0;
		double x;
		bool wyjscie = true;
		int it = 1;
		bool nieruchomea = false;

		if (pochodna3() * pochodna(a) >= 0) {
			x0 = b;
			nieruchomea = true;
		}
		else {
			x0 = a;
		}
		while (wyjscie) {
			if (nieruchomea) {
				x = x0 - (pochodna(x0) / (pochodna(x0) - pochodna(a)))* (x0 - a);
			}
			else {
				x = x0 - (pochodna(x0) / (pochodna(b) - pochodna(x0)))* (b - x0);
			}
			std::cout << "Iteracja: " << it << std::endl;
			std::cout << "x = " << x << std::endl << std::endl;
			if (abs(pochodna(x)) < ep || abs(x - x0) < ep) {
				std::cout << "Wynik metody siecznych = " << x << std::endl;
				wyjscie = false;
				break;
			}
			x0 = x;
			it++;
		}
	}
	else {
	std::cout << "Warunek konieczny nie spelniony" << std::endl;
	return;
	}
}

int main()
{
	int a = -10;
	int b = -3;
	double epsilon = 0.00001;

	metodaBisekcji(a, b, epsilon);
	metodaStycznych(a, b, epsilon);
	metodaSiecznych(a, b, epsilon);

	return 0;
}

