# mkdir build
# cd build
# cmake -DCMAKE_INSTALL_PREFIX=/home/fernando/testing ..
# make
# make install

cmake_minimum_required(VERSION 3.5) 
include(GNUInstallDirs)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")
set (CMAKE_CXX_STANDARD 11)

################################################################################
## Describing the project
################################################################################
project(example-single-program 
        LANGUAGES CXX
        VERSION 0.0.1
)

set(PROJECT_DESCRIPTION       "C++ example")
set(PROJECT_COMMENT           "A very simple example")
set(PROJECT_URL               "https://somesite.com")
set(PROJECT_URL_INFO          "https://somesite.com")
set(PROJECT_URL_HELP          "https://somesite.com")
set(PROJECT_AUTHOR            "Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>")
set(PROJECT_VENDOR            "Nickname")
set(DEBPACK_SECTION           "education")
# Deb file indicates that need to run
set(DEBPACK_REQUIRES          "libpdsramm-dev")# "libpdsramm-dev, libpdsba-dev") # Acording deb names
# Libraries need to compile the program and tests
set(TARGET_EXTRA_LINK         "pdsramm")


################################################################################
## Architecture
################################################################################
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    # set(LIBSUFFIX "64") 
    set(DEBFILE_ARCH "amd64")
else() 
    # set(LIBSUFFIX "") 
    set(DEBFILE_ARCH "i386")
endif()

################################################################################
## Sources files
################################################################################
file(GLOB SOURCE_FILES
    src/biblioteca/*.cpp
    src/biblioteca/*/*.cpp
)

file(GLOB HEADER_FILES 
    src/headers/Pds/*
)


include_directories(src/headers ${ADD_INCLUDE_DIRECTORY})

################################################################################

set(INTERNAL_LIBRARIES_IN_PROJECT         ${PROJECT_NAME}_static)

add_library(${INTERNAL_LIBRARIES_IN_PROJECT} STATIC ${SOURCE_FILES})


# Adding something we can run - Output name matches target name
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${INTERNAL_LIBRARIES_IN_PROJECT} ${TARGET_EXTRA_LINK} ${ADD_LIB_DIRECTORY})


################################################################################
set(DOC_FILES 
    ${CMAKE_BINARY_DIR}/doc/README.md
)

################################################################################
## Archivos de configuracion
################################################################################
configure_file(doc/README.md.in   doc/README.md @ONLY)

################################################################################
## Install
################################################################################

# principal
install(TARGETS     ${PROJECT_NAME} 
        DESTINATION ${CMAKE_INSTALL_BINDIR}
)


# doc
install(FILES       ${DOC_FILES} 
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/${PROJECT_NAME}
)

################################################################################
## Make dist
################################################################################
add_subdirectory(package)


################################################################################
## Test programs
################################################################################
add_subdirectory(test)

################################################################################
## Final messages
################################################################################

MESSAGE(STATUS "++  ")
MESSAGE(STATUS "++  Detecting architecture           : ${DEBFILE_ARCH}") 
MESSAGE(STATUS "++  The program will be installed in : ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "++  To change this option            : cmake /path/of/source/code -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "++  ")

################################################################################
## Macro defines
################################################################################

add_definitions(-DPROJECT_VERSION_STRING=\"${PROJECT_VERSION}\")
add_definitions(-DPROJECT_NAME_STRING=\"${PROJECT_NAME}\")

