//
// Created by df on 2025/7/27.
//

#ifndef DILVERYERROR_HPP
#define DILVERYERROR_HPP
#include <stdexcept>

class DeliveryError final : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};
#endif //DILVERYERROR_HPP
