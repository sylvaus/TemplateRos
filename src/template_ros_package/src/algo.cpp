/**
  * File description
  */

#include <sstream>
#include "algo.hpp"

std::string text_count(int count)
{
  std::stringstream ss;
  ss << "hello world " << count;
  return ss.str();
}
