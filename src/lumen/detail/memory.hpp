#pragma once

namespace detail {

template<typename T>
T&& move(T& obj) {
  return static_cast<T&&>(obj);
}

template<typename T>
class unique_ptr {
 public:
  unique_ptr() : object_ptr_(nullptr) {}
  unique_ptr(T* address) : object_ptr_(address) {}

  inline T* get() const { return object_ptr_; }

  inline void reset(T* address = nullptr) {
    if (object_ptr_)
      delete object_ptr_;

    object_ptr_ = address;
  }

  inline T* operator->() const { return object_ptr_; }

  inline T& operator*() const { return *object_ptr_; }

  ~unique_ptr() { reset(); }

  unique_ptr(const unique_ptr&) = delete;
  unique_ptr& operator=(const unique_ptr&) = delete;

  unique_ptr(unique_ptr&& other) {
    this->object_ptr_ = other.object_ptr_;
    other.object_ptr_ = nullptr;
  }

  unique_ptr& operator=(unique_ptr&& other) {
    if (this == &other) return *this;

    reset();
    this->object_ptr_ = other.object_ptr_;
    other.object_ptr_ = nullptr;

    return *this;
  }

 private:
  T* object_ptr_;
};

} // namespace detail