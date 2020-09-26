#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#define errorPrintf printf
namespace she{

template<class E>
class array{
public:
    array();
    array(int length);
    virtual ~array();

public:
    void clear();//Empty the array.
    bool empty() const;//Determine whether it is empty.If it is empty then return true.
    int length() const;//Returns the length of the array.

public:

    E& get(int i) const;//get the value of the i position.
    void set(int i,E element);//set the value of the i position.
    void insertElement(const E& element,int i);//Insert the element.
    void deleteElement(int i);//Delete the i element.

private:
    E* m_head;//array pointer.
    int m_length;//Array length.

};//class array

}//namespace she

#endif //!_ARRAY_H_