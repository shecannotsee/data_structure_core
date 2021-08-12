#include <iostream>

#include "SLL.cpp"

#define BIU std::cout
#define ENTER std::endl

int main()
{
	she::SLL<int> mySll;
	
	int node1=1545,node2=2232,node3=3433,node4=4546,node5=5123;
	BIU	<<"int node1=1545,node2=2232,node3=3433,node4=4546,node5=5123;" 	<<ENTER;
	BIU	<<"mySll.isEmpty()��"<<mySll.isEmpty()				<<ENTER<<ENTER;
	
	mySll.insert(&node1);
	BIU	<<"insert��1545" 				<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;

	mySll.insert(&node2);
	mySll.insert(&node3);
	mySll.insert(&node4);
	mySll.insert(&node5);
	BIU	<<"insert��2232,3433,4546,5123"			<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	
	mySll.drop();
	BIU	<<"drop" 								<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	
	int temp = 4444 ;
	mySll.update(&temp);
	BIU	<<"update��4444" 						<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	
	mySll.drop();
	BIU	<<"drop" 								<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	mySll.drop();
	BIU	<<"drop" 								<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	mySll.drop();
	BIU	<<"drop" 								<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
	mySll.drop();
	BIU	<<"drop" 								<<ENTER
		<<"mySll.view()��\t"<<mySll.view()		<<ENTER
		<<"mySll.size()��\t"<<mySll.size()		<<ENTER
		<<"mySll.isEmpty()��"<<mySll.isEmpty()	<<ENTER<<ENTER;
 
	return 0 ;
}