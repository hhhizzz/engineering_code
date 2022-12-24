#include "1114_print_in_order.h"

#include <gtest/gtest.h>

#include <string>
#include <thread>

std::string output;

void ResetOutput() { output.clear(); }
void PrintFirst() { output.append("first"); }
void PrintSecond() { output.append("second"); }
void PrintThird() { output.append("third"); }

template <typename T>
void testPattern() {
  for (int i = 0; i < 1000; i++) {
    T foo;
    ResetOutput();

    auto first_callable = [](T* foo) { foo->first(PrintFirst); };
    auto second_callable = [](T* foo) { foo->second(PrintSecond); };
    auto third_callable = [](T* foo) { foo->third(PrintThird); };

    std::thread third_thread(third_callable, &foo);
    std::thread second_thread(second_callable, &foo);
    std::thread first_thread(first_callable, &foo);

    first_thread.join();
    second_thread.join();
    third_thread.join();
    ASSERT_EQ(output, "firstsecondthird");
  }
}

TEST(Examples, MultipleThread) {
  // testPattern<method1::Foo>();
  testPattern<method2::Foo>();
  // testPattern<method3::Foo>();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}