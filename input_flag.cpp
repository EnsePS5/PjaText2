#include <algorithm>
#include <filesystem>
#include <fstream>

#include "input_flag.h"

using std::cout;


namespace input {

/**
 * checks if given flag -> -i / --input exists and path is correct.
 * @param args - vector string value with given arguments.
 * @return bool value.
 */
    string file_to_read;

    bool is_input_given_correctly(const vector<string> &args) {

        if ((std::count(args.begin(), args.end(), "-i") == 0 && std::count(args.begin(), args.end(), "--input")) != 1 && args.size() != 2 &&
            (std::count(args.begin(), args.end(), "-i") == 1 && std::count(args.begin(), args.end(), "--input")) != 0){
            cout << "input is not given or \"-i\" is not the only flag\n";
            return false;
        }else if(args[0] == "-i"){
            const string i = *(std::find(args.begin(), args.end(), "-i") + 1);
            if (!std::filesystem::exists(i)){
                cout << "input path does not exist\n";
                return false;
            }
            file_to_read = i;
            return true;
            } else {
                const string input = *(std::find(args.begin(), args.end(), "--input") + 1);
            if (!std::filesystem::exists(input)){
                cout << "input path does not exist\n";
                return false;
            }
            file_to_read = input;
            return true;
        }
    }

    /**
     * reads arguments from given earlier file and pushing them back into args vector
     * @param args - vector string value with given arguments
     */

    void set_new_read_file(vector<string>& args){
        auto read = std::fstream(args[1]);
        args.erase(args.begin(), args.end());
        for (auto arg = string(); read >> arg;) {
            args.push_back(arg);
        }
    }
}