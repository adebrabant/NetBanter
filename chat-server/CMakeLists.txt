add_executable(${CHAT_SERVER_TARGET_NAME}
    src/Main.cpp
    src/Server.cpp
    include/Server.hpp

    include/sessions/Session.hpp
    src/sessions/Session.cpp

    include/fsms/SessionStateMachine.hpp
    src/fsms/SessionStateMachine.cpp
    include/fsms/SessionState.hpp
    include/fsms/UnauthenticatedState.hpp
    src/fsms/UnauthenticatedState.cpp
    include/fsms/AuthenticatedState.hpp
    src/fsms/AuthenticatedState.cpp
)

target_include_directories(${CHAT_SERVER_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CHAT_SERVER_TARGET_NAME}
   PRIVATE
        ${CHAT_ENGINE_TARGET_NAME}
)