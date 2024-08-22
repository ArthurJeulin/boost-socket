cmake_minimum_required(VERSION 3.21.8)
#Initialize for C++ Languages
set(CMAKE_CXX_COMPILER /usr/bin/g++-10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-std=c++20 -Wall -Wextra -Wpedantic)
endif()

project(boost-socket  
        VERSION 1.0.0
        LANGUAGES CXX)

# Indiquez à CMake d'utiliser les outils de vcpkg
set(CMAKE_TOOLCHAIN_FILE "/ssd/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(CURL REQUIRED)
find_package(glog REQUIRED)
find_package(fmt REQUIRED)
add_executable(Client src/Chapter1/Client.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(Client PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(Client ${Boost_LIBRARIES})
