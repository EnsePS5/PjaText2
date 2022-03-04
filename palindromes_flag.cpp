#include <algorithm>

#include "palindromes_flag.h"

namespace palindromes{

    /**
     * checks if "-p" is the only and the last flag.
     * @param args - vector string value with given arguments.
     * @return bool value
     */

    bool is_palindromes_the_last_flag(const std::vector<std::string>& args){

        auto flag_position = std::find_if(args.begin(), args.end(), [](const std::string& flag){return (flag == "-p" || flag == "--palindromes");});
        if (flag_position == args.end()){
            return true;
        }

        if (!(std::count(args.begin(), args.end(), "-p") == 1 && std::count(args.begin(), args.end(), "--palindromes") == 0) &&
            !(std::count(args.begin(), args.end(), "-p") == 0 && std::count(args.begin(), args.end(), "--palindromes") == 1)){
            std::cout << "the \"-p\" is not the only \"-p\" type flag as it should be\n";
            return false;
        }else if (std::find_if((flag_position + 1),args.end(), [](const std::string& flag){return flag.find('-') != std::string::npos;}) == args.end()){
            return true;
        } else {
            std::cout << "the \"-p\" flag is not the last one\n";
            return false;
        }
    }

    /**
     * checks if a word in source file is a palindrome of one of given arguments after "-p" flag.
     * Also prints the results.
     * @param args - vector string value with given arguments.
     */

    void palindromes_method(const std::vector<std::string>& args){

        auto flag_position = std::find_if(args.begin(), args.end(), [](const std::string& flag){return (flag == "-p" || flag == "--palindromes");});
        std::vector<std::string> palindromes;

        for (auto i = flag_position + 1; i < args.end(); ++i) {
            palindromes.push_back(*i);
        }

        for (int k = 0; k < palindromes.size(); ++k) {
            for (int i = 0, j = palindromes[k].size()-1; i < j; ++i, --j) {
                if (palindromes[k][i] != palindromes[k][j]) {
                    palindromes.erase(palindromes.begin() + k);
                    k--;
                    break;
                }
            }
        }

        std::cin.clear();
        std::cin.seekg(0);

        std::vector<std::string> unique_palindromes;

        for (auto word = std::string(); std::cin >> word; ){
                for (int i = 0, j = word.size()-1; i < j ; ++i , --j) {
                    if (word[i] != word[j]){
                        break;
                }
            }
            if (std::find(palindromes.begin(), palindromes.end(),word) != palindromes.end()){
                if (std::find(unique_palindromes.begin(), unique_palindromes.end(),word) == unique_palindromes.end()) {
                    unique_palindromes.push_back(word);
                    std::cout << word << ' ';
                }
            }
        }
    }
}