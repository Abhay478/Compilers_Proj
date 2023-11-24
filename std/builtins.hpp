#pragma once

#include <string>
#include <vector>

void print(const std::string& str);
void panic(const std::string& str);
std::string input(const std::string& str);

template<typename T>
void push(std::vector<T>& vec, const T& val);

template<typename T>
T pop(std::vector<T>& vec);

template<typename T>
void slice(std::vector<T>& vec, int start, int end);
