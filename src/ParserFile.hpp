#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "IParser.hpp"

class ParserFile : public IParser {
 public:
  ParserFile(const std::string &filePath = "");

  virtual void parseInto(EcgVector &ret) final;

  std::string filePath() const;
  void setFilePath(const std::string &filePath);

 private:
  std::string _filePath;
};

#endif  // PARSER_H
