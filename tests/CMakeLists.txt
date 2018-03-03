add_executable(Tests main.cc is_palindrome_test.cc)
target_link_libraries(Tests programming_questions)
target_link_libraries(Tests /usr/local/lib64/libgtest.a pthread)
