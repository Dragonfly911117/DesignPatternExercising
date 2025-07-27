//
// Created by df on 2025/7/27.
//

#ifndef NOTIFICATIONSENDER_HPP
#define NOTIFICATIONSENDER_HPP
#include <memory>

#include "Messenger.hpp"

class NotificationSender {
public:
    // Constors and Destructor

    /**
     * @brief Default constructor for NotificationSender.
     * Initializes the messenger to nullptr.
     * @warning This constructor does not set a messenger,
     * so any attempt to deliver a message will throw an error.
     */
    NotificationSender() = default;

    explicit NotificationSender(const std::shared_ptr<IMessenger>& messenger): _messenger(messenger) {
    }

    // Setters

    void setMessenger(const std::shared_ptr<IMessenger>& messenger) {
        _messenger = messenger;
    }

    // Getters

    // Methods

    /**
     * @brief Deliver a message using the set messenger.
     * @param message The message to be delivered.
     * @throws DeliveryError if the messenger is not set.
     */
    void deliver(const std::string& message) const;

private:
    std::shared_ptr<IMessenger> _messenger;
};

#endif //NOTIFICATIONSENDER_HPP
