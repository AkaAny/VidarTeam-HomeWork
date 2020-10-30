#include "C1_R4U.h"
#include "RoundLinkedList.h"

typedef  LinkedList<long> IntList;

void C1_R4U::PrintWillBePicked(long total, long round_count, long self_index)
{
	//׼����Ƭ
	IntList* all = new IntList(1);
	for (long i = 1; i < total; i++)
	{
		all->Append(i + 1);
	}
	all->MakeRound();
	while (total >= round_count) {
		//���⣺��� round_count-2 ������������ģ�ѧ���ܸ�����ԭ����
		IntList* item_to_remove = all->RemoveAt(false, round_count - 2);
		long val = item_to_remove->GetValue();
		printf("remove index:%ld\n", val);
		if (val == self_index) {
			printf("YES ��ȥ�����\n");
			return;
		}
		total--;
	}
	printf("NO ˯������\n");
}
