###############################################################################
## Unit Tests
###############################################################################

set(SRC_TEST_FILES
        API/IEXTest.cpp
        ../src/API/IEX.cpp
)

set(HDR_TEST_FILES
        ../src/API/IEX.h)

add_executable(UnitTests ${SRC_TEST_FILES} ${HDR_TEST_FILES})
target_link_libraries(UnitTests CONAN_PKG::catch2
                                CONAN_PKG::cpr
                                CONAN_PKG::jsonformoderncpp
                                CONAN_PKG::trompeloeil
                                CONAN_PKG::fmt)
