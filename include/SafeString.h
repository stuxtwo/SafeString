#ifndef SAFESTRING_H
#define SAFESTRING_H

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <regex>

namespace SafeString {

    inline std::string concatenate(const std::string& a, const std::string& b) {
        return a + b; 
    }

    inline std::string safeSubstring(const std::string& str, size_t start, size_t length) {
        if (start >= str.size()) {
            throw std::out_of_range("Start index out of bounds");
        }
        size_t end = start + length;
        if (end > str.size()) {
            end = str.size(); 
        }
        return str.substr(start, end - start);
    }

    std::vector<std::string> split(const std::string& str, char delimiter, bool trim = true); 
    std::string replace(const std::string& str, const std::string& from, const std::string& to);

    // format string with variadic template arguments
    template<typename... Args>
    std::string format(const std::string& formatStr, Args... args) {
        std::stringstream ss;
        ss << std::format(formatStr, args...); 
        return ss.str(); 
    }

    bool is_empty(const std::string& str);
    std::string trim(const std::string& str);
    std::string to_lowercase(const std::string& str);
    std::string to_uppercase(const std::string& str);
    bool starts_with(const std::string& str, const std::string& prefix);
    bool ends_with(const std::string& str, const std::string& suffix);
    std::string before(const std::string& str, char delimiter);
    std::string after(const std::string& str, char delimiter);
    std::string join(const std::vector<std::string>& strs, const std::string& delimiter);
    std::string remove_char(const std::string& str, char c);
    std::string remove_non_alphabetic(const std::string& str);
    std::string remove_non_numeric(const std::string& str);
    bool is_digit(const std::string& str);
    bool is_alpha(const std::string& str);
    bool is_alnum(const std::string& str);
    bool iequals(const std::string& a, const std::string& b);

}

#endif
