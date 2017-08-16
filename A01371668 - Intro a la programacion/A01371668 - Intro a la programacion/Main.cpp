/****************************************************************
	Materia: 	Gráficas Computacionales
	Fecha :		14 / Agosto / 2017
	Autor :		A01371668 Alonso Issac Morales Gutiérrez
*****************************************************************/

#include <iostream>
#include <string>
using namespace std;

int PerimetroRectangulo(int base, int altura) {
	int p = (2 * base) + (2 * altura);
	return p;
}

float AreaTriangulo(float base, float altura) {
	float a = base * altura;
	return a;
}

int Mayor(int num1, int num2, int num3) {
	if (num1 > num2 && num1 > num3) {
		return num1;
	}
	if (num2 > num1 && num2 > num3) {
		return num2;
	}
	if (num3 > num1 && num3 > num2) {
		return num3;
	}
	return 0;
}

int Menor(int num1, int num2, int num3) {
	if (num1 < num2 && num1 < num3) {
		return num1;
	}
	if (num2 < num1 && num2 < num3) {
		return num2;
	}
	if (num3 < num1 && num3 < num2) {
		return num3;
	}
	return 0;
}

void FilaEstrellas(int n) {
	for (int i = 0; i <= n; i++) {
		std::cout << "*";
	}
	std::cout << "\n";
}

void MatrizEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << "*";
		}
	}
	std::cout << "\n";
}

void PiramideEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void FlechaEstrellas(int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (n - 2); j++) {
			std::cout << " ";
			for (int k = 1; k <= i; k++) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
		for (int a = n; a > 0; a--) {
			for (int b = 0; b < (n - 2); b++) {
				std::cout << " ";
				for (int c = 0; c < a; c++) {
					std::cout << "*";
				}
				std::cout << "\n";
			}
		}
	}
}

void Fibonacci(int n) {
	int a = 0;
	int b = 1;
	int c = 0;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			std::cout << " " << a;
			continue;
		}
		if (i == 2) {
			std::cout << b << " ";
			continue;
		}

		c = a + b;
		a = b;
		b = c;

		std::cout << c << " ";
	}

}

bool EsPrimo(int numero) {
	if (numero <= 1) {
		return false;
	}
	else {
		for (int i = 2; i*i < numero; i++) {
			if (numero%i == 0) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	return true;
}

int main() {
	cout << ("**********************RESULTADOS*********************\n\n");

	PerimetroRectangulo(5, 3);
	AreaTriangulo(5.0f, 3.0f);
	Mayor(5, 9, 1);
	Menor(5, 9, 1);
	FilaEstrellas(5);
	MatrizEstrellas(4);
	PiramideEstrellas(6);
	PiramideEstrellas(3);
	Fibonacci(9);
	EsPrimo(79);
	EsPrimo(52);

	getchar();
	return 0;
}