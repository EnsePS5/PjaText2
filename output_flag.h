#ifndef PROJECT_PJATEXT2_OUTPUT_FLAG_H
#define PROJECT_PJATEXT2_OUTPUT_FLAG_H

#include <iostream>
#include <vector>
#include <string>

using std::vector,std::string;

namespace output{
    bool is_output_given_correctly(const vector<string> &args);
    string get_file_out_path();
}

#endif //PROJECT_PJATEXT2_OUTPUT_FLAG_H
