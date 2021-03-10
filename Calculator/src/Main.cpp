#include "Main.h"

int main()
{
	std::vector<std::string> vector;
	std::string str;
	char c = ' ';
	std::cout << "CALCULATOR" << std::endl;
	std::cout << std::endl << "Example: 77+-7; 5*3.141592" << std::endl;
	do
	{
		std::cout << "Insert your expression: " << std::endl;
		std::cin >> str;
		vector.reserve(str.length());
		if (store_values(vector, str) == true)
		{
			get_result(vector);
			std::cout << "The result is: " << vector[0] << std::endl;
		}
		vector.clear();
		std::cout << "Insert any key to exit or M to do maths again: ";
		std::cin >> c;
	} while (std::toupper(c) == 'M');
}
