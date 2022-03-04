#ifndef PROJECT_PJATEXT2_FILE_FLAG_H
#define PROJECT_PJATEXT2_FILE_FLAG_H

#include <iostream>
#include <vector>
#include <string>

using std::vector,std::string;

namespace file {

    bool is_file_given_correctly(const vector<string> &args);
    string get_file_in_path();
}

#endif //PROJECT_PJATEXT2_FILE_FLAG_H
