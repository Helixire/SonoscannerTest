#include <gtest/gtest.h>
#include "Parser.h"

namespace  {
	TEST(ParserTest, RetOne) {
	    Parser t;
	    
	    EXPECT_EQ(t.r(), 1);
	}
}

