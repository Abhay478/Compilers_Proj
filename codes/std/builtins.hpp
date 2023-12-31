#pragma once

#include <string>
#include <vector>
#include <iostream>

void f_print(const std::string str) {
    std::cout << str << std::endl;
}

void f_print_c(const char c) {
    std::cout << c << std::endl;
}

void f_panic(const std::string str) {
    std::cout << "PANIC: " << str << std::endl;
    exit(1);
}

std::string f_input(const std::string str) {
    std::cout << str;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

std::string f_slice_str(const std::string str, int start, int end) {
    if (start < 0 || end < 0 || start > end) {
        f_panic("Invalid slice");
    } else if (end > str.size()) {
        f_panic("Slice out of bounds");
    }
    return str.substr(start, end - start);
}

template<typename T>
void f_push(std::vector<T>& vec, const T val) {
    vec.push_back(val);
}

void f_push(std::vector<unsigned long int>& vec, const unsigned long int val) {
    vec.push_back(val);
}

void f_push(std::vector<long int>& vec, const long int val) {
    vec.push_back(val);
}

template<typename T>
T f_pop(std::vector<T>& vec) {
    if (vec.empty()) {
        f_panic("Cannot pop from empty vector");
    }
    T val = vec.back();
    vec.pop_back();
    return val;
}

template<typename T>
std::vector<T> f_slice(std::vector<T> vec, int start, int end) {
    if (start < 0 || end < 0 || start > end) {
        f_panic("Invalid slice");
    } else if (end > vec.size()) {
        f_panic("Slice out of bounds");
    }
    return std::vector<T>(vec.begin() + start, vec.begin() + end);
}

template<typename T>
T f_dot(Vec<T> vec1, Vec<T> vec2) {
    if (vec1.a.size() != vec2.a.size()) {
        f_panic("Size mismatch for @");
    }
    T sum = 0;
    for (int i = 0; i < vec1.a.size(); i++) {
        sum += vec1.a[i] * vec2.a[i];
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
