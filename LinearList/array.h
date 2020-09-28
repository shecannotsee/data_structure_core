#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#define ERRORPRINTF printf
#define DEFAULT_LENGTH (128)
namespace she{

template<class E>
class array{
public:
    /** @brief Construct an array with default length(128).
    
    */
    array();

    /** @brief Construct an array with specified length.
    
    @param length The length of the array.
    */
    array(int length);

    /** @brief Construct an array with specified length and initial element.
    
    @param length The length of the array.
    @param element The initial value of the array.
    */
    array(int length,const E& element);

    /** @brief Destructor.
    
    Frees dynamically allocated array memory space,and set the head pointer to null.
    */
    virtual ~array();

public:
    /** @brief Returns the length of the array.
    
    */
    int length() const;

    /** @brief Get the element of the position.
    
    @param position Position of element.
    */
    E& operator[](int position) const;

    /** @brief Get the element of the position.
    
    @param position Position of element.
    */
    E& get(int position) const;

public:
    /** @brief Set the element of the position.
    
    @param position Position of element.
    @param element Elements that need to be modified.
    */
    void set(const E& element,int position);

private:
    /** @brief array pointer.
    
    */
    E* m_head;
    
    /** @brief Array length.
    
    */
    int m_length;

    /** @brief Construct and initialize the array.
    
    @param length The length of array(default length is 128).
    */
    void m_createArray(int length=DEFAULT_LENGTH);

};//class array

}//namespace she

#endif //!_ARRAY_H_