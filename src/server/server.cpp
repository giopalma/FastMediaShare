//
// Created by giovanni on 28/04/23.
//

#include <unordered_map>
#include "server.h"
#include "../tools.h"

std::unordered_map<std::string, std::string> map;

std::string server::GenerateUri(const std::string &path, bool remote_access = false) {

  std::string id = "";
  do {
    id = tools::RandomString(5);
  } while (map.find(id) != map.end()); // This while check if the generated id already exists

  map.insert(std::make_pair(id, path));

  if (remote_access) {
    return tools::GetPublicIp() + "/v/" + id;
  }
  return "localhost/v/" + id;;
}
