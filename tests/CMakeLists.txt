set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

add_executable(is_palindrome_test is_palindrome_test.cc)
target_link_libraries(is_palindrome_test is_palindrome)
target_link_libraries(is_palindrome_test /usr/local/lib64/libgtest.a pthread)

add_executable(first_non_repeated_test first_non_repeated_test.cc)
target_link_libraries(first_non_repeated_test /usr/local/lib64/libgtest.a pthread)

add_executable(are_anagram_test are_anagram_test.cc)
target_link_libraries(are_anagram_test are_anagram)
target_link_libraries(are_anagram_test /usr/local/lib64/libgtest.a pthread)

add_executable(fibonacci_test fibonacci_test.cc)
target_link_libraries(fibonacci_test fibonacci)
target_link_libraries(fibonacci_test /usr/local/lib64/libgtest.a pthread)

add_executable(baseball_game_test baseball_game_test.cc)
target_link_libraries(baseball_game_test baseball_game)
target_link_libraries(baseball_game_test /usr/local/lib64/libgtest.a pthread)

add_executable(find_kth_largest_test find_kth_largest_test.cc)
target_link_libraries(find_kth_largest_test find_kth_largest)
target_link_libraries(find_kth_largest_test /usr/local/lib64/libgtest.a pthread)

add_executable(rotate_matrix_test rotate_matrix_test.cc)
target_link_libraries(rotate_matrix_test rotate_matrix)
target_link_libraries(rotate_matrix_test /usr/local/lib64/libgtest.a pthread)
