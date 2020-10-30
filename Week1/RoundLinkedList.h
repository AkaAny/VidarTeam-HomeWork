#pragma once
#include "LinkedList.h"

template <class T>
class RoundLinkedList
{
public:
	RoundLinkedList(LinkedList<T>* list) {
		LinkedList<T>* current = GetList();
		//ת��ͷ�ڵ�
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		this->head = current;
		//ת��β�ڵ�
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		list->next = this->head; //��β����������ѭ������

		this->list = list;
	}

	template< class _Fn>
	// ˳�������������ѭ����
	void EnumerateA(_Fn func /*bool (*callback)(size_t index,T val)*/) {
		RoundLinkedList<T>* current = this->head;
		size_t index = 0;
		//����ֱ��β�ڵ�
		while (!current->IsTail()) {
			bool need_to_break= func(index, current->GetValue());
			current = current->GetNext();
			index++;
		}
		printf("index:%d\n", index);
		//�Ѿ�����β�ڵ㣬�ٱ���һ��
		func(index, current->GetValue());
	}

	void RemoveAt(size_t index) {
		LinkedList<T>* item= GetList()->RemoveAt(false,index);
		if (item == this->head) { //ɾ����ͷ�ڵ㣬��Ҫ��������ͷ�ڵ�
			this->head = item->next;
		}
	}

	LinkedList<T>* GetList() {
		return this->list;
	}
private:
	LinkedList<T>* head = nullptr;
	LinkedList<T>* list = nullptr;
};

