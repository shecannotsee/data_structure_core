#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

namespace she{

template<class E>
class BinaryTree{
    private:
        struct BTNode{
            E element ;
            int number ;//兼容重复的节点
            BTNode* leftChild ;
            BTNode* rightChild ;
        };
        BTNode* m_root;//根节点
        int m_number;//元素个数

    public:
        BinaryTree();
        virtual ~BinaryTree();

    private:
        /* 清空树
         * @param BTNode* 根节点
         */
        void clean( BTNode* );

        /* 寻找右子树的最小节点
         * @prarm BTNode* 右子树的根节点
         * @param BTNode* 节点的父节点，第一次使用该函数应传nullptr
         * @return 返回最小节点的节点指针[0]和父节点的指针[1]
         */
        BTNode** getRemoveMin( BTNode* , BTNode* );

    public:
        /* 插入元素
         * @param BTNode* 插入位置指针
         * @param E* 待插元素指针
         */
        virtual int insert( BTNode* , E* );

        /* 删除元素
         * @param BTNode* 删除位置指针
         * @param E* 待删元素
         * @param BTNode* 插入位置父节点指针，首次与根节点同时传入时应为空指针
         */
        virtual int remove( BTNode* , E* , BTNode* );

        /* 更新元素
         * @param BTNode* 更新位置指针
         * @param E* 待插入的元素值
         * @param E* 待比较的元素
         */
        virtual int update( BTNode* , E* , E* );

    public:
        /*
         * 获取根节点
         */
        BTNode* getRoot();

        /* 
         * 判断是否为空树，空则返回1，否则返回0
         */
        int isEmpty() const;

        /*
         * 返回树深
         */
        static int depth( BTNode* );

        /*
         * 查看元素
         */
        static E* view ( BTNode* );

        /*
         * 前序遍历(Preorder Traversal):根左右
         */
        static void VLR( BTNode* );

        /*
         * 中序遍历(Inorder Traversal):左根右
         */
        static void LDR( BTNode* );

        /*
         * 后序遍历(Postorder Traversal):左右根
         */
        static void LRD( BTNode* );



};//class tree

};// namespace she

#endif //!_BINARY_TREE_H_
