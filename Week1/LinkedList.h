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

	// ȡָ��λ�õ���
	LinkedList<T>* At(bool from_head,size_t index) {
		LinkedList* current = this;
		if (from_head) { //ת��ͷ�ڵ�
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

	//�������
	LinkedList<T>* Insert(T val) {
		LinkedList<T>* next_char = new LinkedList(val);
		next_char->prev = this;
		next_char->next = nullptr; //��������
		this->next = next_char;
		return next_char;
	}

	//����׷��
	LinkedList<T>* Append(T val) {
		LinkedList* current = this;
		//������β�ڵ�
		while (!current->IsTail()) {
			current = current->next;
		}
		return current->Insert(val);
	}

	//����ɾ��
	void RemoveSelf() {
		LinkedList* current_prev = this->prev;
		LinkedList* current_next = this->next;
		if (!this->IsHead()) { //����ͷ�ڵ�
			current_prev->next = current_next;
		}
		if (!this->IsTail()) { //����β�ڵ�
			current_next->prev = current_prev;
		}
	}

	// ɾ��������ָ��λ�õ�item
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
	// ˳�����
	void EnumerateA(_Fn func /*void (*callback)(size_t index,T val)*/) {
		LinkedList<T>* current = this;
		//ת��ͷ�ڵ�
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		size_t index = 0;
		//����ֱ��β�ڵ�
		while (!current->IsTail()) {
			func(index,current->GetValue());
			current = current->GetNext();
			index++;
		}
		printf("index:%d\n", index);
		//�Ѿ�����β�ڵ㣬�ٱ���һ��
		func(index, current->GetValue());
	}

	template< class _Fn>
	// �������
	void EnumerateZ(_Fn func /*void (*callback)(size_t index,T val)*/) {
		LinkedList<T>* current = this;
		//ת��β�ڵ�
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		size_t index = 0;
		//����ֱ��ͷ�ڵ�
		while (!current->IsHead()) {
			func(index, current->GetValue());
			current = current->GetPrev();
			index++;
		}
		//�Ѿ�����ͷ�ڵ㣬�ٱ���һ��
		func(index, current->GetValue());
	}

	// ת��Ϊѭ������
	void MakeRound() {
		LinkedList<T>* current = this;
		//ת��ͷ�ڵ�
		while (!current->IsHead()) {
			current = current->GetPrev();
		}
		LinkedList<T>* head = current; //����ͷ�ڵ�
		//ת��β�ڵ�
		while (!current->IsTail()) {
			current = current->GetNext();
		}
		current->next = head;
		head->prev = current; //��ȫ��ѭ������
	}

	// ���ѭ���������ݻ����ͷ�ڵ㣬ʵ���Ͽ���������ڵ�����
	void MakeUnRound(LinkedList<T> *head) {
		LinkedList<T>* current = this;
		while (!current->IsTail()) { //˳�����
			if (current != head) {
				current = current->GetNext();
				continue;
			}
			//��ȡβ��
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


