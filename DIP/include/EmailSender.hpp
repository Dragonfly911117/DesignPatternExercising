//
// Created by df on 2025/7/27.
//

#ifndef EMAILSENDER_HPP
#define EMAILSENDER_HPP
#include <iostream>
#include <string>

#include "Messenger.hpp"

class EmailSender final : public IMessenger {
public:
    void send(const std::string& message) override;

private:
    static void sendEmail(const std::string& message);
};
#endif //EMAILSENDER_HPP
