#include "headers.h"
#include <string>
using namespace std;

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    struct Response {
        long status_code;
        string body;
    };

    Response get(const string& url, const map<string, string>& headers);
    Response post(const string& url, const map<string, string>& headers, const string& body);
    Response multipartUpload(const string& url, const map<string, string>& headers,
                             const string& metadata_json, const string& file_path);

private:
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, string* s);
};
class FileOperations{
    private:

    public:
    // def
};
