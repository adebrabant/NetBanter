cmake_minimum_required(VERSION 3.29.3)

project(NetBanter
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD           20)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CHAT_ENGINE_TARGET_NAME         ChatEngine)
set(CHAT_SERVER_TARGET_NAME         ChatServer)
set(CHAT_CLIENT_TARGET_NAME         ChatClient)
set(CHAT_ENGINE_TESTS_TARGET_NAME   ChatEngine.Tests)

enable_testing()

add_subdirectory(chat-engine)
add_subdirectory(chat-server)
add_subdirectory(chat-client)
add_subdirectory(chat-engine-tests)