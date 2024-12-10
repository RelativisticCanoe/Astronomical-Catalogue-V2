#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

#include "control.h"

bool QUIT{false};

void UserInterface(){};

int main()
{
    std::string temp{""};
    std::cout << "Hello World!" << std::endl;
    std::cin >> temp;
    return 0;
}