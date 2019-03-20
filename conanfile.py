import os
import shutil

from conans import CMake, ConanFile, tools


class CprConan(ConanFile):
    name = "cpr"
    version = "1.3.0"
    license = "MIT License"
    url = "https://github.com/whoshuu/cpr"
    description = "C++ Requests is a simple wrapper around libcurl inspired by the excellent Python Requests project."
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "curl_nosignal": [True, False],
        "use_openssl": [True, False],
    }
    default_options = "curl_nosignal=False", "use_openssl=True"
    # exports = ["CMakeLists.txt"]
    exports_sources = ["cpr-config.cmake"]
    generators = "cmake"
    requires = "libcurl/7.60.0@bincrafters/stable"

    @property
    def zip_folder_name(self):
        return "%s-%s" % (self.name, self.version)

    def source(self):
        zip_name = "%s.tar.gz" % self.version
        tools.download("https://github.com/whoshuu/cpr/archive/%s" % zip_name, zip_name)
        tools.check_md5(zip_name, "f9df0c649208b06dd314699b4eb43759")
        tools.unzip(zip_name)
        os.unlink(zip_name)
        with tools.chdir(self.zip_folder_name):
            tools.replace_in_file('CMakeLists.txt', 'project(cpr)', '''project(cpr)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()''')
            tools.replace_in_file('CMakeLists.txt', 'add_subdirectory(opt)', '')
            #tools.replace_in_file('cpr/CMakeLists.txt', 'add_library(${CPR_LIBRARIES}', 'add_library(${CPR_LIBRARIES} STATIC')
            tools.replace_in_file('cpr/CMakeLists.txt', '${CURL_INCLUDE_DIRS}', '${CONAN_INCLUDE_DIRS_LIBCURL}')
            tools.replace_in_file('cpr/CMakeLists.txt', '${CURL_LIBRARIES}', '${CONAN_LIBS_LIBCURL}')

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CPR_CURL_NOSIGNAL"] = "ON" if self.options.curl_nosignal else "OFF"
        cmake.definitions["CMAKE_USE_OPENSSL"] = "ON" if self.options.use_openssl else "OFF"
        cmake.definitions["BUILD_CPR_TESTS"] = "OFF"
        cmake.configure(source_dir=self.zip_folder_name)
        cmake.build()

    def package(self):
        source_dir = self.zip_folder_name
        self.copy("cpr-config.cmake", ".", ".")
        self.copy("*.h", dst="include", src=source_dir + '/include')
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)
        self.copy("*.so*", dst="lib", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["cpr"]