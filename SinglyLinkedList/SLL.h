/**
	���������ʵ��
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
		/** @brief ��ͷ������
		@param element �����Ԫ��
		*/
		void insert(E* element);
		
		/** @brief ɾ����ǰ����
		@return 1�޸ĳɹ���0�޸�ʧ��
		*/
		int drop();
		
		/** @brief �޸ĵ�ǰԪ��
		@param element �޸ĵ�Ԫ������
		@return 1�޸ĳɹ���0�޸�ʧ��
		*/
		int update(E* element);
		
		/** @brief ����Ԫ�أ�ֻ��
		*/
		E view() const;

	private:
		struct node{
			E element;//�ڵ�����
			node* next;//�ڵ�ָ��
		};
		
		node* m_head;//ͷָ��

	public:
		/** @brief ����Ԫ�ظ���
		*/
		int size() const;
		
		/** @brief �пգ����򷵻�1������0
		*/
		int isEmpty() const;
	
	private:
		int m_number;//Ԫ�ظ���
		int m_count;//��������ͷָ�븴λʱ����
		

};//class SLL

}//namespace she


#endif //! _SLL_H_