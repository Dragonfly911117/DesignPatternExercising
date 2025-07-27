#include "MessengerFactory.hpp"
#include "SMSSender.hpp"
#include "EmailSender.hpp"

MessengerFactory::MessengerFactory() {
    // Default creators for each messenger type
    _creators["email"] = []() { return std::make_shared<EmailSender>(); };
    _creators["sms"] = []() { return std::make_shared<SMSSender>(); };
}

std::shared_ptr<IMessenger> MessengerFactory::createMessenger(const std::string& type) const {
    if (const auto it = _creators.find(type); it != _creators.end()) {
        return it->second();
    }
    throw std::invalid_argument("Messenger type not registered");
}
