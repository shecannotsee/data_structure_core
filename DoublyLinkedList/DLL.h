#ifndef _DLL_H_
#define _DLL_H_

namespace she{

template<class E>
class DLL{
    public:
        DLL();
        ~DLL();
    public:
        /*
         * 插入元素
         */
        void insert(E* element);

        /*
         * 删除元素
         */
        int remove();

        /*
         * 修改元素
         */
        int update(E* element);

        /*
         * 查看元素
         */
        E* view() const;

    private:
        struct node
        {
            E element;      //结点数据
            node* pre;   //前驱指针
            node* next;  //后驱指针
        };
        
        node* m_head;//头指针
        node* m_tail;//尾指针

    public:
        /*
         * 返回实际元素个数
         */
        int size() const;

        /*
         * 判断链表是否为空，空则返回1，否则0
         */
        int isEmpty() const;
    
    private:
        int m_number;//元素个数

};//class DLL

};//namespace

#endif //!_DLL_H_