#include "NotificationSender.hpp"
#include "DeliveryError.hpp"

void NotificationSender::deliver(const std::string& message) const {
    if (_messenger != nullptr) {
        _messenger->send(message);
        return;
    }
    throw DeliveryError("Messenger is not set");
}
