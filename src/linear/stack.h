//
// Created by shecannotsee on 2023/3/17.
//

#ifndef DATA_STRUCTURE_CORE_SRC_LINEAR_STACK_H_
#define DATA_STRUCTURE_CORE_SRC_LINEAR_STACK_H_

#include <memory>

namespace she {

// LIFO:last-in,first-outs
template<typename T>
class stack {
 public:
  stack(int stack_size);

 private:
  std::unique_ptr<T> stack_ptr;
  int size_;

 public:
  bool push(T&& element);
  T pop();

 public:
  int size() const;
  T copy_pop() const;


};// class stack

};// namespace she

#endif //DATA_STRUCTURE_CORE_SRC_LINEAR_STACK_H_
