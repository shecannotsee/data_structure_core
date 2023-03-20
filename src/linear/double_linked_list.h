//
// Created by shecannotsee on 2023/3/17.
//

#ifndef DATA_STRUCTURE_CORE_SRC_LINEAR_DOUBLE_LINKED_LIST_H_
#define DATA_STRUCTURE_CORE_SRC_LINEAR_DOUBLE_LINKED_LIST_H_

#include <memory>

namespace she {

template<typename T>
class double_linked_list {
 private:
  struct node {
    T value{};
    std::unique_ptr<node> next{nullptr};
  };
 public:
  double_linked_list();

 private:
  std::unique_ptr<node> head_ptr_;
  std::unique_ptr<node> tail_ptr_;
  int size_;

 public:
  // insert from head
  bool insert_in_head(T&& element);
  // insert from tail
  bool add_in_tail(T&& element);
  // delete from head
  bool remove_in_head();
  // delete from tail
  bool remove_in_tail();


  // delete current node
  bool remove(node* p);

 public:
  int size() const;
  node* begin() const;
  node* end() const;


};// class double_linked_list

};// namespace she

#endif //DATA_STRUCTURE_CORE_SRC_LINEAR_DOUBLE_LINKED_LIST_H_
