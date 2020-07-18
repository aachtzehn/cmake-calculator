/*
 * LibTest.cpp
 *
 *  Created on: 18.07.2020
 *      Author: andreas
 */

#include "pg/Adder.h"
#include "pg/Terminal.h"
#include "pg/IExpr.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;

class MockTerminal : public pg::IExpr {
public:
	MOCK_METHOD0(execute, double());
};

TEST(AdderTest, AdderTest) {
	MockTerminal mt1;
	MockTerminal mt2;

	//EXPECT_CALL(mt1, execute()).Times(AtLeast(1));
	//EXPECT_CALL(mt2, execute()).Times(AtLeast(1));
	EXPECT_CALL(mt1, execute()).WillOnce(Return(1.0));
	EXPECT_CALL(mt2, execute()).WillOnce(Return(2.0));

	pg::Adder a(mt1, mt2);

	ASSERT_EQ(3.0, a.execute());
}

TEST(TerminalTest, PositiveNos) {
	pg::Terminal t1(1.0);
	pg::Terminal t2(2.0);
	pg::Terminal t3(99999999.0);

	ASSERT_EQ(1.0, t1.execute());
	ASSERT_EQ(2.0, t2.execute());
	ASSERT_EQ(99999999.0, t3.execute());
}

TEST(TerminalTest, NegativeNos) {
	pg::Terminal t1(-1.0);
	pg::Terminal t2(-2.0);
	pg::Terminal t3(-99999999.0);

	ASSERT_EQ(-1.0, t1.execute());
	ASSERT_EQ(-2.0, t2.execute());
	ASSERT_EQ(-99999999.0, t3.execute());
}

TEST(TerminalTest, Zero) {
	pg::Terminal t1(0.0);

	ASSERT_EQ(0.0, t1.execute());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
