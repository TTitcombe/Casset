###############################################################################
## Unit Tests
###############################################################################

set(SRC_TEST_FILES
  BasicTest.cpp
)

add_executable(UnitTests ${SRC_TEST_FILES})
target_link_libraries(UnitTests CONAN_PKG::catch2)
