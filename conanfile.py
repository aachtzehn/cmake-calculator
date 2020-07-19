from conans import ConanFile, CMake


class CalcConan(ConanFile):
    name = "calc"
    version = "1.0"
    license = "MIT License"
    author = "Andreas Achtzehn andreas@achtzehn.de"
    url = "https://github.com/aachtzehn/calc"
    description = "Calculator example to test cmake and conan"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*","include/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="..")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*", , src="stage", keep_path=True)

    def package_info(self):
        self.cpp_info.libs = ["CalcLib"]
