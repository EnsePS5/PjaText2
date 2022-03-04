#include "words_flag.h"

namespace words{

    /**
     * prints how many words are in source file
     */

    void words_method(){

        std::cin.clear();
        std::cin.seekg(0);

        int words_counter = 0;

        for(auto word = std::string(); std::cin >> word; ){
            words_counter++;
        }
        std::cout << words_counter << '\n';
    }
}