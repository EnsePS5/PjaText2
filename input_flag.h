#ifndef PROJECT_PJATEXT2_INPUT_FLAG_H
#define PROJECT_PJATEXT2_INPUT_FLAG_H

#include <iostream>
#include <vector>
#include <string>

using std::vector,std::string;
namespace input {

    bool is_input_given_correctly(const vector<string> &args);
    void set_new_read_file(vector<string>& args);
}

#endif //PROJECT_PJATEXT2_INPUT_FLAG_H
