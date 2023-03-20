//
// Created by shecannotsee on 2023/3/17.
//

#ifndef DATA_STRUCTURE_CORE_SRC_LINEAR_QUEUE_H_
#define DATA_STRUCTURE_CORE_SRC_LINEAR_QUEUE_H_

#include <memory>

namespace she {

// last-in,out-outs
template<typename T>
class queue {
 public:
  queue();

 private:
  std::unique_ptr<T> queue_ptr_;
  int size_;

 public:
  // insert
  bool enqueue(T&& element);
  // remove
  T dequeue();

 public:
  int size() const;
  T head() const;
  T tail() const;

};// class queue

};// namespace she

#endif //DATA_STRUCTURE_CORE_SRC_LINEAR_QUEUE_H_
