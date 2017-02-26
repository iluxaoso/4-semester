#include "Header.h"

int main()
{
	Vector2 a;
	Vector2 b;

	double c;
	std::cin >> a;
	//std::cin >> b;

	std::cin >> c;

	b = a.getRotated(c);

	std::cout << b << "\n";

	system("pause");
}