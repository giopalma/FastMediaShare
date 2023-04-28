//
// Created by giovanni on 28/04/23.
//

#include "server.h"
#include "../tools.h"

std::string server::generateUrl(std::string path, bool remoteAccess = false) {
    // Generate id from path
    std::string id = tools::random_string(5);
    if (remoteAccess) {
        return tools::getPublicIp() + "/v/" + id;
    }
    return "localhost/v/" + id;;
}
