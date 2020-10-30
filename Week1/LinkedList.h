#pragma once
#include <cstdio>

template <class T>
class LinkedList
{
public:
	static LinkedList<T>* Create(const T* buf, size_t len) {
		LinkedList* current = new LinkedList(buf[0]);
		for (size_t i = 1; i < len; i++)
		{
			current = current->Insert(buf[i]);
		}
		return current;
	}

	// 取指定位置的项
	LinkedList<T>* At(bool from_head,size_t index) {
		LinkedList* current = this;
		if (from_head) { //转到头节点
			while (!current->IsHead()) {
				current = current->prev;
			}
		}
		for (size_t i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current;
	}
	LinkedList(const T val) {
		this->val = val;
	}

	//链表插入
	LinkedList<T>* Insert(T val) {
		LinkedList<T>* next_char = new LinkedList(val);
		next_char->prev = this;
		next_char->next = nullptr; //单向链表
		this->next = next_char;
		return next_char;
	}

	//链表追加
	LinkedList<T>* Append(T val) {
		LinkedList* current = this;
		//遍历到尾节点
		while (!current->IsTail()) {
			current = current->next;
		}
		return current->Insert(val);
	}

	//链表删除
	void RemoveSelf() {
		LinkedList* current_prev = this->prev;
		LinkedList* current_next = this->next;
		if (!this->IsHead()) { //不是头节点
			current_prev->next = current_next;
		}
		if (!this->IsTail()) { //不是尾节点
			current_next->prev = current_prev;
		}
	}

	// 删除并返回指定位置的item
	LinkedList* RemoveAt(bool from_head,size_t index) {
		LinkedList* item= At(from_head,index);
		item->RemoveSelf();
		return item;
	}

	bool IsHead() {
		return this->prev == nullptr;
	}

	bool IsTail() {
		return this->next == nullptr;
	}

	T GetValue() {
		return val;
	}

	LinkedList* GetPrev() {
		return this->prev;
	}

	LinkedList* GetNext() {
		return this->next;
	}

	template< class _Fn>
	// 顺序遍历
	void EnumerateA(_Fn func /*void (*callback)(size_t index,T val)*/) {
		LinkedList<T>* current = this;
		//转到头节点
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		size_t index = 0;
		//遍历直到尾节点
		while (!current->IsTail()) {
			func(index,current->GetValue());
			current = current->GetNext();
			index++;
		}
		printf("index:%d\n", index);
		//已经到达尾节点，再遍历一次
		func(index, current->GetValue());
	}

	template< class _Fn>
	// 倒序遍历
	void EnumerateZ(_Fn func /*void (*callback)(size_t index,T val)*/) {
		LinkedList<T>* current = this;
		//转到尾节点
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		size_t index = 0;
		//遍历直到头节点
		while (!current->IsHead()) {
			func(index, current->GetValue());
			current = current->GetPrev();
			index++;
		}
		//已经到达头节点，再遍历一次
		func(index, current->GetValue());
	}

	// 转换为循环链表
	void MakeRound() {
		LinkedList<T>* current = this;
		//转到头节点
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		LinkedList<T>* head = current; //缓存头节点
		//转到尾节点
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		current->next = head;
		head->prev = current; //完全的循环链表
	}

	// 解除循环链表（根据缓存的头节点，实际上可以在任意节点解除）
	void MakeUnRound(LinkedList<T> *head) {
		LinkedList<T>* current = this;
		while (!current->IsTail()) { //顺序遍历
			if (current != head) {
				current = current->GetNext();
				continue;
			}
			//获取尾项
			LinkedList<T>* tail = current->prev;
			tail->next = nullptr;
			current->prev = nullptr;
			break;
		}
	}
private:
	T val;
	LinkedList* prev = nullptr;
	LinkedList* next = nullptr;
};

typedef LinkedList<char> String;


