set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(is_palindrome STATIC is_palindrome.cc)
add_library(are_anagram STATIC are_anagram.cc)
add_library(fibonacci STATIC fibonacci.cc)
add_library(baseball_game STATIC baseball_game.cc)
add_library(find_kth_largest STATIC find_kth_largest.cc)
add_library(rotate_matrix STATIC rotate_matrix.cc)
add_library(fixed_size_map STATIC fixed_size_map.cc)

add_executable(maze_generator maze_generator.cc)
add_executable(maze_diagonal_solver maze_diagonal_solver.cc)
