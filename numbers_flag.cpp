#include <algorithm>

#include "numbers_flag.h"

namespace numbers{

    /**
     * prints how many numbers are in source file that is between 2 blank spaces.
     */

    void numbers_method(){

        int numbers_counter = 0;

        std::cin.clear();
        std::cin.seekg(0);

        for(auto number = std::string(); std::cin >> number;){
            if (std::count_if(number.begin(), number.end(),[number](char digit){return (((digit >= 48 && digit <= 57)||
            (digit == 46)) && (number.front() >= 48 && number.front() <= 57 && number.back() >= 48 && number.back() <= 57));})){
                numbers_counter++;
            }
        }
        std::cout << numbers_counter << '\n';
    }
}
