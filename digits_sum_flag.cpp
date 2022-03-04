#include "digits_sum_flag.h"

namespace digits_sum{

    /**
     * prints result of summed digits from the source file.
     */

    void digits_sum_method(){

        int digit_sum = 0;

        std::cin.clear();
        std::cin.seekg(0);

        for (char digit; std::cin >> digit;){
            if (digit >= 48 && digit <= 57) {
                switch (digit) {
                    case 48 :
                        digit_sum += 0;
                        break;
                    case 49 :
                        digit_sum += 1;
                        break;
                    case 50 :
                        digit_sum += 2;
                        break;
                    case 51 :
                        digit_sum += 3;
                        break;
                    case 52 :
                        digit_sum += 4;
                        break;
                    case 53 :
                        digit_sum += 5;
                        break;
                    case 54 :
                        digit_sum += 6;
                        break;
                    case 55 :
                        digit_sum += 7;
                        break;
                    case 56 :
                        digit_sum += 8;
                        break;
                    case 57 :
                        digit_sum += 9;
                        break;
                    default:;
                }
            }
        }
        std::cout << digit_sum << '\n';
    }
}