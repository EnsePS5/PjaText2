#include <fstream>
#include <filesystem>
#include <iostream>

#include "output_flag.h"

using std::cout;

string file_to_write;

namespace output{

    /**
     * checks if given flag -> -o / --output exists and path is correct.
     * If not, creates a file using given path
     * @param args - vector string value with given arguments.
     * @return bool value.
     */

    bool is_output_given_correctly(const vector<string> &args){
        if (std::count(args.begin(), args.end(), "-o") != 1 && std::count(args.begin(), args.end(), "--output") != 1){
            return false;
        }else if(std::find(args.begin(), args.end(),"-o") != args.end()){
            const string o = *(std::find(args.begin(), args.end(), "-o") + 1);
            if (!std::filesystem::exists(o)){
                cout << "output path does not exist. Created new file if it was possible\n";
            }
            file_to_write = o;
        } else {
            const string output = *(std::find(args.begin(), args.end(), "--output") + 1);
            if (!std::filesystem::exists(output)){
                cout << "output path does not exist. Created new file if it was possible\n";
            }
            file_to_write = output;
        }
        return true;
    }

    /**
     * typical getter
     * @return string with saved path
     */

    string get_file_out_path(){
        return file_to_write;
    }
}