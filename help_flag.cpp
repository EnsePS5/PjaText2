#include "help_flag.h"

using std::vector,std::string;

/**
 * prints a help menu
 */

namespace help{
    void help_method(){
        std::cout << "||||||||||||||||||| THE PJATEXT2 HELP MENU |||||||||||||||||\n"
                     "(1) -> [-f] or [--file] + path to file --> the source file\n"
                     "(2) -> [-i] or [--input] + path to input file --> file where other arguments are written down\n"
                     "Must be implemented alone.\n"
                     "(3) -> [-n] or [--newline] --> counts lines in source file\n"
                     "(4) -> [-d] or [--digits] --> counts digits in source file\n"
                     "(5) -> [-dd] or [--numbers] --> counts numbers in source file between 2 blank spaces\n"
                     "(6) -> [-c] or [--chars] --> counts chars in source file\n"
                     "(7) -> [-w] or [--words] --> counts words in source file\n"
                     "(8) -> [-s] or [--sorted] --> prints all words in lexical order\n"
                     "(9) -> [-rs] or [--reverse-sorted] --> prints all words in lexical order but start from the end\n"
                     "(10) -> [-l] or [--by-length] + [-s] or [-rs] --> prints all words by length from the shortest do the longest\n"
                     "(11) -> [-a] or [--anagrams] + std::string (multiple times) --> prints all words from source file which are anagrams of given arguments\n"
                     "Must be the last flag.\n"
                     "(12) -> [-p] or [--palindromes] + std::string (multiple times) --> prints all words from source file which are palindromes of given arguments\n"
                     "Must be the last flag.\n"
                     "(13) -> [-o] or [--output] + path to file --> defines which file will save the result\n"
                     "(14) -> [-ds] or [--digits-sum] + char --> sums all digits in the source file\n";
    }
}
