#include <functional>
#include <mutex>

using std::function;

class Foo {
 private:
  std::mutex m1_;
  std::mutex m2_;
  std::unique_lock<std::mutex> lock1_;
  std::unique_lock<std::mutex> lock2_;

 public:
  Foo() : lock1_(m1_, std::try_to_lock), lock2_(m2_, std::try_to_lock) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    lock1_.unlock();
  }

  void second(function<void()> printSecond) {
    std::lock_guard<std::mutex> guard(m1_);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    lock2_.unlock();
  }

  void third(function<void()> printThird) {
    std::lock_guard<std::mutex> guard(m2_);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};