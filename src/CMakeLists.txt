add_library(flib
    flib/db/db.cpp
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)

target_link_libraries(flib
    PUBLIC
    SQLiteCpp
    sqlite3
    pthread
    dl
)

target_include_directories(flib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/flib/
)

target_compile_options(flib
    PRIVATE
    -Wall 
    -Wextra 
    -Wpedantic 
    -Wconversion
    -Wpessimizing-move
    -Wredundant-move
    -Wmove
    -Wrange-loop-construct
)

add_executable(flashy_cards 
  app/main.cpp
)

target_link_libraries(flashy_cards
    PRIVATE
    flib
)