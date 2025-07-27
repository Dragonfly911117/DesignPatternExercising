#include"gtest/gtest.h"

#include "DeliveryError.hpp"
#include "NotificationSender.hpp"
#include "MessengerFactory.hpp"

TEST(NotificationSenderTest, DeliverWithoutMessengerThrows) {
    NotificationSender notificationSender;
    const std::string message = "Hello, World!";
    EXPECT_THROW(notificationSender.deliver(message), DeliveryError);
}

TEST(NotificationSenderTest, DeliverWithEmailMessengerSucceeds) {
    const auto senderFactory = MessengerFactory();
    const auto emailSender = senderFactory.createMessenger("email");
    NotificationSender notificationSender;
    notificationSender.setMessenger(emailSender);
    const std::string message = "Hello, World!";
    EXPECT_NO_THROW(notificationSender.deliver(message));
}

TEST(NotificationSenderTest, DeliverWithSmsMessengerSucceeds) {
    const auto senderFactory = MessengerFactory();
    const auto smsSender = senderFactory.createMessenger("sms");
    NotificationSender notificationSender;
    notificationSender.setMessenger(smsSender);
    EXPECT_NO_THROW(notificationSender.deliver("Hello, World! via SMS"));
}


class mockSender final : public IMessenger {
public:
    std::string message;

    void send(const std::string& msg) override {
        message = msg;
    }
};

TEST(NotificationSenderTest, DeliverWithMockMessengerSucceeds) {
    auto senderFactory = MessengerFactory();
    senderFactory.registerMessenger("mock", []() {
        return std::make_shared<mockSender>();
    });
    const auto mock = senderFactory.createMessenger("mock");
    const auto message = "Hello, World! via Mock";
    const NotificationSender notificationSender(mock);
    notificationSender.deliver(message);

    EXPECT_EQ(std::dynamic_pointer_cast<mockSender>(mock)->message, message);
}

TEST(SenderFactoryTest, RegisterAndCreateMockMessenger) {
    auto senderFactory = MessengerFactory();
    senderFactory.registerMessenger("mock", []() {
        return std::make_shared<mockSender>();
    });
    const auto mock = senderFactory.createMessenger("mock");
    EXPECT_NE(mock, nullptr);
}

// Main function to run all tests

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
