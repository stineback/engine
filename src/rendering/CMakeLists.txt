find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# add the executable
add_executable(rendering Main.cpp)
target_link_libraries(rendering ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

