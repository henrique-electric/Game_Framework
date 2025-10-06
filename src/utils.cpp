#include "utils.hpp"

void abort(const char *str) {
    std::cerr << str << std::endl;
    exit(1);
}