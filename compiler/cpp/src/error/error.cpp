#include "errors/error.hpp"
#include <iostream>

namespace macs {

void print_error(const McsError& err, const std::string& source_line) {
    std::cerr << "[MCS-ERROR-" << err.line << "]:\n";
    std::cerr << err.message << "\n\n";
    std::cerr << err.line << " | " << source_line << "\n";
    std::cerr << "  | ";
    for (int i = 0; i < err.column; ++i) std::cerr << ' ';
    for (int i = 0; i < err.length; ++i) std::cerr << '^';
    std::cerr << "\n";
}

} // namespace macs