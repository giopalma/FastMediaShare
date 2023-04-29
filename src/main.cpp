#include <iostream>
#include <cxxopts.hpp>
#include "server/server.h"
#include "tools.h"

cxxopts::Options options("FastMediaShare", "Simple Media Share System");

std::string version = "1.0.0";

void cli(int argc, char *argv[]) {
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
    if (result.count("public")) {
      server::Run(tools::GetPublicIp(), 8000);
    } else {
      server::Run("localhost", 8000);
    }
  }

  if (result.count("version")) {
    std::cout << "version: " << version << std::endl;
  }
}

int main(int argc, char *argv[]) {
  server::init();
  cli(argc, argv);
  server::destroy();
  return 0;
}
