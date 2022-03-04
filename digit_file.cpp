#include "digit_flag.h"

namespace digit{

    /**
     * prints how many digits are in source file
     */

    void digit_method(){

        int digit_counter = 0;

        std::cin.clear();
        std::cin.seekg(0);

        for (char digit; std::cin >> digit;){
            if (digit >= 48 && digit <= 57)
            digit_counter++;
        }
        std::cout << digit_counter << '\n';
    }
}

