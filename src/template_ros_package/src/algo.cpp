/**
  * File description
  */

#include "algo.hpp"
#include <sstream>

std::string text_count(int count) {
  std::stringstream ss;
  ss << "hello world " << count;
  return ss.str();
}
