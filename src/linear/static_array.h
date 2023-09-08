//
// Created by shecannotsee on 2023/3/20.
//

#ifndef DATA_STRUCTURE_CORE_SRC_LINEAR_ARRAY_H_
#define DATA_STRUCTURE_CORE_SRC_LINEAR_ARRAY_H_

#include <memory>

namespace she {

template<typename T>
class static_array {
 public:
  static_array();
  static_array(int capacity);
  ~static_array() = default;


 private:
  std::unique_ptr<T> array_ptr_;
  int size_;// numbers of element
  int capacity_;// max element numbers

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
