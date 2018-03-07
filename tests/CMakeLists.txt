add_executable(is_palindrome_test is_palindrome_test.cc)
target_link_libraries(is_palindrome_test is_palindrome)
target_link_libraries(is_palindrome_test /usr/local/lib64/libgtest.a pthread)

add_executable(first_non_repeated_test first_non_repeated_test.cc)
target_link_libraries(first_non_repeated_test /usr/local/lib64/libgtest.a pthread)
