#include <iostream>

void printHello(const std::string& name)
{
    std::cout << "Hello " << name << std::endl;
}

const char* HSE = "HSE";

int main()
{
    printHello(HSE);
}
