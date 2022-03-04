#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "file_flag.h"
#include "input_flag.h"
#include "help_flag.h"
#include "newline_flag.h"
#include "output_flag.h"
#include "digit_flag.h"
#include "numbers_flag.h"
#include "chars_flag.h"
#include "words_flag.h"
#include "sort_flag.h"
#include "revsort_flag.h"
#include "bylength_flag.h"
#include "anagrams_flag.h"
#include "palindromes_flag.h"
#include "digits_sum_flag.h"

using std::cout,std::cin,std::vector,std::string;

/**
 * checks witch args are implemented in function and witch are not
 * @param args - vector string value with given arguments
 * @return - prints a message and returns std::map of implemented arguments
 */

auto witch_args_are_included_in_program(const vector<string>& args) {

    const auto implemented_arguments = vector<string>{
            "","-f", "-n", "-d", "-dd", "-c", "-w", "-s", "-rs", "-l", "-a", "-o", "-p", "-i", "--file",
            "--newlines",
            "--digits", "--numbers", "--chars", "--words", "--sorted", "--reverse-sorted", "--by-length", "--anagrams",
            "--output",
            "--palindromes", "--input","--help","-ds","--digits-sum"};
    //TODO CREATE YOUR OWN FLAG

    auto result = std::map<string,int>();

    for (int i = 0; i < implemented_arguments.size(); ++i) {
        result[implemented_arguments[i]] = i;
    }

        for (const auto &v : args) {
            if (std::find(implemented_arguments.begin(), implemented_arguments.end(), v) ==
                implemented_arguments.end()) {
                if (*(v.begin()+1) == ':') cout << v << "\n--- Path will be checked later --- \n";
                else cout << v << " -> this argument is not implemented in program. It won't be executed.\n";
            } else {
                cout << v << " -> checked! \n";
            }
        }
        cout << "------------------------------------------------\n";
    return result;
}

int main(int args_count, const char* args[]) {

    //
    // DEFINING WITCH ARGUMENTS MUST BE EXECUTED AND FROM WITCH FILE.
    //

    auto arguments = std::vector<std::string>(args + 1, args + args_count);
    if (arguments.empty()) {
        help::help_method();
        return -1;
    }
    //
    // THE ERROR MUST BE FOUND BEFORE FLAGS EXECUTION --> ALL POSSIBLE ERRORS ARE BEING CHECKED BELOW.
    //

    if (input::is_input_given_correctly(arguments)) {
        input::set_new_read_file(arguments);
        if (arguments.empty()) {
            help::help_method();
            return -1;
        }
    } else if (
            std::count(arguments.begin(), arguments.end(), "-i") > 0 ||
            std::count(arguments.begin(), arguments.end(), "--input") > 0) {
        return -1;
    }
    if (bylength::is_l_flag_given_correctly(arguments)){
        return -1;
    }
    if (!anagrams::is_anagrams_the_last_flag(arguments)){
        return -1;
    }
    if (!palindromes::is_palindromes_the_last_flag(arguments)){
        return -1;
    }
    auto flags_to_do = witch_args_are_included_in_program(arguments);

    //This one applies fully to "-n -d -dd -c -w -s -rs" and partially "-l -a -p -o"

    std::ifstream file_in;
    if (!file::is_file_given_correctly(arguments)) {
        return -1;
    } else {
        file_in.open(file::get_file_in_path());
        cin.rdbuf(file_in.rdbuf());
    }
    std::ofstream file_out;
    if (output::is_output_given_correctly(arguments)) {
        file_out.open(output::get_file_out_path());
        cout.rdbuf(file_out.rdbuf());
    }

    for (int i = 0; i < arguments.size(); ++i) {
        switch (flags_to_do[arguments[i]]) {
            case 0 : break;
            case 1 :
            case 14 :
                cout << "file loaded\n";
                i++;
                break;
            case 2 :
            case 15 :
                cout << arguments[i] << " --> ";
                newline::newline_method();
                break;
            case 3 :
            case 16 :
                cout << arguments[i] << " --> ";
                digit::digit_method();
                break;
            case 4 :
            case 17 :
                cout << arguments[i] << " --> ";
                numbers::numbers_method();
                break;
            case 5 :
            case 18 :
                cout << arguments[i] << " --> ";
                chars::chars_method();
                break;
            case 6 :
            case 19 :
                cout << arguments[i] << " --> ";
                words::words_method();
                break;
            case 7 :
            case 20 :
                cout << arguments[i] << " --> ";
                sort::sort_method();
                break;
            case 8 :
            case 21 :
                cout << arguments[i] << " --> ";
                revsort::revsort_method();
                break;
            case 9 :
            case 22 :
                cout << arguments[i] << " --> ";
                if (bylength::where_l_flag_is_needed(arguments,i) == 0){
                    return -1;
                } else
                    i = bylength::get_last_index();
                break;
            case 10 :
            case 23 :
                cout << arguments[i] << " --> ";
                anagrams::anagrams_method(arguments);
                break;
            case 11 :
            case 24 :
                break;
            case 12 :
            case 25 :
                cout << arguments[i] << " --> ";
                palindromes::palindromes_method(arguments);
                break;
            case 13 :
            case 26 :
                break;
            case 27 :
                help::help_method();
                break;
            case 28 :
            case 29 :
                cout << arguments[i] << " --> ";
                digits_sum::digits_sum_method();
                break;
            default :;
        }
    }
}

