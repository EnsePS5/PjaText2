#include <algorithm>

#include "anagrams_flag.h"

namespace anagrams{

    /**
     * checks if "-a" is the only and the last flag.
     * @param args - vector string value with given arguments.
     * @return bool value
     */

   bool is_anagrams_the_last_flag(const std::vector<std::string>& args){

       auto flag_position = std::find_if(args.begin(), args.end(), [](const std::string& flag){return (flag == "-a" || flag == "--anagrams");});
       if (flag_position == args.end()){
           return true;
       }

        if (!(std::count(args.begin(), args.end(), "-a") == 1 && std::count(args.begin(), args.end(), "--anagrams") == 0) &&
                !(std::count(args.begin(), args.end(), "-a") == 0 && std::count(args.begin(), args.end(), "--anagrams") == 1)){
            std::cout << "the \"-a\" is not the only \"-a\" type flag as it should be\n";
            return false;
        }else if (std::find_if((flag_position + 1),args.end(), [](const std::string& flag){return flag.find('-') != std::string::npos;}) == args.end()){
            return true;
        } else {
            std::cout << "the \"-a\" flag is not the last one\n";
            return false;
        }
    }

    /**
     * checks if a word in source file is an anagram of one of given arguments after "-a" flag.
     * Also prints the results.
     * @param args - vector string value with given arguments.
     */

    void anagrams_method(const std::vector<std::string>& args){

        auto flag_position = std::find_if(args.begin(), args.end(), [](const std::string& flag){return (flag == "-a" || flag == "--anagrams");});
        std::vector<std::string> anagrams;

        for (auto i = flag_position + 1; i < args.end(); i++) {
            anagrams.push_back(*i);
        }

        for (auto & anagram : anagrams) {

            std::cin.clear();
            std::cin.seekg(0);

            std::vector<std::string> unique_anagrams;

            for (auto word = std::string(); std::cin >> word; ){
                if (std::is_permutation(anagram.begin(), anagram.end(),word.begin(),word.end())){
                    if (std::find(unique_anagrams.begin(), unique_anagrams.end(),word) == unique_anagrams.end()){
                        unique_anagrams.push_back(word);
                        std::cout << word << ' ';
                    }
                }
            }
        }
        std::cout << '\n';
    }
}