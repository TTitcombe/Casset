###############################################################################
## Unit Tests
###############################################################################

set(SRC_TEST_FILES
        API/IEXTest.cpp
)

find_package(Catch2 REQUIRED)
add_executable(UnitTests ${SRC_TEST_FILES})
target_link_libraries(UnitTests CONAN_PKG::catch2
                                CONAN_PKG::cpr
                                CONAN_PKG::jsonformoderncpp
                                CONAN_PKG::trompeloeil)