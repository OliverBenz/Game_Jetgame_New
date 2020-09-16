find_file(SDL2_INCLUDE_DIR NAMES SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAMES SDL2)

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${DSL2_INCLUDE_DIR})

add_subdirectory(actors)
add_subdirectory(app)

target_link_libraries(main PRIVATE ${SDL2_LIBRARY})
target_link_libraries(main PRIVATE app)
target_link_libraries(main PRIVATE actors)
