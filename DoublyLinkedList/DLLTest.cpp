#include <iostream>

#include "DLL.cpp"

#define BIU std::cout
#define ENTER std::endl

int main()
{
    she::DLL<int> myDll ;

    int node1 = 1823 , node2 = 2646 , node3 = 3895 , node4 = 4185 , node5 = 5920;
	BIU	<<"int node1 = 1823 , node2 = 2646 , node3 = 3895 , node4 = 4185 , node5 = 5920;" 	<<ENTER;
	BIU	<<"myDll.isEmpty():"<<myDll.isEmpty()				<<ENTER<<ENTER;


    BIU << "insert" <<ENTER;
    myDll.insert(&node1);
	BIU	<<"insert:1823" 				<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;

	myDll.insert(&node2);
	myDll.insert(&node3);
	myDll.insert(&node4);
	myDll.insert(&node5);
	BIU	<<"insert:2646,3895,4185,5920"			<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())	<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	
	myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())	<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	
	int temp = 4444 ;
	myDll.update(&temp);
	BIU	<<"update:4444" 						<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	
	myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
	myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;
    myDll.remove();
	BIU	<<"remove" 								<<ENTER
		<<"myDll.view():\t"<<*(myDll.view())		<<ENTER
		<<"myDll.size():\t"<<myDll.size()		<<ENTER
		<<"myDll.isEmpty():"<<myDll.isEmpty()	<<ENTER<<ENTER;


    return 0 ;
}