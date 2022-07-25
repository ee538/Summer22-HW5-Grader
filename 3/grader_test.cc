#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

template <class T>
void PrintCollection(T& input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

TEST(FindAllPasswords, AllPasswordsContainAWordInTheDictionary) {
  std::unordered_set<std::string> valid_passwords = {"aa", "bad", "sad", "aa",
                                                     "bbb"};

  std::unordered_set<std::string> dictionary = {"a", "b"};

  std::cout << "valid_passwords:" << std::endl;
  PrintCollection(valid_passwords);
  std::cout << "dictionary:" << std::endl;
  PrintCollection(dictionary);

  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};
  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, NoValidPasswordExists) {
  std::unordered_set<std::string> dictionary = {"a", "b"};

  std::unordered_set<std::string> valid_passwords = {};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords0) {
  std::unordered_set<std::string> dictionary = {"ab", "cd"};
  std::unordered_set<std::string> valid_passwords = {"abb", "cdd", "aa", "j"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aa", "j"};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords1) {
  std::unordered_set<std::string> dictionary = {"ab", "ho"};
  std::unordered_set<std::string> valid_passwords = {"aji", "jho", "aa", "j"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aji", "aa", "j"};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords2) {
  std::unordered_set<std::string> dictionary = {"c", "d", "e", "f"};
  std::unordered_set<std::string> valid_passwords = {"abc", "tin", "aa", "j"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"aa", "j", "tin"};

  auto actual = FindAllPasswords(blackbox, 3);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords3) {
  std::unordered_set<std::string> dictionary = {"bad", "sad", "a"};
  std::unordered_set<std::string> valid_passwords = {"asad", "bada", "zz", "aa",
                                                     "jim",  "xta",  "xtb"};
  BlackBox blackbox(valid_passwords, dictionary);

  std::unordered_set<std::string> expected = {"jim", "xtb", "zz"};

  auto actual = FindAllPasswords(blackbox, 4);

  EXPECT_EQ(actual, expected);
}

TEST(FindAllPasswords, SimplePasswords5) {
  std::unordered_set<std::string> dictionary = {"bad", "sad", "f", "t"};

  std::unordered_set<std::string> valid_passwords = {
      "asad", "bada", "zz", "aa", "bbbbb", "bcdef", "jklmn", "trojan", "apple"};

  BlackBox blackbox(valid_passwords, dictionary);
  std::unordered_set<std::string> expected = {"aa", "bbbbb", "zz", "jklmn",
                                              "apple"};

  auto actual = FindAllPasswords(blackbox, 5);

  EXPECT_EQ(actual, expected);
}
