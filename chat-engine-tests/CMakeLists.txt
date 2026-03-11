add_executable(${CHAT_ENGINE_TESTS_TARGET_NAME}
    src/users/UserTests.cpp
    src/users/UserRepositoryTests.cpp
    src/authentications/AuthResultTests.cpp
    src/authentications/AuthenticatorTests.cpp
    src/authentications/PasswordHasherTests.cpp
)

target_include_directories(${CHAT_ENGINE_TESTS_TARGET_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${CHAT_ENGINE_TESTS_TARGET_NAME}
    PRIVATE
        ${CHAT_ENGINE_TARGET_NAME}
        GTest::gtest
        GTest::gtest_main
)

add_test(NAME ChatEngine.Tests COMMAND ${CHAT_ENGINE_TESTS_TARGET_NAME})