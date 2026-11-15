#pragma once

#include <string>
#include <vector>

namespace CDrive {

struct HttpResponse {
    long statusCode = 0;
    std::string body;
    std::string errorBuffer;
};

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    HttpClient(const HttpClient&) = delete;
    HttpClient& operator=(const HttpClient&) = delete;
    HttpClient(HttpClient&&) noexcept = default;
    HttpClient& operator=(HttpClient&&) noexcept = default;

    HttpResponse get(const std::string& url, const std::vector<std::string>& headers = {});
    HttpResponse post(const std::string& url, const std::string& payload, const std::vector<std::string>& headers = {});
    HttpResponse multipartUpload(const std::string& url, const std::string& filePath, const std::string& metadataJson, const std::vector<std::string>& headers = {});

private:
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

}
