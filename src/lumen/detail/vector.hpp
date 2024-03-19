#pragma once


namespace detail {

template<typename T>
class vector {
 public:
  vector();
  ~vector();

  explicit vector(size_t size);

  vector(const vector<T>& other);
  vector<T>& operator=(const vector<T>& other);

  vector(vector<T>&& other);
  vector<T>& operator=(vector<T>&& other);

  void push_back(const T& element);

  void resize(uint32_t size);

  void clear();

  size_t size() const;

  T at(size_t index) const;

  T operator[](size_t index) const;

 private:
  T* block_;

  size_t size_;
  size_t capacity_;
};

template<typename T>
vector<T>::vector() : block_(nullptr), size_(0), capacity_(0) {}

template<typename T>
vector<T>::vector(size_t size) : block_(new T[size]), size_(size),
                                 capacity_(size) {}

template<typename T>
vector<T>::vector(const vector<T> &other) {
  if (&other == this) return;

  this->block_ = nullptr;
  this->resize(other.capacity_);
  memcpy(this->block_, other.block_, other.size_ * sizeof(T));

  this->size_ = other.size_;
  this->capacity_ = other.capacity_;
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T> &other) {
  if (&other == this) return *this;

  this->block_ = nullptr;
  this->resize(other.capacity_);
  memcpy(this->block_, other.block_, other.size_ * sizeof(T));

  this->size_ = other.size_;
  this->capacity_ = other.capacity_;

  return *this;
}

template<typename T>
vector<T>::vector(vector<T> &&other) {
  this->block_ = other.block_;
  other.block_ = nullptr;

  this->size_ = other.size_;
  other.size_ = 0;

  this->capacity_ = other.capacity_;
  other.capacity_ = 0;
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T>&& other) {
  this->block_ = other.block_;
  other.block_ = nullptr;

  this->size_ = other.size_;
  other.size_ = 0;

  this->capacity_ = other.capacity_;
  other.capacity_ = 0;

  return *this;
}

template<typename T>
T vector<T>::at(size_t index) const { return block_[index]; }

template<typename T>
T vector<T>::operator[](size_t index) const { return at(index); }

template<typename T>
size_t vector<T>::size() const { return size_; }

template<typename T>
void vector<T>::push_back(const T &element) {
  if (size_ == capacity_)
    resize(size_ ? size_ * 2 : 1);

  block_[size_++] = element;
}

template<typename T>
void vector<T>::resize(uint32_t size) {
  auto new_block = new T[size];
  if (block_) {
    memcpy(new_block, block_, size_ * sizeof(T));
    delete[] block_;
  }

  block_ = new_block;
  capacity_ = size;
}

template<typename T>
void vector<T>::clear() {
  if (block_)
    delete block_;
}

template<typename T>
vector<T>::~vector() {
  this->clear();
}

} // namespace detail