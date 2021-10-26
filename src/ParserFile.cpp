#include "ParserFile.hpp"

#include <cstring>
#include <fstream>
#include <stdexcept>

#include <iostream>

ParserFile::ParserFile(const std::string &filePath) : _filePath(filePath) {}

void ParserFile::parseInto(EcgVector &ret) {
  std::fstream file(_filePath, std::fstream::in);

  if (!file.is_open()) {
    throw std::invalid_argument("Could not open file : " + _filePath);
  }

  char buffer[7];
  file.read(buffer, 7);

  if (std::strncmp(buffer, "NbData=", 7) != 0) {
    throw std::runtime_error("Wrong format for file : " + _filePath);
  }

  int nbData = 0;
  file >> nbData;

  if (nbData <= 0) {
    throw std::runtime_error("Number of element unrecognized in file : " +
                             _filePath);
  }

  EcgVector tmp;
  tmp.reserve(nbData);
  short curValue = 0;

  for (; nbData > 0; --nbData) {
    file >> curValue;
    tmp.push_back(curValue);
  }
  ret.insert(ret.end(), tmp.begin(), tmp.end());
}

std::string ParserFile::filePath() const { return _filePath; }

void ParserFile::setFilePath(const std::string &filePath) {
  _filePath = filePath;
}