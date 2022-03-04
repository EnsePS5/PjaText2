#include <fstream>

#include "newline_flag.h"

/**
 * prints how many lines are in source file
 */

namespace newline{
    void newline_method(){

        int number_of_lines = 0;

        std::cin.clear();
        std::cin.seekg(0);

        for (auto line = std::string(); std::getline(std::cin,line);){
            number_of_lines++;
        }
        std::cout << number_of_lines << '\n';
    }
}
