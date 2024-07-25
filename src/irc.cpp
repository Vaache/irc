#include "ircserv.hpp"

int main(int ac, char ** av) {
    (void)ac;
    (void)av;
    std::string str = "Hello World";
    std::cout << str << std::endl;
	std::vector<int> arr;

	
	for (int i = 0; i < 100; ++i) {
		arr.push_back(i);
	}

	for (unsigned long i = 0; i < arr.size(); ++ i) {
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
	return 0;
}