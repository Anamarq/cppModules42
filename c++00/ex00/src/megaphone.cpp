#include <iostream>

std::string toUpper(const std::string& str)
{
	std::string res = str;
	for (int i = 0; i < (int)res.length(); ++i)
	{
		res[i] = std::toupper(res[i]);
	}
	return res;
}


//std::string toUpper(std::string str)
//{
//	std::string res;
//	//Bucle foreach. c es como str[c]
//	for (char c : str)
//		res += std::toupper(c);
//	return res;
//}

int main(int argc, char* argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << toUpper(argv[i]);
		}
		std::cout << std::endl;

	}
	return 0;
}