#include "builtins.hpp"
#include <iostream>

std::string input(const std::string& str);

void print(const std::string& str) {
    std::cout << str << std::endl;
}

void panic(const std::string& str) {
    std::cout << "PANIC: " << str << std::endl;
    exit(1);
}

std::string input(const std::string& str) {
    std::cout << str;
    std::string input;
    std::cin >> input;
    return input;
}

template<typename T>
void push(std::vector<T>& vec, const T& val) {
    vec.push_back(val);
}

template<typename T>
T pop(std::vector<T>& vec) {
    if (vec.empty()) {
        panic("Cannot pop from empty vector");
    }
    T val = vec.back();
    vec.pop_back();
    return val;
}

template<typename T>
void slice(std::vector<T>& vec, int start, int end) {
    if (start < 0 || end < 0 || start > end) {
        panic("Invalid slice");
    } else if (end > vec.size()) {
        panic("Slice out of bounds");
    }
    vec.erase(vec.begin() + start, vec.begin() + end);
}
