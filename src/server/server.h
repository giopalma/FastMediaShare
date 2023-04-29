//
// Created by giovanni on 28/04/23.
//

#ifndef FASTMEDIASHARE_SERVER_H
#define FASTMEDIASHARE_SERVER_H

#include <iostream>
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

class server {
 public:
/**
 * Generate the url from a path
 * @param path media file path
 * @param remote_access if true, return the url with public ip
 * @return url of media file
 */
  static std::string GenerateUri(const std::string &path, bool remote_access);
  static void Run(const std::string host, v_uint16 port);
  void static init();
  void static destroy();
};

#endif //FASTMEDIASHARE_SERVER_H
