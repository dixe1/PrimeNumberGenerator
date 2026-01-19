//
// Created by bartek on 1/19/26.
//

#ifndef CPP_PROJECT_TEMPLATE_CLEARTERMINAL_H
#define CPP_PROJECT_TEMPLATE_CLEARTERMINAL_H

#endif //CPP_PROJECT_TEMPLATE_CLEARTERMINAL_H

#include "iostream"

namespace localTools {
    void inline clearTerm() {
        std::cout << "\033[2J\033[H" << std::flush;
    }
}