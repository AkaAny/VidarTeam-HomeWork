#pragma once
#include "LinkedList.h"

template <class T>
class RoundLinkedList
{
public:
	RoundLinkedList(LinkedList<T>* list) {
		LinkedList<T>* current = GetList();
		//转到头节点
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		this->head = current;
		//转到尾节点
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		list->next = this->head; //首尾相连，构成循环链表

		this->list = list;
	}

	template< class _Fn>
	// 顺序遍历（会无限循环）
	void EnumerateA(_Fn func /*bool (*callback)(size_t index,T val)*/) {
		RoundLinkedList<T>* current = this->head;
		size_t index = 0;
		//遍历直到尾节点
		while (!current->IsTail()) {
			bool need_to_break= func(index, current->GetValue());
			current = current->GetNext();
			index++;
		}
		printf("index:%d\n", index);
		//已经到达尾节点，再遍历一次
		func(index, current->GetValue());
	}

	void RemoveAt(size_t index) {
		LinkedList<T>* item= GetList()->RemoveAt(false,index);
		if (item == this->head) { //删除了头节点，需要重新设置头节点
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

