include(FetchContent)


FetchContent_Declare(
    wxwidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_TAG master
)

FetchContent_MakeAvailable(wxwidgets)

# add_library(flib
#     flib/db/db.cpp
# )

# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)

# target_link_libraries(flib
#     PUBLIC
#     SQLiteCpp
#     sqlite3
#     pthread
#     dl
# )

# target_include_directories(flib
#   PUBLIC
#   ${CMAKE_CURRENT_SOURCE_DIR}/flib/
# )

# target_compile_options(flib
#     PRIVATE
#     -Wall 
#     -Wextra 
#     -Wpedantic 
#     -Wconversion
#     -Wpessimizing-move
#     -Wredundant-move
#     -Wmove
#     -Wrange-loop-construct
# )

add_executable(flashy_cards 
  app/main.cpp
)

target_link_libraries(flashy_cards
    PRIVATE
    #flib
    wx::core wx::net wx::base wx::aui
)

# wx::core
# wx::base
# wx::net
# wx::html
# wx::base
# wx::gl 
# wx::xml
# wx::xrc