#include <gtest/gtest.h>
#include "ParserFile.hpp"

namespace {
TEST(ParserFileTest, ParseFile) {
  ParserFile parser("./data/parser/ecg-0.txt");

  EcgVector data;
  parser.parseInto(data);

  EcgVector expectedData{-444, -431, -304, -91,  272,
                         400,  245,  -146, -476, -492};
  ASSERT_EQ(data, expectedData);

  // Test Insert into existing vector

  parser.parseInto(data);
  expectedData.insert(expectedData.end(), expectedData.begin(),
                      expectedData.end());
  ASSERT_EQ(data, expectedData);
}

TEST(ParserFileTest, FileNotFound) {
  ParserFile parser("thisPathDoesNotExist");

  EcgVector data;
  ASSERT_THROW(parser.parseInto(data), std::invalid_argument);
}

TEST(ParserFileTest, NoFile) {
  ParserFile parser;

  EcgVector data;
  ASSERT_THROW(parser.parseInto(data), std::invalid_argument);
}

// TODO(PBK) Test parser with malformated file (/dev/random, gibrish, empty, not
// number, too big number, too small number, ...)

}  // namespace
