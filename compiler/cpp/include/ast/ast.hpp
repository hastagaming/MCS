#pragma once
#include <string>
#include <vector>
#include <memory>

namespace macs {

struct Node {
    virtual ~Node() = default;
};

struct Program : Node {
    std::vector<std::unique_ptr<Node>> items;
};

} // namespace macs