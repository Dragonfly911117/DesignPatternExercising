#include "EmailSender.hpp"

void EmailSender::send(const std::string& message) {
    sendEmail(message);
}

void EmailSender::sendEmail(const std::string& message) {
    std::cout << "Sending email: " << message << std::endl;
}
