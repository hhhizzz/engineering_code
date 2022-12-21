#include <condition_variable>
#include <functional>
#include <mutex>

using std::function;

namespace method1 {
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
}  // namespace method1

namespace method2 {
class Foo {
 private:
  std::condition_variable cv_;
  std::mutex mu_;
  int k_ = 0;

 public:
  Foo() {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    k_ = 1;
    cv_.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lock(mu_);
    cv_.wait(lock, [this]() { return k_ == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    k_ = 2;
    cv_.notify_all();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lock(mu_);
    cv_.wait(lock, [this]() { return k_ == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};

}  // namespace method2
