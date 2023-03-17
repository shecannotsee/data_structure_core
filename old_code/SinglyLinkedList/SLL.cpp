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
	next = new node() ;//�����µĽڵ�
	(*next).element = *element ;//�µĽڵ�������ֵ
	(*next).next = (*m_head).next ;//��ͷָ��ָ��ĵ�һ���ڵ㸳ֵ���½ڵ㣬��֤�ҵõ������ڵ�
	(*m_head).next = next ;//���µĽڵ����Ϊͷָ��ָ��Ľڵ�
	
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
	else{//�鿴�������쳣��׽
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
