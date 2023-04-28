//
// Created by giovanni on 28/04/23.
//

#ifndef FASTMEDIASHARE_TOOLS_H
#define FASTMEDIASHARE_TOOLS_H

#include <string>
#include <random>
#include <algorithm>
#include <curl/curl.h>

class tools {
 public:
  static std::string RandomString(std::size_t length);

  static std::string GetPublicIp();
};

#endif //FASTMEDIASHARE_TOOLS_H
