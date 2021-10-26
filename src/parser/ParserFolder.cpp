#include "ParserFolder.hpp"
#include <stdexcept>

ParserFolder::ParserFolder(const std::string &folderPath)
    : _folderPath(folderPath) {}

void ParserFolder::parseInto(EcgVector &ret) {
  EcgVector tmp;
  ParserFile parser;

  if (_folderPath.empty()) {
    throw std::invalid_argument("Folder Path Empty");
  }

  unsigned int index = 0;
  try {
    while (1) {
      parser.setFilePath(_folderPath + "/ecg-" + std::to_string(index) +
                         ".txt");
      parser.parseInto(tmp);
      ++index;
    }
  } catch (std::invalid_argument) {
    if (tmp.empty()) {
      throw;
    }
  }
  ret.insert(ret.end(), tmp.begin(), tmp.end());
}

std::string ParserFolder::folderPath() const { return _folderPath; }

void ParserFolder::setFolderPath(const std::string &folderPath) {
  _folderPath = folderPath;
}
