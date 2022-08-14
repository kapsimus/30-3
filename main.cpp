#include <iostream>
#include <string>
#include <map>
#include <cpr/cpr.h>

void postMethod(std::map<std::string, std::string>& arguments){
    std::map<std::string, std::string>::iterator it;
    std::vector<cpr::Pair> args;
    cpr::Response response;

    for (it = arguments.begin(); it != arguments.end(); it++) {
        args.push_back(cpr::Pair(cpr::Pair((std::string)it->first, (std::string)it->second)));
    }
    cpr::Payload pl(args.begin(), args.end());
    response = cpr::Post(cpr::Url("http://httpbin.org/post"), pl);
    std::cout << response.text << std::endl;
}

void getMethod(std::map<std::string, std::string>& arguments){
    std::string url = "http://httpbin.org/get";
    std::map<std::string, std::string>::iterator it;
    cpr::Response response;

    if (!arguments.empty()) {
        url += "?";
        for (it = arguments.begin(); it != arguments.end(); it++) {
            if (it != arguments.begin()) {
                url += "&";
            }
            url += it->first + "=" + it->second;
        }
    }
    std::cout << url <<std::endl;
    response = cpr::Get(cpr::Url(url));
    std::cout << response.text << std::endl;
}

int main() {
    std::string key, value;
    std::map<std::string, std::string> arguments;

    do {
        std::cout << "Enter argument:" << std::endl;
        std::cin >> key;
        if (key != "post" && key != "get") {
            std::cout << "Enter value:" << std::endl;
            std::cin >> value;
            arguments.insert(std::pair<std::string, std::string>(key, value));
        }
    } while (key != "post" && key != "get");

    if (key == "post") {
        postMethod(arguments);
    }

    if (key == "get") {
        getMethod(arguments);
    }
    return 0;
}
