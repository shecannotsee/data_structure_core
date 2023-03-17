#include "array.h"

using namespace she;

template<class E>
array<E>::array(){
    m_createArray();
}

template<class E>
array<E>::array(int length){
    m_createArray(length);
}

template<class E>
array<E>::array(int length,const E& element){
    m_createArray(length);
    for(int i=0;i<m_length;i++){
        *(m_head+i)=element;
    }
}

template<class E>
array<E>::~array(){
    delete []m_head;
    m_head=nullptr;
}

template<class E>
int array<E>::length() const{
    return m_length;
}

template<class E>
E& array<E>::operator[](int position) const{
    if(position<m_length){
        return *(m_head+position);
    }
    else{
        ERRORPRINTF("error:Array access violation.\n");
        return *(m_head+position);
    }
}

template<class E>
E& array<E>::get(int position) const{
    if(position<m_length){
        return *(m_head+position);
    }
    else{
        ERRORPRINTF("error:Array access violation.\n");
        return *(m_head+position);
    }
}

template<class E>
void array<E>::set(const E& element,int position){
    if(position<m_length){
        *(m_head+position)=element;
    }
    else{
        ERRORPRINTF("error:Array access violation,refused to visit.\n");
    }
}

template<class E>
void array<E>::m_createArray(int length){
    if(length<=0){
        length=DEFAULT_LENGTH;
        ERRORPRINTF("error:The input parameter is incorrect.\n");
    }
    m_head=new E(length);
    m_length=length;
}