

#include "helpers/helpers.h"
#include "http/http.h"

#ifndef USE_IOT

#include <curl/curl.h>
#include <cstring>
#include <sstream>
#include <iostream>

namespace Ark {
namespace Client {
namespace {

class PlatformHTTP : public AbstractHTTP
{
    public: 
        PlatformHTTP() = default;

        /**/

        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
        { // https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }

        /**/

        std::string get(
                const char *const request
        ) override {
            std::ostringstream ss;
            ss << this->host_ << ":" << this->port_ << request;

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());

                /* skip https verification */
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }
            return readBuffer;
        }

        /**/

        std::string post(
                const char *const request,
                const char *body
        ) override {
            std::ostringstream ss;
            ss << this->host_ << ":" << this->port_ << request;

            /* https://curl.haxx.se/libcurl/c/http-post.html */
            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl_global_init(CURL_GLOBAL_ALL);
            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str()); // Set the URL that is about to receive our POST
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body); // Now specify the POST data ex: "username=baldninja"
                
                /* skip https verification */
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Do NOT verify peer
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // Do NOT verify host

                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl); // Perform the request, res will get the return code 
                if(res != CURLE_OK) { // Check for errors
                    fprintf(
                        stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res)
                    );
                }
                curl_easy_cleanup(curl); /* always cleanup */ 
            }
            curl_global_cleanup();
            return readBuffer;
        };
        /**/
};
/**/
}

/**
 * HTTP Object Factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP() {
    return std::unique_ptr<AbstractHTTP>(new PlatformHTTP());
}
/**/
};
};

#endif
