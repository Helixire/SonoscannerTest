#include <gtest/gtest.h>
#include "parser/ParserFolder.hpp"

namespace {

TEST(ParserFolderTest, FileNotFound) {
  ParserFolder parser("thisPathDoesNotExist");

  EcgVector data;
  ASSERT_THROW(parser.parseInto(data), std::invalid_argument);
}

TEST(ParserFolderTest, NoFile) {
  ParserFolder parser;

  EcgVector data;
  ASSERT_THROW(parser.parseInto(data), std::invalid_argument);
}

TEST(ParserFolderTest, ParseFolder) {
  ParserFolder parser("./data/parser");

  EcgVector data;
  parser.parseInto(data);

  EcgVector expectedData{-444, -431, -304,  -91, 272, 400, 245,  -146,
                         -476, -492, -1080, 722, 812, 969, 1212, 1571};
  ASSERT_EQ(data, expectedData);
  // Test Insert into existing vector

  parser.parseInto(data);
  expectedData.insert(expectedData.end(), expectedData.begin(),
                      expectedData.end());
  ASSERT_EQ(data, expectedData);
}

}  // namespace