//
// Created by df on 2025/7/27.
//

#ifndef SENDERFACTORY_HPP
#define SENDERFACTORY_HPP
#include <functional>
#include <memory>

#include "Messenger.hpp"

class MessengerFactory {
public:
    using CreatorFunc = std::function<std::shared_ptr<IMessenger>()>;

    // Constructors and Destructors

    /**
     * @brief Default Constructor registering creators for default messenger types
     * @see EmailSender, SMSSender
     **/
    MessengerFactory();

    // Setters

    // Getters

    // Methods

    /**
     *  @brief Register a messenger type with its creator function.
     *  *  This is used mainly for testing purposes.
     * @param type The type of the messenger to register.
     * @param creator The function that creates an instance of the messenger.
     * @see MessengerType
     * @see CreatorFunc
     **/
    void registerMessenger(const std::string& type, const CreatorFunc& creator) {
        _creators[type] = creator;
    }

    std::shared_ptr<IMessenger> createMessenger(const std::string& type) const;

private:
    std::unordered_map<std::string, CreatorFunc> _creators{};
};


#endif //SENDERFACTORY_HPP
