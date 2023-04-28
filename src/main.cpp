#include <iostream>
#include <cxxopts.hpp>
#include "server/server.h"

cxxopts::Options options("FastMediaShare", "Simple Media Share System");

std::string version = "1.0.0";

int main(int argc, char *argv[]) {
  options.add_options()
      ("h,help", "Print usage")
      ("s,share", "Share file", cxxopts::value<std::string>())
      ("p,public", "Make it public and print the public URI")
      ("version", "Show software version");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
  }

  if (result.count("share")) {
    // Open HTTP server
    // Allow connection to <domain>/v/$id
    // Stream media
    // feature: make a way to share commands and sync clients
    std::string path = result["share"].as<std::string>();
    std::cout << server::GenerateUri(path, true) << std::endl;
  }

  if (result.count("version")) {
    std::cout << "version: " << version << std::endl;
  }
  return 0;
}
