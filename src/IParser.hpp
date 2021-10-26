#ifndef IPARSER_HPP
#define IPARSER_HPP

#include <vector>

using EcgVector = std::vector<short>;

class IParser {
 public:
  virtual ~IParser() = default;
  virtual void parseInto(EcgVector &ret) = 0;
};

#endif  // IPARSER_HPP
