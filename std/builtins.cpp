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

template<typename T>
T dot(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        panic("Size mismatch for @");
    }
    T sum = 0;
    for (int i = 0; i < vec1.size(); i++) {
        sum += vec1[i] * vec2[i];
    }
    return sum;
}

// For all types except integral types:
template<typename T>
typename std::enable_if<!std::is_integral<T>::value, T>::type _zero()
{
    T::zero();
}

// For integral types only:
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type _zero()
{
    return 0;
}

// For all types except integral types:
template<typename T>
typename std::enable_if<!std::is_integral<T>::value, T>::type _one()
{
    T::one();
}

// For integral types only:
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type _one()
{
    return 1;
}
