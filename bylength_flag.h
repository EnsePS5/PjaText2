#ifndef PROJECT_PJATEXT2_BYLENGTH_FLAG_H
#define PROJECT_PJATEXT2_BYLENGTH_FLAG_H

#include <iostream>
#include <vector>
#include <string>

namespace bylength{

    bool is_l_flag_given_correctly(const std::vector<std::string>& args);
    int where_l_flag_is_needed(const std::vector<std::string>& args, const int& index);
    int get_last_result();
    int get_last_index();
}

#endif //PROJECT_PJATEXT2_BYLENGTH_FLAG_H
