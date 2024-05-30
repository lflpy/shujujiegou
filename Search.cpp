//#include<stdio.h>
//#include<stdlib.h>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//typedef int RecType;
//
//const static int sizel=10;
//typedef struct
//{
//	RecType rec[sizel+1];
//	int n;
//} SqTable;
///* 折半查找：BinSearch(R,x,&j)
//操作结果：根据折半查找基本思想在升序表R中查找k值，若查找成功返回k值在线性表中的下标，否则返回0，并通过指针变量j返回在升序表中查找k值共执行查找操作的次数。 */
//int BinSearch(SqTable R,RecType x,int *j)
//{
//	// 请在这里补充代码，完成本关任务
//    /********** Begin *********/
//	int low,high,mid;
//    low=0;
//    high=R.n;*j=1;
//    while(low<=high)
//    {
//        mid=(low+high)/2;
//        if(x==R.rec[mid])
//        {
//            return mid;
//        }
//        else if(x<R.rec[mid])
//        {
//            high=mid-1;
//        }
//        else{
//            low=mid+1;
//        }
//        *j=*j+1;
//
//    }return 0;
//
//
//	/********** End **********/
//}
//
//void printSqTable(SqTable R)
//{
//	int i;
//	printf("当前线性表共%d个数据，分别为：",R.n);
//	for(i=1;i<=R.n;i++)
//		printf("%4d",R.rec[i]);
//	printf("\n");
//}
////10
////15 23 67 45 28 98 87 50 91 72
////67
////int main()
////{
////	SqTable R;
////	RecType x;
////	int i,j,k;
////
////	printf("请输入线性表的长度：");
////	scanf("%d",&R.n);
////
////	printf("请逐一输入线性表的%d个数据（输入时使用空格分格）：",R.n);
////	for(i=1;i<=R.n;i++)
////		scanf("%d",&R.rec[i]);
////	printSqTable(R);
////	// 请在这里补充代码，完成本关任务
////    /********** Begin *********/
////    sort(R.rec,R.rec+sizel+1);
//
//
//
//
//
//	/********** End **********/
//	printf("排序后：\n");
//	printSqTable(R);
//	printf("请输入待查找的数据：");
//	scanf("%d",&x);
//	k=BinSearch(R,x,&j);
//	if(k==0)
//		printf("没有此数据！");
//	else
//		printf("%d在升序线性表中的%d下标位，按折半查找思想，第%d次找到！",x,k,j);
//	return 0;
//}
