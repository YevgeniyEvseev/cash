cmake_minimum_required(VERSION 3.2)

project(Cash VERSION 1.0 LANGUAGES C)

add_executable(cash 
main.c 
cash.c 
hash/source/hash.c 
list/source/list_page.c
)

add_executable(cash_test 
test.c 
cash.c 
hash/source/hash.c 
list/source/list_page.c
)

target_link_libraries(cash_test PRIVATE check subunit rt pthread m)