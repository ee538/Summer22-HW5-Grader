#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Fibonacci, Test1) {
  EXPECT_EQ(Fibonacci(-1), 1);
  EXPECT_EQ(Fibonacci(0), 1);
  EXPECT_EQ(Fibonacci(1), 1);
}

TEST(Fibonacci, Test2) {
  std::vector<int> expecteds{1, 1, 2, 3, 5, 8, 13, 21, 34};
  for (int i = 0; i < expecteds.size(); ++i) {
    EXPECT_EQ(Fibonacci(i), expecteds[i]);
  }
}
//-----------------------------------------------------------------------------
TEST(CoinChangeMemo, Test1) {
  std::vector<int> coins = {1, 2, 5};

  EXPECT_EQ(CoinChangeMemo(coins, 11), 3);
}

TEST(CoinChangeMemo, Test2) {
  std::vector<int> coins = {2, 2, 5};

  EXPECT_EQ(CoinChangeMemo(coins, 11), 4);
}

TEST(CoinChangeMemo, Impossible) {
  std::vector<int> coins = {4, 5};
  EXPECT_EQ(CoinChangeMemo(coins, 11), -1);
}

TEST(CoinChangeMemo, TestWith10) {
  std::vector<int> coins = {2, 4};
  EXPECT_EQ(CoinChangeMemo(coins, 10), 3);
}

TEST(CoinChangeMemo, TestWith50) {
  std::vector<int> coins = {2, 4};
  EXPECT_EQ(CoinChangeMemo(coins, 100), 25);
}

TEST(CoinChangeMemo, TestWithLargerVector) {
  std::vector<int> coins = {84,  457, 478, 309, 350, 349,
                            422, 469, 100, 432, 188};
  EXPECT_EQ(CoinChangeMemo(coins, 6099), 13);
}
//-----------------------------------------------------------------------------
TEST(CoinChangeTabulation, Test1) {
  std::vector<int> coins = {1, 2, 5};

  EXPECT_EQ(CoinChangeTabulation(coins, 11), 3);
}

TEST(CoinChangeTabulation, Test2) {
  std::vector<int> coins = {2, 2, 5};

  EXPECT_EQ(CoinChangeTabulation(coins, 11), 4);
}

TEST(CoinChangeTabulation, Impossible) {
  std::vector<int> coins = {4, 5};
  EXPECT_EQ(CoinChangeTabulation(coins, 11), -1);
}

TEST(CoinChangeTabulation, TestWith10) {
  std::vector<int> coins = {2, 4};
  EXPECT_EQ(CoinChangeTabulation(coins, 10), 3);
}

TEST(CoinChangeTabulation, TestWith50) {
  std::vector<int> coins = {2, 4};
  EXPECT_EQ(CoinChangeTabulation(coins, 100), 25);
}

TEST(CoinChangeTabulation, TestWithLargerVector) {
  std::vector<int> coins = {84,  457, 478, 309, 350, 349,
                            422, 469, 100, 432, 188};
  EXPECT_EQ(CoinChangeTabulation(coins, 6099), 13);
}