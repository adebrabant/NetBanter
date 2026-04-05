find_package(unofficial-sodium CONFIG REQUIRED)

add_library(${CHAT_ENGINE_TARGET_NAME}
    include/authentications/PasswordHasher.hpp
    include/authentications/Authenticator.hpp
    include/authentications/AuthResult.hpp
    src/authentications/Authenticator.cpp
    src/authentications/PasswordHasher.cpp
    src/authentications/AuthResult.cpp

    include/users/User.hpp
    include/users/UserRepository.hpp
    src/users/User.cpp
    src/users/UserRepository.cpp

    include/clients/Client.hpp
    include/clients/ClientManager.hpp
    src/clients/Client.cpp
    src/clients/ClientManager.cpp

    include/messages/Message.hpp
    include/messages/Messenger.hpp
    include/messages/DeliveryResult.hpp
    src/messages/Message.cpp
    src/messages/Messenger.cpp
    src/messages/DeliveryResult.cpp

    include/networks/TcpSocket.hpp
    include/networks/TcpServer.hpp
    include/networks/NetworkSystem.hpp
    src/networks/TcpSocket.cpp
    src/networks/TcpServer.cpp
    src/networks/NetworkSystem.cpp

    include/parsers/CommandParser.hpp
    src/parsers/CommandParser.cpp

    include/fsms/StateMachine.hpp
    src/fsms/StateMachine.cpp

    include/states/State.hpp
)

target_include_directories(${CHAT_ENGINE_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ChatEngine
    PRIVATE
    unofficial-sodium::sodium
)