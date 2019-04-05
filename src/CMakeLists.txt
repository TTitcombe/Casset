set(SRC_FILES
  main.cpp
  IEX.cpp
  # add any additional source files here
)

set(HDR_FILES
  IEX.h
  # add any additional header files here
)

add_executable(Casset ${SRC_FILES} ${HDR_FILES})
target_link_libraries(Casset CONAN_PKG::cpr
                             CONAN_PKG::jsonformoderncpp
                             CONAN_PKG::fmt)