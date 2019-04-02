add_subdirectory(API)

set(SRC_FILES
  main.cpp
  ${API_SRC_FILES}
  # add any additional source files here
)

set(HDR_FILES
  ${API_HDR_FILES}
  # add any additional header files here
)

add_executable(Casset ${SRC_FILES} ${HDR_FILES})
target_link_libraries(Casset CONAN_PKG::cpr
                             CONAN_PKG::jsonformoderncpp
                             CONAN_PKG::fmt)