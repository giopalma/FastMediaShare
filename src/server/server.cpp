#include <unordered_map>
#include "server.h"
#include "../tools.h"
#include <sstream>

std::unordered_map<std::string, std::string> map;
const size_t kIdLen = 10;

std::string server::GenerateUri(const std::string &path, const bool remote_access = false) {

  std::string id = "";
  do {
    id = tools::RandomString(kIdLen);
  } while (map.find(id) != map.end()); // This while check if the generated id already exists

  map.insert(std::make_pair(id, path));

  if (remote_access) {
    return tools::GetPublicIp() + "/v/" + id;
  }
  return "127.0.0.1/v/" + id;;
}
void server::Run(const std::string host, const unsigned short port) {
  auto router = oatpp::web::server::HttpRouter::createShared();
  auto connection_handler = oatpp::web::server::HttpConnectionHandler::createShared(router);
  auto connection_provider =
      oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", port, oatpp::network::Address::IP_4});

  oatpp::network::Server server(connection_provider, connection_handler);
  OATPP_LOGI("FMS",
             "Server running on %s:%s",
             host.c_str(),
             std::to_string(port).c_str());
  server.run();
}
void server::init() {
  oatpp::base::Environment::init();
}
void server::destroy() {
  oatpp::base::Environment::destroy();
}
