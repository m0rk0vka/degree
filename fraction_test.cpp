#include "fraction.h"

int main() {
	Fraction<int> a(2,3);
	Fraction<int> b;
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	std::cout << "-" << a << " + " << b << " = " << (-a + b) << std::endl;
	std::cout << "-" << a << " - " << b << " = " << (-a - b) << std::endl;
	std::cout << "-" << a << " * " << b << " = " << (-a * b) << std::endl;
	std::cout << "-" << a << " / " << b << " = " << (-a / b) << std::endl;
	std::cout << "-" << a << " + " << "-" << b << " = " << (-a + -b) << std::endl;
	std::cout << "-" << a << " - " << "-" << b << " = " << (-a - -b) << std::endl;
	std::cout << "-" << a << " * " << "-" << b << " = " << (-a * -b) << std::endl;
	std::cout << "-" << a << " / " << "-" << b << " = " << (-a / -b) << std::endl;
	std::cout << a << " + " << "-" << b << " = " << (a + -b) << std::endl;
	std::cout << a << " - " << "-" << b << " = " << (a - -b) << std::endl;
	std::cout << a << " * " << "-" << b << " = " << (a * -b) << std::endl;
	std::cout << a << " / " << "-" << b << " = " << (a / -b) << std::endl;

	b -= a;
	std::cout << b << std::endl;

	b = Fraction<int>(3,4);

	b -= a * Fraction<int>(3, 1);
	std::cout << b << std::endl;

	b = Fraction<int>(3,4);
	b -= (a * Fraction<int>(3, 1));
	std::cout << b << std::endl;

	return 0;
}
