#include <algorithm>
#include <iterator>

#include "revsort_flag.h"
#include "bylength_flag.h"

namespace revsort{

    /**
     * prints sorted and reversed lexically words from source file
     * if "-l" is present, prints words sorted and reversed by length
     */
    void revsort_method(){

        std::cin.clear();
        std::cin.seekg(0);

        std::vector<std::string> result;

        for (auto word = std::string() ; std::cin >> word; ){
            result.push_back(word);
        }

        if (bylength::get_last_result() == 2){
            std::sort(result.begin(), result.end(),
                      [](const std::string& left, const std::string& right){return left.size() > right.size();});
        } else {
            std::sort(result.begin(), result.end());
        }
        std::reverse(result.begin(), result.end());

        std::cin.clear();
        std::cin.seekg(0);

        for (const auto& r : result) {
            std::cout << '[' << r << ']' << ' ';
        }
        std::cout << '\n';
    }
}

