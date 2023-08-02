#pragma once

#include <string>
#include <unordered_map>
#include <regex>

class URLParser {
public:
    struct ParsedURL {
        std::string scheme;
        std::string host;
        std::string path;
        std::unordered_map<std::string, std::string> query;
        std::string fragment;
    };

    static ParsedURL parse(const std::string& url) {
        ParsedURL parsedUrl;

        // Regular expression to extract different URL components
        const std::regex urlRegex(
            "^(?:(\\w+):\\/\\/)?([^\\/\\?#]+)?(\\/[^?#]*)?(?:\\?([^#]*))?(?:#(.*))?$"
        );

        std::smatch match;

        if (std::regex_match(url, match, urlRegex)) {
            if (match[1].matched) {
                parsedUrl.scheme = match[1].str();
            }

            if (match[2].matched) {
                parsedUrl.host = match[2].str();
            }

            if (match[3].matched) {
                parsedUrl.path = match[3].str();
            }

            if (match[4].matched) {
                parsedUrl.query = parseQuery(match[4].str());
            }

            if (match[5].matched) {
                parsedUrl.fragment = match[5].str();
            }
        }

        return parsedUrl;
    }

private:
    static std::unordered_map<std::string, std::string> parseQuery(const std::string& queryString) {
        std::unordered_map<std::string, std::string> queryMap;
        const std::regex queryRegex("([^=&]+)=([^&]*)");

        auto queryBegin = std::sregex_iterator(queryString.begin(), queryString.end(), queryRegex);
        auto queryEnd = std::sregex_iterator();

        for (auto it = queryBegin; it != queryEnd; ++it) {
            std::string key = (*it)[1].str();
            std::string value = (*it)[2].str();
            queryMap[key] = value;
        }

        return queryMap;
    }
};
