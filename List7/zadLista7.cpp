#include <iostream>
#include "exercise1.cpp"
#include "exercise2.cpp"

int main()
{
	char userChoice = 'y';
	while(userChoice == 'y')
	{
		exercise1();
		exercise2();
		std::cout << "Do you wish to repeat? Y/n: ";
		std::cin >> userChoice;
	}
	return 0;
}

