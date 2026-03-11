find_package(unofficial-sodium CONFIG REQUIRED)

add_library(${CHAT_ENGINE_TARGET_NAME}

)

target_include_directories(${CHAT_ENGINE_TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ChatEngine
    PRIVATE
    unofficial-sodium::sodium
)