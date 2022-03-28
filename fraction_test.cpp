#include "fraction.h"

int main() {
	Fraction a;
	Fraction b;

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
	
	return 0;
}
