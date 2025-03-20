cmake_minimum_required(VERSION 3.2)

project(hash VERSION 1.0 LANGUAGES C)

add_executable(hash_list
hash.c
test.c
../../list/source/list_page.c
)