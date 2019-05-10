set(SRC_FILES
  main.cpp
  API/src/IEX.cpp
  API/src/stockinfo.cpp
  API/src/portfolio.cpp
  UI/src/presenter.cpp
  UI/src/mainwindow.cpp
)

set(HDR_FILES
  API/hdr/IEX.h
  API/hdr/stockinfo.h
  API/hdr/portfolio.h
  UI/hdr/presenter.h
  UI/hdr/mainwindow.h
  UI/hdr/mainwindow.ui
)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(Casset ${SRC_FILES} ${HDR_FILES})
target_link_libraries(Casset CONAN_PKG::cpr
                             CONAN_PKG::jsonformoderncpp
                             CONAN_PKG::fmt
                             CONAN_PKG::CLI11
                             CONAN_PKG::spdlog
                             Qt5::Core
                             Qt5::Widgets)
