#include <windows.h>
#include <iostream>


int main() {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	std::cout << screenWidth << std::endl;
	std::cout << screenHeight << std:: endl;
}