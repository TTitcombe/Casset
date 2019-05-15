###############################################################################
## Unit Tests
###############################################################################

set(SRC_TEST_FILES
        API/IEXTest.cpp
        ../src/API/src/IEX.cpp
        API/stockinfoTest.cpp
        ../src/API/src/stockinfo.cpp
        UI/presenterTest.cpp
        ../src/UI/src/presenter.cpp
        ../src/UI/src/mainwindow.cpp
)

set(HDR_TEST_FILES
        ../src/API/hdr/IEX.h
        ../src/API/hdr/stockinfo.h
        ../src/UI/hdr/presenter.h
        ../src/UI/hdr/mainwindow.h
        ../src/UI/hdr/mainwindow.ui
)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(UnitTests ${SRC_TEST_FILES} ${HDR_TEST_FILES})
target_link_libraries(UnitTests CONAN_PKG::catch2
                                CONAN_PKG::cpr
                                CONAN_PKG::fmt
                                CONAN_PKG::jsonformoderncpp
                                CONAN_PKG::trompeloeil
                                CONAN_PKG::spdlog
                                CONAN_PKG::CLI11
                                Qt5::Core
                                Qt5::Widgets)
