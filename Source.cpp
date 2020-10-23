#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct goods
{
	char name[100];
	float price;
};
void bubblesort(struct goods *Goods,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 0; k < n - 1 - i; k++)
		{
			if (Goods[k].price < Goods[k + 1].price)
			{
				char Tempname[100] = {};
				int temp = 0;
				temp = Goods[k].price;
				Goods[k].price = Goods[k + 1].price;
				Goods[k + 1].price = temp;
				strcpy(Tempname, Goods[k].name);
				strcpy(Goods[k].name, Goods[k + 1].name);
				strcpy(Goods[k+1].name,Tempname);
			}
		}
	}
}
int main() {
	struct goods *Goods;
	printf("Enter number of goods : ");
	int n;
	scanf("%d",&n);
	if (n <= 0)
	{
		printf("Error");
		return 0;
	}
	Goods = (struct goods*)malloc(n * sizeof(struct goods));
	printf("Enter name and price\n");
	for (int i = 0; i < n; i++)
	{
		printf("[%d] : ", i + 1);
		scanf("%s %f", Goods[i].name, &Goods[i].price);
		if (Goods[i].price < 0)
		{
			printf("Error");
			return 0;
		}
	}
	bubblesort(Goods,n);
	printf("\n-------------------------------------------------------------------\n");
	for (int i = 0; i <n; i++)
	{
		printf("[%d] %s %.2f baht\n",i+1,Goods[i].name,Goods[i].price);
	}
	return 0;
}