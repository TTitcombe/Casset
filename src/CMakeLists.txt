set(SRC_FILES
  main.cpp
  API/IEX.cpp
)

set(HDR_FILES
  API/IEX.h
)

add_executable(Casset ${SRC_FILES} ${HDR_FILES})
target_link_libraries(Casset CONAN_PKG::cpr
                             CONAN_PKG::jsonformoderncpp
                             CONAN_PKG::CLI11
                             CONAN_PKG::spdlog)
