#ifndef _SINGLY_LIST_H_
#define _SINGLY_LIST_H_
#include <stdio.h>
#define ERRORPRINTF printf
#define DEFAULT_LENGTH (128)
namespace she{

template<class E>
class singlyList{
public:
    singlyList();
    ~singlyList();

public:
    E& operator[](int position) const;
    E& getElement(int position) const;
    E* findPosition(const E& element) const;

public:
    void headInsert(const E& element);
    void tailInsert(const E& element);
    void update(int position,const E& element);
    void deletePosition(int position);
    void deleteElement(const E& element);

private:
    E* m_headPointer;
    E* m_tailPointer;
    int length;

};//class singlyList

}//namespace she

#endif //!_SINGLY_LIST_H_