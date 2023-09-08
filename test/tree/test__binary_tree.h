//
// Created by shecannotsee on 23-9-8.
//

#ifndef DATA_STRUCTURE_CORE_TEST__BINARY_TREE_H
#define DATA_STRUCTURE_CORE_TEST__BINARY_TREE_H

#include <tree/binary_tree.h>

TEST(binary_tree,base_test) {
  she::binary_tree<int> entity;
  entity.insert_root(1);/* test verification */{
    auto root = entity.get_root();
    EXPECT_EQ(root->data, 1);
    entity.insert_this_node_left(root,1);
  }


}

#endif //DATA_STRUCTURE_CORE_TEST__BINARY_TREE_H
