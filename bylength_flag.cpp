#include <algorithm>

#include "bylength_flag.h"

namespace bylength{

    int last_result = 0,current_index = 0;

    /**
     * checks if given "-l" flag is correctly implemented to the program
     * @param args - vector string value with given arguments.
     * @return bool value
     */

    bool is_l_flag_given_correctly(const std::vector<std::string>& args){
        if (std::find(args.begin(), args.end(),"-l") == args.end() || std::find(args.begin(), args.end(),"--by-length") == args.end()){
            return false;
        }
        for (int i = 0; i < args.size(); ++i) {
            if (args[i] == "-l" || args[i] == "--by-length") {
                if (!(args[i + 1] != "-s" || args[i + 1] != "-rs" || args[i + 1] != "--sorted" ||
                    args[i + 1] != "--reverse-sorted"
                    || args[i + 1] != "-l" || args[i + 1] != "--by-length")) {
                    std::cout << "given argument after \"-l\" is wrong. Make sure you inserted correct flag\n";
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * setting suitable variables for usage in -s or -rs
     * @param args - vector string value with given arguments.
     * @param index - index location where -l was found
     * @return integer value witch is needed in further implementations
     */

    int where_l_flag_is_needed(const std::vector<std::string>& args, const int& index){

        current_index = index;

        while (true) {
            if (args[current_index + 1] == "-l" || args[current_index + 1] == "--by-length") {
                ++current_index;
            } else if (args[current_index + 1] == "-s" || args[current_index + 1] == "--sorted"){
                last_result = 1;
                return 1;
            } else if (args[current_index + 1] == "-rs" || args[current_index + 1] == "--reverse-sorted"){
                last_result = 2;
                return 2;
            }
        }
    }

    /**
     * typical getter
     * @return int value of result in 'where_is_l_flag_needed'
     */
    int get_last_result(){
        return last_result;
    }
    /**
     * typical getter
     * @return int value of index where the function 'where_is_l_flag_needed' stopped
     */
    int get_last_index(){
        return current_index;
    }
}

