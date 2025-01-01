#ifndef SAFESTRING_H
#define SAFESTRING_H

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>

namespace SafeString {
    std::string concatenate(const std::string& a, const std::string& b);
    std::string safeSubstring(const std::string& str, size_t start, size_t length);
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::string replace(const std::string& str, const std::string& from, const std::string& to);

    template<typename... Args>
    std::string format(const std::string& formatStr, Args... args);
}

#endif
