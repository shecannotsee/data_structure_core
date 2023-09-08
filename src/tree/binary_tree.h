//
// Created by shecannotsee on 2023/3/17.
//

#ifndef DATA_STRUCTURE_CORE_SRC_TREE_BINARY_TREE_H_
#define DATA_STRUCTURE_CORE_SRC_TREE_BINARY_TREE_H_

#include <memory>

namespace she {

// make_unique
namespace {
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args ) {
  return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}
}

template<typename T>
struct binary_tree_node {
  explicit binary_tree_node(T value)
      : data(value),
        left(nullptr),
        right(nullptr) {}
  T data;
  std::unique_ptr<binary_tree_node<T>> left;
  std::unique_ptr<binary_tree_node<T>> right;
};

template<typename T>
class binary_tree {
 public:
  // copy:off
  binary_tree(const binary_tree&) = delete;
  binary_tree& operator=(const binary_tree&) = delete;
  // move:off
  binary_tree(binary_tree&&) = delete;
  binary_tree& operator=(binary_tree&&) = delete;
  // destructors
  ~binary_tree() = default;
  // constructors
  binary_tree() = default;

 private:
  // necessary data
  std::unique_ptr<binary_tree_node<T>> root_{nullptr};
  // unnecessary data
  auto insert_this_node(binary_tree_node<T>* node,T value,bool is_left = true) -> void {

  }
 public:

  auto insert_this_node_left(binary_tree_node<T>* node,T value) -> void {
    using left = std::true_type;
    this->insert_this_node(node,value,left::value);
  }
  auto insert_this_node_right(binary_tree_node<T>* node,T value) -> void {
    using right = std::false_type;
    this->insert_this_node(node,value,right::value);
  }

  auto get_root() -> binary_tree_node<T>* {
    return (this->root_).get();
  }

  auto insert_root(T value,bool is_left = true) -> void {
    if (this->root_ == nullptr) {
      root_ = make_unique<binary_tree_node<T>>(value);
    } else {
      this->insert_this_node(this->root_.get(),value, is_left);
    }
  }

  auto find_node(T value) -> binary_tree_node<T>* {

  }


};



} // namespace she

#endif //DATA_STRUCTURE_CORE_SRC_TREE_BINARY_TREE_H_
