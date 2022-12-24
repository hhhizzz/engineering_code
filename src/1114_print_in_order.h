#include <condition_variable>
#include <functional>
#include <future>
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

// It's not a perfect solution, if the notify is called before the wait, the
// whole process will be blocked
namespace method2 {
class Foo {
 private:
  std::condition_variable cv_;
  std::mutex mu_;
  int k_ = 0;

 public:
  Foo() = default;

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
    cv_.notify_one();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lock(mu_);
    cv_.wait(lock, [this]() { return k_ == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};

}  // namespace method2

namespace method3 {
class Foo {
 private:
  std::promise<void> pro1_, pro2_;

 public:
  Foo() = default;

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pro1_.set_value();
  }

  void second(function<void()> printSecond) {
    pro1_.get_future().wait();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pro2_.set_value();
  }

  void third(function<void()> printThird) {
    pro2_.get_future().wait();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
}  // namespace method3
