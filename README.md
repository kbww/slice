# Slice - URL Parser (C++ Header-Only) Library

Slice is a simple header-only C++ library that allows you to parse URLs and extract their components (scheme, host, path, query, and fragment) using regular expressions.

## Usage

To use the URL Parser in your C++ project, follow these steps:

1. Download the `url_parser.h` header file from this repository.
2. Copy the `url_parser.h` file into your project directory or include it in your project's `include` folder.

## Build

The URL Parser is a header-only library and does not require a separate build process. You can include the `url_parser.h` file directly in your C++ source files, and the parser will be available for use.

## Example

Below is a simple example usage:

```cpp
#include <iostream>
#include "url_parser.h"

int main() {
    std::string url = "https://www.example.com/page?param1=value1&param2=value2#section";

    URLParser::ParsedURL parsedUrl = URLParser::parse(url);

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
```

Replace the url variable with any URL you want to parse. The URLParser class will extract its components and provide them in the ParsedURL struct for further use in your application.

## Contributing

Contributions to this project are welcome! If you find any issues or have any improvements, please feel free to open an issue or submit a pull request.
