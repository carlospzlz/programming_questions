add_executable(IsPalindromeTest is_palindrome_test.cc)
target_link_libraries(IsPalindromeTest is_palindrome)
target_link_libraries(IsPalindromeTest /usr/local/lib64/libgtest.a pthread)
