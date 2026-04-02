add_executable(${CHAT_CLIENT_TARGET_NAME}
    src/Main.cpp
    src/Application.cpp
    include/Application.hpp

    include/fsms/StateMachine.hpp
    src/fsms/StateMachine.cpp
    include/fsms/State.hpp

    include/fsms/EnterState.hpp
    src/fsms/EnterState.cpp

    include/fsms/LoginState.hpp
    src/fsms/LoginState.cpp

    include/fsms/ChatState.hpp
    src/fsms/ChatState.cpp

    include/fsms/ExitState.hpp
    src/fsms/ExitState.cpp

    include/fsms/RegistrationState.hpp
    src/fsms/RegistrationState.cpp

    include/fsms/MainMenuState.hpp
    src/fsms/MainMenuState.cpp
)

target_include_directories(${CHAT_CLIENT_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CHAT_CLIENT_TARGET_NAME}
   PRIVATE
        ${CHAT_ENGINE_TARGET_NAME}
)