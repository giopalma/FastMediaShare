//
// Created by giovanni on 28/04/23.
//

#ifndef FASTMEDIASHARE_SERVER_H
#define FASTMEDIASHARE_SERVER_H

#include "string"

class server {
 public:
/**
 * Generate the url from a path
 * @param path media file path
 * @param remote_access if true, return the url with public ip
 * @return url of media file
 */
  static std::string GenerateUri(const std::string &path, bool remote_access);
};

#endif //FASTMEDIASHARE_SERVER_H
