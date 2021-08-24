#include "DLL.h"
#include <iostream>


template<class E>
she::DLL<E>::DLL():m_number(0),m_head(nullptr),m_tail(nullptr)
{
    /* 构造函数
     * 生成一个头节点
     */

    m_head = new node() ;
    (*m_head).pre = nullptr ;
    (*m_head).next = nullptr ;
    m_tail = m_head ;


}

template<class E>
she::DLL<E>::~DLL()
{
    /* 析构函数
     * 释放所有申请内存，尤其是头节点
     */
    while( m_number > 0 ){
        remove();
    }
    
    delete m_head ;
    m_head = nullptr ;
    m_tail = nullptr ;

}

template<class E>
void she::DLL<E>::insert(E* element)
{
    /* 插入：插在当前节点（用指针p指向的节点）的前面
     * 1.生成需要插入的节点，用一个指针temp指向待插节点
     * 2.待插节点的前驱指针，指向P前面那个节点
     * 3.p前面那个节点的后驱，指向待插入节点
     * 4.待插节点的后驱，指向p指向的节点
     * 5.P指向的节点的前驱指针，指向待插节点，插入结束
     */
    node* temp = new node() ;
    (*temp).element = *element ;// 1
    node* p = (*m_head).next ;// p
    (*temp).pre = m_head ;// 2.
    (*m_head).next = temp ;// 3.
    (*temp).next = p ;// 4.
    if( !isEmpty() ){
        (*p).pre = temp ;// 5.
        m_tail = p ;// 尾节点
    }
    else{
        m_tail = temp ;// 尾节点
    }

    m_number++;
}

template<class E>
int she::DLL<E>::remove()
{
    /* 删除：删除当前指针指向的节点（P指向的节点）
     * 1.判断该元素是否存在，若存在，则进行删除操作，不存在则不做或者抛异常
     * 2. 让P指向节点前面一个节点的后驱指针，指向P后面节点（也就是把P后驱指针的值，赋值给P前面节点的后驱指针）
     * 3.然后将P后面节点的前驱指针，指向P前面节点（也就是把P前驱指针的值，赋值给P后面节点的前驱指针）
     * 4.删除P节点申请的内存
     */
    if( m_number > 0 ){// 1.
        node* p = (*m_head).next ;
        (*m_head).next = (*p).next ;// 2.
        (*(*p).next).pre = (*p).pre ;// 3.

        m_tail = (*p).next ;

        delete p;// 4.
        p = nullptr ;

        m_number-- ;
        return 1 ;
    }
    else{
        return 0;
    }

}

template<class E>
int she::DLL<E>::update(E* element)
{
    if( m_number > 0 ){
        (*(*m_head).next).element = *element ;
        return 1 ;
    }
    else{
        return 0;
    }
}

template<class E>
inline E* she::DLL<E>::view() const
{
    if( m_number > 0 ){
        return &(*(*m_head).next).element ;
    }
    else{
        try{
			char *error = "An empty linked list was viewed!" ;
			throw error ;
		}
		catch(char *str)  {  
			std::cout << str << std::endl;  
		}  
    }
}


template<class E>
inline int she::DLL<E>::size() const
{
    return m_number ;
}


template<class E>
inline int she::DLL<E>::isEmpty() const
{
    if( m_number > 0 ){//不为空
        return 0 ;
    }
    else{
        return 1 ;
    }
}


