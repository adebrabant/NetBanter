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

    include/sessions/Session.hpp
    include/sessions/SessionManager.hpp
    src/sessions/Session.cpp
    src/sessions/SessionManager.cpp
)

target_include_directories(${CHAT_ENGINE_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ChatEngine
    PRIVATE
    unofficial-sodium::sodium
)