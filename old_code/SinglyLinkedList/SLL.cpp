#include "SLL.h"
#include <iostream>

using namespace she;

template<class E>
SLL<E>::SLL():m_number(0),m_count(0)
{
	m_head = new node();
	(*m_head).next = nullptr ;
}

template<class E>
SLL<E>::~SLL()
{
	int temp ;
	while( !isEmpty() ){
		temp = drop() ;
	}
	
	delete m_head ;
	m_head = nullptr ;
}

template<class E>
void SLL<E>::insert(E* element)
{
	node* next ;
	next = new node() ;//创建新的节点
	(*next).element = *element ;//新的节点数据域赋值
	(*next).next = (*m_head).next ;//将头指针指向的第一个节点赋值给新节点，保证找得到后续节点
	(*m_head).next = next ;//将新的节点更新为头指针指向的节点
	
	m_number++ ;
}

template<class E>
int SLL<E>::drop()
{
	if( !isEmpty() ){
		node* temp ;
		temp = (*m_head).next ;
		delete m_head ;
		m_head = temp ;
		
		m_number-- ;
		
		return 1;
	}
	else{
		return 0;
	}
}

template<class E>
int SLL<E>::update( E* element )
{
	if( !isEmpty() ){
		(*(*m_head).next).element = *element ;
		return 1 ;
	}
	else{
		return 0 ;
	}
}

template<class E>
E SLL<E>::view() const
{
	if( !isEmpty() ){
		return (*(*m_head).next).element ;
	}
	else{//查看空链表，异常捕捉
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
int SLL<E>::size() const
{
	return m_number;
}

template<class E>
int SLL<E>::isEmpty() const
{
	if( m_number == 0 && (*m_head).next == nullptr ){
		return 1;
	}
	else{
		return 0;
	}
}
