//
//#include<stdio.h>
//int main()
//{
//	int i, j, k, n, yu[301], shu[301], ying[301], zong[301], id[301], t;
//	scanf("%d", &n);
//	for (i = 1;i <= n;i++)
//	{
//		scanf("%d%d%d", &yu[i], &shu[i], &ying[i]);
//		zong[i] = yu[i] + shu[i] + ying[i];
//		id[i] = i;
//	}
//	for (i = 1;i <= n;i++)
//	{
//		for (j = 2;j <= n;j++)
//		{
//			if (zong[i] < zong[j] && i < j)
//			{
//				t = yu[j];
//				yu[j] = yu[i];
//				yu[i] = t;
//				t = zong[j];
//				zong[j] = zong[i];
//				zong[i] = t;
//				t = id[j];
//				id[j] = id[i];
//				id[i] = t;
//			}
//			else if (zong[j] == zong[i] && i < j)
//			{
//				if (yu[i] < yu[j])
//				{
//					t = yu[j];
//					yu[j] = yu[i];
//					yu[i] = t;
//					t = id[j];
//					id[j] = id[i];
//					id[i] = t;
//				}
//				else if (yu[i] == yu[j] && i != j)
//				{
//					if (id[i] > id[j])
//					{
//						t = id[j];
//						id[j] = id[i];
//						id[i] = t;
//					}
//				}
//			}
//		}
//	}
//	for (i = 1;i < 6;i++)
//	{
//		printf("%d %d\n", id[i], zong[i]);
//	}
//	return 0;
//}
//
