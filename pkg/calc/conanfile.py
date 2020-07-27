from conans import ConanFile, CMake,tools


class CalcConan(ConanFile):
    name = "Calc"
    license = "MIT License"
    author = "Andreas Achtzehn <andreas@achtzehn.de>"
    url = "https://github.com/aachtzehn/cmake-calculator"
    description = "Calculator example to test cmake and conan"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": True}
    generators = "cmake"
    exports_sources = "../../CMakeLists.txt*", "../../src*","../../include*","../../test*"

    def set_version(self):
        git = tools.Git()
        self.version = "%s" % git.get_branch()

    def requirements(self):
        self.requires("CalcLib/"+self.version)

    def build(self):
        cmake = CMake(self, parallel=True, set_cmake_flags=True)
        # cmake .. -DBUILD_SHARED_LIBS=On -DBUILD_CALCULATORLIB=On -DCMAKE_INSTALL_PREFIX=$(pwd)/../stage -DBUILD_TESTING=On
        cmake.verbose = True
        cmake.definitions["BUILD_CALCULATOR"] = True
        cmake.definitions["CMAKE_INSTALL_PREFIX"] = "stage/"
        cmake.configure()
        cmake.build()
        #cmake.test()
        cmake.install()


    def package(self):
        self.copy("*",src="stage", keep_path=True)

