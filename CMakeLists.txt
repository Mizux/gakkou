cmake_minimum_required(VERSION 3.5)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
project(Gakkou VERSION 0.1 LANGUAGES CXX)

##############################
##  COMPILATION PARAMETERS  ##
##############################
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/usr/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/usr/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/usr/bin)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

##########################
##  INSTALL PARAMETERS  ##
##########################
# Offer the user the choice of overriding the installation directories
set(CMAKE_INSTALL_PREFIX install)
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib:$ORIGIN/")

###########
##  DOC  ##
###########
option(ENABLE_DOC "Compile doxygen documentation" OFF)
if(ENABLE_DOC)
  add_subdirectory(doc)
endif()



# Qt Setting
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5  REQUIRED COMPONENTS Core Gui Widgets)
#find_package(Qt5  REQUIRED COMPONENTS 3DRender 3DCore 3DInput 3DExtras)

file(GLOB_RECURSE _SRCS "src/*.[hc]pp")
file(GLOB_RECURSE _QRCS "data/*.qrc")

add_executable(sumApp ${_SRCS} ${_QRCS})
target_link_libraries(sumApp Qt5::Core Qt5::Gui Qt5::Widgets)
#target_link_libraries(sumApp Qt5::3DCore Qt5::3DRender Qt5::3DInput Qt5::3DExtras)

#install(TARGETS sumApp DESTINATION bin)
