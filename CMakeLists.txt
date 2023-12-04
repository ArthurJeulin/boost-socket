cmake_minimum_required(VERSION 3.21.8)
#Initialize for C++ Languages
set(CMAKE_CXX_COMPILER /usr/bin/g++-10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options( -std=c++20 -Wall -Wextra -Wpedantic)
endif()

project(BoostAsio  
        VERSION 1.0.0
        LANGUAGES CXX)

# enable_testing()
# add_subdirectory(test)
find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(Client src/Chapter1/Client.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(Client PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(Client PRIVATE ${Boost_LIBRARIES})


add_executable(Server src/Chapter1/Server.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(Server PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(Server PRIVATE ${Boost_LIBRARIES})


add_executable(ActiveSocket src/Chapter1/ActiveSocket.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(ActiveSocket PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(ActiveSocket PRIVATE ${Boost_LIBRARIES})

add_executable(PassiveSocket src/Chapter1/PassiveSocket.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(PassiveSocket PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(PassiveSocket PRIVATE ${Boost_LIBRARIES})


add_executable(ResolveDNS src/Chapter1/ResolveDNS.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(ResolveDNS PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(ResolveDNS PRIVATE ${Boost_LIBRARIES})

add_executable(BindServer src/Chapter1/BindServer.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(BindServer PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(BindServer PRIVATE ${Boost_LIBRARIES})


add_executable(Connecting src/Chapter1/Connecting.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(Connecting PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(Connecting PRIVATE ${Boost_LIBRARIES})

add_executable(ConnectionResolveDNS src/Chapter1/ConnectionResolveDNS.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(ConnectionResolveDNS PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(ConnectionResolveDNS PRIVATE ${Boost_LIBRARIES})

add_executable(server-accept src/Chapter1/server-accept.cpp)
# Liens avec les bibliothèques Boost nécessaires
target_include_directories(server-accept PRIVATE ${Boost_INCLUDE_DIRS})
# Vous pouvez également ajouter d'autres bibliothèques nécessaires
target_link_libraries(server-accept PRIVATE ${Boost_LIBRARIES})


# add_executable(output src/Chapter2/output.cpp)
# # Liens avec les bibliothèques Boost nécessaires
# target_include_directories(output PRIVATE ${Boost_INCLUDE_DIRS})
# # Vous pouvez également ajouter d'autres bibliothèques nécessaires
# target_link_libraries(output PRIVATE ${Boost_LIBRARIES})
