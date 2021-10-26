#ifndef PARSERFOLDER_HPP
#define PARSERFOLDER_HPP

#include "IParser.hpp"
#include "ParserFile.hpp"

class ParserFolder : public IParser {
 public:
  ParserFolder(const std::string &folderPath = "");

  virtual void parseInto(EcgVector &ret) final;

  std::string folderPath() const;
  void setFolderPath(const std::string &folderPath);

 private:
  std::string _folderPath;
};

#endif  // PARSERFOLDER_HPP
