#include "SafeString/SafeString.h"
#include <iostream>
#include <cassert>

void testConcatenate() {
    assert(SafeString::concatenate("Hello, ", "World!") == "Hello, World!");
    std::cout << "testConcatenate passed!" << std::endl;
}

void testSafeSubstring() {
    assert(SafeString::safeSubstring("Hello, World!", 7, 5) == "World");
    try {
        SafeString::safeSubstring("Short", 10, 2);
    }
    catch (const std::out_of_range&) {
        std::cout << "testSafeSubstring passed!" << std::endl;
        return;
    }
    assert(false); // Should not reach here
}

void testSplit() {
    auto result = SafeString::split("A,B,C", ',');
    assert(result.size() == 3 && result[0] == "A" && result[1] == "B" && result[2] == "C");
    std::cout << "testSplit passed!" << std::endl;
}

void testReplace() {
    assert(SafeString::replace("Hello, World!", "World", "C++") == "Hello, C++!");
    std::cout << "testReplace passed!" << std::endl;
}

int main() {
    testConcatenate();
    testSafeSubstring();
    testSplit();
    testReplace();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
