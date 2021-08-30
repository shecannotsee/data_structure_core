#include "BinaryTree.h"
#include <iostream>

template<class E>
she::BinaryTree<E>::BinaryTree():m_root(nullptr),m_number(0)
{

}

template<class E>
she::BinaryTree<E>::~BinaryTree()
{
    clean( (*this).getRoot() );
}

template<class E>
void she::BinaryTree<E>::clean( BTNode* p )
{   //clean tree
    if( nullptr != p ){
        delete p ;
        (*this).clean( (*p).leftChild ) ;
        (*this).clean( (*p).rightChild ) ;
        p = nullptr ;
    }
}

template<class E>
she::BinaryTree<E>::BTNode** she::BinaryTree<E>::getRemoveMin( BTNode* p , BTNode* parent )
{
    BTNode* t_return[2];

    if( nullptr == (*p).leftChild ){
        t_return[0] = p ;
        t_return[1] = parent ;
        return *t_return ;
    }else{
        return (*this).getRemoveMin( (*p).leftChild , p ) ;
    }
}


template<class E>
int she::BinaryTree<E>::insert( BTNode* p , E* element )
{   //left small and right big
    /* 插入:根据左小右大进行插入(二叉排序树)
     * 1.为空树则直接插入，不为空则往下走
     * 1.1.生成新节点
     * 1.2.新节点初始化
     * 1.3.新节点链接到已找到的插入位置
     * 2.1.与当前节点进行比较
     * 2.2.若大于当前节点则进入右子树继续进行比较
     * 2.3.若小于当前节点，则进入左子树进行比较
     * 2.3.若等于，则修改结构体中表示节点数量的标识
     * 
     */
    if( nullptr == p ){// 1.
        BTNode* newNode = new BTNode() ;// 1.1.
        (*newNode).element = (*element) ;// 1.2.
        (*newNode).leftChild = nullptr ;// 1.2.
        (*newNode).rightChild = nullptr ;//1.2.
        (*newNode).number ++ ;//1.2.
        p = newNode ;// 1.3.
        m_number++;

        return 1;
    }
    else if ( (*p).element < (*element) ){// 2.2.
        return (*this).insert( (*p).rightChild , element ) ;
    }
    else if ( (*p).element > (*element) ){// 2.3.
        return (*this).insert( (*p).leftChild , element ) ;
    }
    else if( (*element) == (*p).element ){
        (*p).number ++ ;
        m_number++ ;
        return 1;
    }
    else{//其他未知情况
        try{
			char *error = "An unknown error occurred while inserting!" ;
			throw error ;
		}
		catch(char *str)  {  
			std::cout << str << std::endl;  
		}  
    }
}

template<class E>
int she::BinaryTree<E>::remove( BTNode* p , E* element , BTNode* parent )
{
    //找到对应节点
    if( (*p).element == *element  ){//remove
        if( --((*p).number) ){//More than one node is the same
            return 1 ;
        }

        if( nullptr != (*p).leftChild && nullptr != (*p).rightChild ){//1-1
            //通过找到待删除节点的右子树的最小数据代替该子节点的数据，并做相应的处理
            //懒惰删除：做删除标记，并进行相应处理
            //注：在二叉排序树中使用懒惰删除，可能树最终的情况和彻底删除节点的情况会不一样
            /*待添加*/
            BTNode* t_min[2] = (*this).getRemoveMin( p , nullptr ) ;

            if( (*parent).leftChild == p ){
                (*(*parent).leftChild).element = (*(t_min[0])).element ;
            }else{
                (*(*parent).rightChild).element = (*(t_min[0])).element ;
            }
            //对找到的右子树最小节点的的父节点进行处理，主要是将指向该最小节点的父节点指针置空
            if(  (*(*(t_min[1]))).leftChild == t_min[0]  ){
                (*(*(t_min[1]))).leftChild = nullptr ;
            }else{
                (*(*(t_min[1]))).rightChild = nullptr ;
            }
            //释放节点
            delete t_min ;
            t_min = nullptr ;
            m_number-- ;
            return 1 ;
            
        }else if( nullptr != (*p).leftChild && nullptr == (*p).rightChild ){//1-0
            if( (*parent).leftChild = p ){
                (*parent).leftChild = (*p).leftChild ;
            }else{
                (*parent).rightChild = (*p).leftChild ;
            }
            delete p;
            p = nullptr ;
            m_number-- ;
            return 1

        }else if( nullptr == (*p).leftChild && nullptr != (*p).rightChild ){//0-1
            if( (*parent).leftChild = p ){
                (*parent).leftChild = (*p).rightChild ;
            }else{
                (*parent).rightChild = (*p).rightChild ;
            }
            delete p;
            p = nullptr ;
            m_number-- ;
            return 1

        }else if( nullptr == (*p).leftChild && nullptr == (*p).rightChild ){//0-0
            delete p;
            p = nullptr ;
            m_number-- ;
            return 1
        }else{
            return 0;
        }

    }else if( (*p).element > *element ){//当前的大，需要去左小找
        parent = p ;
        return (*this).remove( (*p).leftChild , element , parent ) ;
    }
    else if( (*p).element < *element ){//当前的小，需要去右大找
        parent = p ;
        return (*this).remove( (*p).rightChild , element , parent ) ;
    }else{//没有找到
        return 0;
    }
    
}

template<class E>
int she::BinaryTree<E>::update( BTNode* p , E* newElement , E* comparisonElement )
{
    if( (*p).element == *comparisonElement  ){//找到，进行修改
        (*p).element = newElement ;
        return 1;
    }else if( *comparisonElement > (*p).element ){//当前的小，目标要去右大找
        return (*this).update( (*p).rightChild , newElement , comparisonElement );
    }
    else if( *comparisonElement < (*p).element ){//当前的大，目标要去左小找
        return (*this).update( (*p).leftChild , newElement , comparisonElement );
    }else{
        return 0;
    }
}

template<class E>
she::BinaryTree<E>::BTNode* she::BinaryTree<E>::getRoot()
{
    return *m_root ;
}

template<class E>
inline int she::BinaryTree<E>::isEmpty() const
{
    if( nullptr == m_root ){
        return 0;
    }
    else{
        return 1;
    }
}

template<class E>
int she::BinaryTree<E>::depth(BTNode* p)
{
    if( nullptr != p ){
        int t_left = 0 ;
        int t_right = 0 ;
        t_left = depth( (*p).leftChild ) ; //left depth
        t_right = depth( (*p).rightChild ) ;//right depth

        if( t_left > t_right ){
            return (t_left + 1 ) ;
        }
        else{
            return ( t_right + 1 ) ;
        }
    }
    else{
        return 0 ;
    }
}

template<class E>
E* she::BinaryTree<E>::view ( BTNode* p )
{
    if( nullptr != p )
    {
        return &((*p).element) ;
    }else{
        try{
			char *error = "An empty binary tree was viewed!" ;
			throw error ;
		}
		catch(char *str)  {  
			std::cout << str << std::endl;  
		}  
    }
}


template<class E>
void she::BinaryTree<E>::VLR(BTNode* p)
{//root-left-right
    if( nullptr != p ){

        std::cout<<E<<std::endl;

        VLR((*p).leftChild);

        VLR((*p).rightChild);

    }
}

template<class E>
void she::BinaryTree<E>::LDR(BTNode* p)
{//left-root-right
    if( nullptr != p ){

        LDR((*p).leftChild);

        std::cout<<E<<std::endl;

        LDR((*p).rightChild);

    }
}

template<class E>
void she::BinaryTree<E>::LRD(BTNode* p)
{//left-right-root
    if( nullptr != p ){

        LRD((*p).leftChild);

        LRD((*p).rightChild);

        std::cout<<E<<std::endl;

    }
}


