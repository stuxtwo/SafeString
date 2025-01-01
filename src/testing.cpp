#include "SafeString/SafeString.h"

namespace SafeString {
    std::string concatenate(const std::string& a, const std::string& b) {
        return a + b;
    }

    std::string safeSubstring(const std::string& str, size_t start, size_t length) {
        if (start >= str.size()) {
            throw std::out_of_range("Start index out of range");
        }
        return str.substr(start, length);
    }

    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::string replace(const std::string& str, const std::string& from, const std::string& to) {
        if (from.empty()) {
            return str;
        }
        std::string result = str;
        size_t start_pos = 0;
        while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
            result.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return result;
    }

    template<typename... Args>
    std::string format(const std::string& formatStr, Args... args) {
        size_t size = snprintf(nullptr, 0, formatStr.c_str(), args...) + 1;
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, formatStr.c_str(), args...);
        return std::string(buf.get(), buf.get() + size - 1);
    }
}
