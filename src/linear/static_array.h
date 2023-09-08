//
// Created by shecannotsee on 2023/3/20.
//

#ifndef DATA_STRUCTURE_CORE_SRC_LINEAR_ARRAY_H_
#define DATA_STRUCTURE_CORE_SRC_LINEAR_ARRAY_H_

#include <memory>
#include <array>
#include <map>

namespace she {

template<typename T,typename std::size_t>
class static_array {
 public:
  // copy:off
  static_array(const static_array&) = delete;
  static_array& operator=(const static_array&) = delete;
  // move:off
  static_array(static_array&&) = delete;
  static_array& operator=(static_array&&) = delete;
  // destructors
  ~static_array() = default;
  // constructors
  static_array();
  static_array(size_t size_);


 private:
  std::unique_ptr<T[]> array_ptr_;
  std::size_t size_;

 public:
  // insert : array[pos]->array[pos+1], total nums ++
  bool insert(int pos);
  // array[pos+1] -> array[pos], total nums --
  bool remove(int pos);

 public:
  T& operator[](int pos) const;
  int size() const;
  int capacity() const;

};// class static_array

};// namespace she

#endif //DATA_STRUCTURE_CORE_SRC_LINEAR_ARRAY_H_
