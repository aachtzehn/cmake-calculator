from conans import ConanFile, CMake


class CalcConan(ConanFile):
    name = "CalcLib"
    version = "1.0"
    license = "MIT License"
    author = "Andreas Achtzehn <andreas@achtzehn.de>"
    url = "https://github.com/aachtzehn/cmake-calculator"
    description = "Calculator example to test cmake and conan"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": True}
    generators = "cmake"
    exports_sources = "../../CMakeLists.txt*", "../../src*","../../include*","../../test*"

    def build(self):
        cmake = CMake(self, parallel=True, set_cmake_flags=True)
        # cmake .. -DBUILD_SHARED_LIBS=On -DBUILD_CALCULATORLIB=On -DCMAKE_INSTALL_PREFIX=$(pwd)/../stage -DBUILD_TESTING=On
        cmake.verbose = True
        cmake.definitions["BUILD_CALCULATORLIB"] = True
        cmake.definitions["CMAKE_INSTALL_PREFIX"] = "stage/"
        cmake.configure()
        cmake.build()
        cmake.test()
        cmake.install()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("stage/*", keep_path=True)

    def package_info(self):
        self.cpp_info.libs = ["CalcLib"]
