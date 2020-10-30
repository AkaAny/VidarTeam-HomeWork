#include "C1_Liki.h"
#include "MemUtils.h"
#include <cstdlib>
#include <string>

void C1_Liki::DrawFunction(DecInt x_len, DecInt y_len, bool (*callback)(DecInt x, DecInt y))
{
	DecInt** point = MemUtils::MallocAndZeroSpace<DecInt>(x_len,y_len); //�ο����ϵ�˼·��ʵ��һ����ά�ռ�
	if (!point) {
		return;
	}
	
	for (DecInt y_pos = 0; y_pos < y_len; y_pos++)
	{
		for (DecInt x_pos = 0; x_pos < x_len; x_pos++)
		{
			//����ת�ɿռ���������ϵ�������ޣ�
			DecInt x_center = x_pos - (x_len / 2);
			DecInt y_center = y_pos - (y_len / 2);
			if (callback(x_center, y_center)) {
				printf(" *");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
