cmake_minimum_required(VERSION 3.28)
project(Camera C)

set(CMAKE_C_STANDARD 17)

set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/src/camera.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})

# C_GLM
find_package(cglm REQUIRED)
if (cglm_FOUND)
    message("Linking cGLM...")
    target_link_libraries(${PROJECT_NAME} cglm::cglm -lm)
else ()
    message("GLFW not found!")
endif ()