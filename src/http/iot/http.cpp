


#include "http/http.h"
#include "helpers/helpers.h"
#include <memory>
#include <vector>

#ifdef ESP8266
    #include <ESP8266HTTPClient.h>
#else
    #include <HTTPClient.h>
#endif

namespace Ark {
namespace Client {
namespace {

/**
*
**/
class PlatformHTTP : public AbstractHTTP
{
    public:
        PlatformHTTP() = default;

        /**/

        int tryConnection(
                HTTPClient &client,
                const char *const peer,
                int port,
                const char *const request
        ) {
            if (!client.begin(peer, port, request)) {
                /* Bad HTTP begin */
                return -1;
            }
            int code = client.GET();
            int count = 0;
            while (code != HTTP_CODE_OK)
            {   //error
                client.end();
                if (count >=2) {
                    /* Bad connection. Try another peer */
                    return code;
                };
                /* Bad HTTP GET.\nRetrying connection.. */
                delay(1000);
                client.begin(peer, port, request);
                code = client.GET();
                count++;
            };
            return code;
        };

        /**/

        std::string get(
                const char *const request
        ) override {
            HTTPClient http;
            http.setReuse(false);
            http.setTimeout(3000);
            if (int code = tryConnection(http, this->host_, this->port_, request) != 200) {
                /* error */
                return http.errorToString(-code).c_str(); // <- note `-` symbol.
            }
            return http.getString().c_str();
        }

        /**/

        std::string post(
                const char *const request,
                const char *body
        ) override {
            HTTPClient http;
            http.setReuse(true);
            http.setTimeout(3000);
            http.begin(this->host_, this->port_, request);

            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            http.POST(body);
            return http.getString().c_str();
        }
        /**/
};
/**/
}

/**
 * HTTP object factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP() {
    return std::unique_ptr<AbstractHTTP>(new PlatformHTTP());
}
/**/
};
};
