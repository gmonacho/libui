cmake_minimum_required(VERSION 3.10)
project(e_libui C)
# set (CMAKE_C_COMPILER "/usr/bin/gcc")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_files/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libft/includes ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

set(LIBRARIES ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} -L${CMAKE_CURRENT_SOURCE_DIR}/libft/ -lft)



add_executable(${PROJECT_NAME} src/button/ui_button.c
src/event/ui_event.c
src/shape/ui_rect.c
src/texture/ui_texture.c
src/win/ui_display_buttons.c
src/win/ui_update_buttons.c
src/win/ui_win.c
src/main.c
src/ui_error.c
src/ui_init.c)



target_link_libraries(${PROJECT_NAME} ${LIBRARIES})