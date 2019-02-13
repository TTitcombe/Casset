set(SRC_FILES
  src/main.cpp
  # add any additional source files here
)

set(HDR_FILES
  # add any additional header files here
)

add_executable(Casset ${SRC_FILES} ${HDR_FILES})
target_link_libraries(Casset CONAN_PKG::cpr)