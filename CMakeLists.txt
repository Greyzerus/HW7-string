#cmake_minimum_required(VERSION 2.5)
project(HW7)

set(FLAGS )#-fsanitize=address) Для HW7_STRING Санитайзер выдаёт ошибку, валгринд молчит. ???
set(CMAKE_CXX_FLAGS "${FLAGS} -std=c++14 -Wall -fpermissive")

set(SOURCE_FILES)
add_executable(HW7 ${SOURCE_FILES_STRING} main.cpp sorted_vector.h)

set(SOURCE_FILES_STRING main_string.cpp MyString.cpp MyString.hpp nstrlen.cpp nstrlen.h)
add_executable(HW7_STRING ${SOURCE_FILES_STRING})

