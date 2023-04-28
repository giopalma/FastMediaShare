#include <iostream>
#include <cxxopts.hpp>

cxxopts::Options options("FastMediaShare", "Simple Media Share System");

std::string version = "1.0.0";

int main(int argc, char *argv[]) {
    options.add_options()
            ("h,help", "Print usage")
            ("s,share","Share file", cxxopts::value<std::string>())
            ("p,public","Make it public and print the public URI")
            ("version","Show software version");

    auto result = options.parse(argc,argv);

    if(result.count("help")){
        std::cout << options.help() << std::endl;
    }

    if(result.count("share")){
        std::string path = result["share"].as<std::string>();
        std::cout << "Share command executed" << std::endl;
    }

    if(result.count("version")){
        std::cout << "version: "<< version << std::endl;
    }
    return 0;
}
