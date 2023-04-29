//
// Created by giovanni on 29/04/23.
//

#ifndef FASTMEDIASHARE_SRC_SERVER_SERVER_HANDLER_H_
#define FASTMEDIASHARE_SRC_SERVER_SERVER_HANDLER_H_

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

class server_handler : public oatpp::web::server::HttpRequestHandler {
 public:
  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {
    return ResponseFactory::createResponse(Status::CODE_200, "Hello World!");
  }
};

#endif //FASTMEDIASHARE_SRC_SERVER_SERVER_HANDLER_H_
