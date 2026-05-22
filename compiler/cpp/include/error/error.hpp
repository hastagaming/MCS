#pragma once
#include <string>

namespace macs {

struct McsError {
    int line;
    int column;
    int length;
    std::string message;
};

void print_error(const McsError& err, const std::string& source_line);

} // namespace macs