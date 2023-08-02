#include <gtest/gtest.h>
#include "url_parser.h"

// Tests for URLParser::parse()
TEST(URLParserTest, ParseURL) {
    std::string url = "https://www.example.com/page?param1=value1&param2=value2#section";
    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

    EXPECT_EQ(parsedUrl.scheme, "https");
    EXPECT_EQ(parsedUrl.host, "www.example.com");
    EXPECT_EQ(parsedUrl.path, "/page");
    EXPECT_EQ(parsedUrl.fragment, "section");

    EXPECT_EQ(parsedUrl.query.size(), 2);
    EXPECT_EQ(parsedUrl.query["param1"], "value1");
    EXPECT_EQ(parsedUrl.query["param2"], "value2");
}

TEST(URLParserTest, ParseURLWithEmptyComponents) {
    // Test with a URL missing some components
    std::string url = "ftp://example.com";
    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

    EXPECT_EQ(parsedUrl.scheme, "ftp");
    EXPECT_EQ(parsedUrl.host, "example.com");
    EXPECT_EQ(parsedUrl.path, "");
    EXPECT_EQ(parsedUrl.fragment, "");
    EXPECT_TRUE(parsedUrl.query.empty());
}

TEST(URLParserTest, ParseURLWithEmptyQuery) {
    // Test with a URL having an empty query
    std::string url = "https://www.example.com/page#section";
    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

    EXPECT_EQ(parsedUrl.scheme, "https");
    EXPECT_EQ(parsedUrl.host, "www.example.com");
    EXPECT_EQ(parsedUrl.path, "/page");
    EXPECT_EQ(parsedUrl.fragment, "section");
    EXPECT_TRUE(parsedUrl.query.empty());
}

TEST(URLParserTest, ParseURLWithSpecialCharacters) {
    // Test with a URL containing special characters
    std::string url = "https://www.example.com/page?name=John%20Doe&age=30%2B";
    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

    EXPECT_EQ(parsedUrl.scheme, "https");
    EXPECT_EQ(parsedUrl.host, "www.example.com");
    EXPECT_EQ(parsedUrl.path, "/page");
    EXPECT_EQ(parsedUrl.fragment, "");
    EXPECT_EQ(parsedUrl.query.size(), 2);
    EXPECT_EQ(parsedUrl.query["name"], "John Doe");
    EXPECT_EQ(parsedUrl.query["age"], "30+");
}

// Add more tests as needed to cover different scenarios.

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
