//
// Created by shecannotsee on 2023/3/17.
//
#include <iostream>
#include "global_test_set.h"
#include "test__example.h"
// test_suite
#include "tree/test__binary_tree.h"
// easy_test


int main(int argc,char* argv[]) {
  std::cout << YELLOW_COLOR << "Start test " << RESET_COLOR << std::endl;
  constexpr bool easy_test  = false;
  constexpr bool test_suite = true;
  if(easy_test) {

  }

  if(test_suite) {
    testing::InitGoogleTest();

    if (RUN_ALL_TESTS() == 0) {
      std::cout << GREEN_COLOR << "Pass the test." << RESET_COLOR << std::endl;
    } else {
      std::cout << RED_COLOR << "Failed the test." << RESET_COLOR << std::endl;
    }
  }

  return 0;
};
