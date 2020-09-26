#include "array.h"

using namespace she;

template<class E>
array<E>::array(){
    m_head=new E(100);
    m_length=100;
    (*this).clear();
}

template<class E>
array<E>::array (int length){
    m_head=new E(length);
    m_length=length;
    (*this).clear();
}

template<class E>
array<E>::~array(){
    delete []m_head;
    m_head=nullptr;
}

template<class E>
void array<E>::clear(){
    for(int i=0;i<m_length;i++){
        *(m_head+i)=0;
    }
}

template<class E>
bool array<E>::empty() const{
    if(m_length!=0){
        return false;
    }
    else{//m_length==0
        return true;
    }
}

template<class E>
int array<E>::length() const{
    return m_length;
}



template<class E>
E& array<E>::get(int i) const{
    if(i<m_length){
        return *(m_head+i);
    }
    else{
        errorPrintf("Refused to visit.");
    }
}

template<class E>
void array<E>::set(int i,E element){
    if(i<m_length){
        *(m_head+i)=element;
    }
    else{
        errorPrintf("Refused to visit.");
    }
}

template<class E>
void array<E>::insertElement(const E& element,int i){

}

template<class E>
void array<E>::deleteElement(int i){
    
}