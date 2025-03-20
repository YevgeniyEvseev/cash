cmake_minimum_required(VERSION 3.2)

project(list VERSION 1.0 LANGUAGES C )

add_executable(list_main
main.c
list_page.c
)

add_executable(test_list 
list_page.c
test.c 
)

target_link_libraries(test_list PRIVATE check subunit rt pthread m)