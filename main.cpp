//
// Created by greyzerus on 13.04.17.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "sorted_vector.h"
int main () {
    std::cout << "Put 10 ints: "<<std::flush;
    sorted_vector<int> example;
    int demo;
    for (int i=0; i<10; i++) {
        std::cin >> demo;
        example.insert(demo);
    }
    std::cout << "You put: "
              << example
              << "\nPut word number to access: "
              << std::flush;
    std:: cin >> demo;
    try {
        std::cout << "\nThe " << demo
                  << " number is " << example[demo] << std::endl;
    } catch (std::out_of_range &ex)
    {
        std::cout << "...\nSorry, but it's out of range." << std::endl;
        return -1;
    }
    return 0;
}



