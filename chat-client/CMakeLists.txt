add_executable(${CHAT_CLIENT_TARGET_NAME}
    src/Main.cpp
)

target_include_directories(${CHAT_CLIENT_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CHAT_CLIENT_TARGET_NAME}
   PRIVATE
        ${CHAT_ENGINE_TARGET_NAME}
)