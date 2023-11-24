#pragma once

#include <string>
#include <vector>

void f_print(const std::string& str);
void f_panic(const std::string& str);
std::string f_input(const std::string& str);

template<typename T>
void push(std::vector<T>& vec, const T& val);

template<typename T>
T pop(std::vector<T>& vec);

template<typename T>
void slice(std::vector<T>& vec, int start, int end);

template<typename T>
T dot(const std::vector<T>& vec1, const std::vector<T>& vec2);

template<typename T>
typename std::enable_if<!std::is_integral<T>::value, T>::type _zero();

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type _zero();

template<typename T>
typename std::enable_if<!std::is_integral<T>::value, T>::type _one();

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type _one();
