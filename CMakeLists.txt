cmake_minimum_required(VERSION 3.14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

project(Gakkou VERSION 0.1 LANGUAGES CXX)

include(CTest)
include(GNUInstallDirs)

# Force default build type to Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

if(UNIX)
  option(BUILD_SHARED_LIBS "Build shared libraries(.so or .dylib)." ON)
	if(APPLE)
		set(CMAKE_INSTALL_RPATH "@loader_path;@loader_path/../${CMAKE_INSTALL_LIBDIR}")
	else()
		set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
	endif()
else()
  # only support for static build on Windows.
  set(BUILD_SHARED_LIBS OFF)
endif()

###########
# Sum app #
###########
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
add_executable(gakkou::sumApp ALIAS sumApp)
# Install
install(TARGETS sumApp
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )


# Install
include(GNUInstallDirs)
install(EXPORT ${PROJECT_NAME}Targets
  NAMESPACE gakkou::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Gakkou
  COMPONENT Devel)
include(CMakePackageConfigHelpers)
configure_package_config_file(cmake/GakkouConfig.cmake.in
  "${PROJECT_BINARY_DIR}/GakkouConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Gakkou"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/GakkouConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion)
install(
  FILES
  "${PROJECT_BINARY_DIR}/GakkouConfig.cmake"
  "${PROJECT_BINARY_DIR}/GakkouConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Gakkou"
  COMPONENT Devel)
