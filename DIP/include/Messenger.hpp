//
// Created by df on 2025/7/27.
//

#ifndef MESSAGESENDER_HPP
#define MESSAGESENDER_HPP
#include <string>

class IMessenger {
public:
    virtual ~IMessenger() = default;
    virtual void send(const std::string& message) = 0;
};
#endif //MESSAGESENDER_HPP
