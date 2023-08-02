#include <iostream>
#include "slice/url_parser.h" // Include the header file

int main() {
    std::string url = "https://www.example.com/page?param1=value1&param2=value2#section";

    // Use the URLParser to parse the URL
    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

    // Access the components of the URL
    std::cout << "Scheme: " << parsedUrl.scheme << std::endl;
    std::cout << "Host: " << parsedUrl.host << std::endl;
    std::cout << "Path: " << parsedUrl.path << std::endl;
    std::cout << "Fragment: " << parsedUrl.fragment << std::endl;

    std::cout << "Query Parameters:" << std::endl;
    for (const auto& entry : parsedUrl.query) {
        std::cout << entry.first << " = " << entry.second << std::endl;
    }

    return 0;
}
