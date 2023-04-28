//
// Created by giovanni on 28/04/23.
//

#include "tools.h"
#include <curl/curl.h>

std::string tools::RandomString(std::size_t length) {
  const std::string kCharacters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  std::random_device random_device;
  std::mt19937 generator(random_device());
  std::uniform_int_distribution<> distribution(0, kCharacters.size() - 1);

  std::string random_string;

  std::generate_n(std::back_inserter(random_string), length, [&] { return kCharacters[distribution(generator)]; });

  return random_string;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string *) userp)->append((char *) contents, size * nmemb);
  return size * nmemb;
}

std::string tools::GetPublicIp() {
  CURL *curl;
  CURLcode res;
  std::string read_buffer;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return read_buffer;
  }
  return "UNABLE TO GET IP";
}
