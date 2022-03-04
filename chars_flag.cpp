#include "chars_flag.h"

namespace chars{

    /**
     * prints counted chars in a source file
     */

    void chars_method(){

        std::cin.clear();
        std::cin.seekg(0);

        int chars_counter = 0;
        for (char sign; std::cin >> sign;){
            chars_counter++;
        }
        std::cout << chars_counter << '\n';
    }
}