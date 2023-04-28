#include <iostream>
#include <cxxopts.hpp>

cxxopts::Options options("FastMediaShare", "Simple Media Share System");

std::basic_string<char> version = "1.0.0";

int main(int argc, char *argv[]) {
    options.add_options()
            ("version","Show software version")
            ("s,share","Share file", cxxopts::value<std::string>())
            ("p,public","Make it public, print the public URI");

    auto result = options.parse(argc,argv);

    if(result.count("share")){
        std::cout << "Share command executed" << std::endl;
    }

    if(result.count("version")){
        std::cout << "version: "<< version << std::endl;
    }

    return 0;
}
