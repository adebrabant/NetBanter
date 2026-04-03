add_executable(${CHAT_CLIENT_TARGET_NAME}
    src/Main.cpp
    src/Application.cpp
    include/Application.hpp

    include/states/EnterState.hpp
    src/states/EnterState.cpp

    include/states/LoginState.hpp
    src/states/LoginState.cpp

    include/states/ChatState.hpp
    src/states/ChatState.cpp

    include/states/ExitState.hpp
    src/states/ExitState.cpp

    include/states/RegistrationState.hpp
    src/states/RegistrationState.cpp

    include/states/MainMenuState.hpp
    src/states/MainMenuState.cpp
)

target_include_directories(${CHAT_CLIENT_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CHAT_CLIENT_TARGET_NAME}
   PRIVATE
        ${CHAT_ENGINE_TARGET_NAME}
)