cmake_minimum_required(VERSION 3.12)
project(FdF C)

set(CMAKE_C_STANDARD 99)
#find_library(OPENGL OpenGL)
#find_library(APPKIT AppKit)
#find_library(MLX mlx)

AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(FdF
#set(SOURCE_FILES
#        ${SOURCE_FILES}
        ${LIBA}
        fdf.h
        main.c
        ft_size_list.c
        error.c
        save_map.c
        ft_atoi_fdf.c
        mogify_coords.c
        conclusion.c
        print_fdf.c)

link_libraries(libft/libftprintf.a)
#add_executable(clion ${SOURCE_FILES})
#target_link_libraries(clion ${CMAKE_SOURCE_DIR}/libft/libft.a ${MLX} ${OPENGL} ${APPKIT})