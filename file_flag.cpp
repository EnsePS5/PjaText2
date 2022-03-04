#include <algorithm>
#include <filesystem>
#include <fstream>

#include "file_flag.h"

using std::vector,std::string,std::cout;

string file_to_read;
/**
 * check if given flag -> -f / --file exists and path is correct.
 * @param args - vector string value with given arguments.
 * @return bool value.
 */

namespace file {

    bool is_file_given_correctly(const vector<string> &args) {

        if (!(std::count(args.begin(), args.end(), "-f") == 0 && std::count(args.begin(), args.end(), "--file") == 1) &&
                !(std::count(args.begin(), args.end(), "-f") == 1 && std::count(args.begin(), args.end(), "--file") == 0)) {
            cout << "file is not given or it is given multiple times";
            return false;
        } else if(std::find(args.begin(), args.end(),"-f") != args.end()){
            const string f = *(std::find(args.begin(), args.end(), "-f") + 1);
            if (!std::filesystem::exists(f)){
                cout << "file path does not exist\n";
                return false;
            }
            file_to_read = f;
            return true;
            } else {
                const string file = *(std::find(args.begin(), args.end(), "--file") + 1);
            if (!std::filesystem::exists(file)){
                cout << "file path does not exist\n";
                return false;
                }
            file_to_read = file;
            return true;
        }
    }
    /**
     * typical getter
     * @return string with saved path
     */

    string get_file_in_path(){
        return file_to_read;
    }
}