//
// Created by df on 2025/7/27.
//

#ifndef SMSSENDER_HPP
#define SMSSENDER_HPP
#include <iostream>

class SMSSender final : public IMessenger {
public:
    void send(const std::string& message) override {
        sendSMS(message);
    }

    static void sendSMS(const std::string& message) {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};
#endif //SMSSENDER_HPP
