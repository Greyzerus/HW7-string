#include <iostream>
#include <cstdlib>
#include "MyString.hpp"
int main() {
    MyString string;
    std::cout << "Enter new string: " << std::flush;
    std::cin.clear();
    try {
        std::cin >> string;
    } catch (std::bad_alloc &ex)
    {
        return -1;
    }
    std::cout << "Your string: " << string
            << "\n Enter new string to contatenate: " << std::flush;
    MyString string2;
    try {
        std::cin >> string2;
    } catch (std::bad_alloc &ex)
    {
        return -1;
    }
    std::cout << "Contatenated strings:\n'+': " << string+string2 <<std::endl;
    std::cout<< "'+=': " << (string+=string2) << std::endl;
    return 0;
}