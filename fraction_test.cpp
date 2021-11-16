#include "fraction.h"
#include <iostream>

int main() {
	Fraction<int> a;
	Fraction<int> b;
	std::cin >> a >> b;
	std::cout << a << " " << b << std::endl;
	return 0;
}
