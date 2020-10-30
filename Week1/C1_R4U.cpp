#include "C1_R4U.h"
#include "RoundLinkedList.h"

typedef  LinkedList<long> IntList;

void C1_R4U::PrintWillBePicked(long total, long round_count, long self_index)
{
	//准备卡片
	IntList* all = new IntList(1);
	for (long i = 1; i < total; i++)
	{
		all->Append(i + 1);
	}
	all->MakeRound();
	while (total >= round_count) {
		//问题：这个 round_count-2 是我试验出来的，学长能告诉我原因吗
		IntList* item_to_remove = all->RemoveAt(false, round_count - 2);
		long val = item_to_remove->GetValue();
		printf("remove index:%ld\n", val);
		if (val == self_index) {
			printf("YES 请去上早课\n");
			return;
		}
		total--;
	}
	printf("NO 睡就完事\n");
}
