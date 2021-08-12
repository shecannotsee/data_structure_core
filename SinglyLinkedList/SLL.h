/**
	单链表操作实现
*/
#ifndef _SLL_H_
#define _SLL_H_

namespace she{

template<class E>
class SLL
{
	public:
		SLL();
		virtual ~SLL();
	
	public:
		/** @brief 从头部插入
		@param element 插入的元素
		*/
		void insert(E* element);
		
		/** @brief 删除当前数据
		@return 1修改成功；0修改失败
		*/
		int drop();
		
		/** @brief 修改当前元素
		@param element 修改的元素内容
		@return 1修改成功；0修改失败
		*/
		int update(E* element);
		
		/** @brief 查找元素，只读
		*/
		E view() const;

	private:
		struct node{
			E element;//节点数据
			node* next;//节点指针
		};
		
		node* m_head;//头指针

	public:
		/** @brief 返回元素个数
		*/
		int size() const;
		
		/** @brief 判空，空则返回1，否则0
		*/
		int isEmpty() const;
	
	private:
		int m_number;//元素个数
		int m_count;//计数器，头指针复位时归零
		

};//class SLL

}//namespace she


#endif //! _SLL_H_