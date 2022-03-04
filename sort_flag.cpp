#include <algorithm>
#include <iterator>

#include "sort_flag.h"
#include "bylength_flag.h"

namespace sort{

    /**
     * prints sorted words from source file
     * if "-l" is present, prints words sorted by length
     */

    void sort_method(){

        std::cin.clear();
        std::cin.seekg(0);

        std::vector<std::string> result;

        for (auto word = std::string() ; std::cin >> word; ){
            result.push_back(word);
        }

        if (bylength::get_last_result() == 1) {
            std::sort(result.begin(), result.end(),
                      [](const std::string &left, const std::string &right) { return left.size() > right.size(); });
        }else {
            std::sort(result.begin(), result.end());
        }

        std::cin.clear();
        std::cin.seekg(0);

        for (const auto& r : result) {
            std::cout << '[' << r << ']' << ' ';
        }
        std::cout << '\n';
    }
}
