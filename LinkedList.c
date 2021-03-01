#include "LL.h"

bool isEmpty()
{
		if (head == NULL)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
}

void doesNotExist()
{
	system("cls");
	
	printf("\nNO EXISTING STATISTICIAN\n\n");
	
	system("pause");
	system("cls");
	
	return;
}

Statistician newStatistician()
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	if (isEmpty())
	{
		newNode->data = NULL;
		newNode->next = NULL;
		
		head = newNode;
		tail = newNode;
	
		system("cls");
	
		printf("\nNEW STATISTICIAN CREATED SUCCESSFULLY\n\n");
	
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		
		printf("\nSTATISTICIAN ALREADY CREATED\n\n");
		
		system("pause");
		system("cls");
	}
	
}

void destroyStatistician(Statistician *s)
{
	struct node *currentNode = head;
	nodePtr *next = NULL;
	
	while (currentNode != NULL)
	{
		next = currentNode->next;
		free(currentNode);
		currentNode = next;
	}
	head = NULL;
	
	system("cls");
	
	printf("\nEXISTING STATISTICIAN SUCCESSFULLY DESTROYED\n\n");
	
	system("pause");
	system("cls");
}

void add(Statistician s, int x)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *ptr;
	
	if (newNode == NULL)
	{
		printf("\nMemory cannot be allocated.");
		return;
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}	
}

void removeData(Statistician s, int x)
{
	struct node *currentNode = head;
	struct node *prev = NULL;
	int count = 0;
	
	while (currentNode != NULL)
	{
		if (currentNode->data == x)
		{
			if (prev == NULL)
			{
				head = currentNode->next;
			}
			else
			{
				prev->next = currentNode->next;
			}
			
		printf("DATA SUCCESSFULLY REMOVED\n\n");
		free(currentNode);
		
		count = 1;
		
		break;
		}
		
		prev = currentNode;
		currentNode = currentNode->next;
	}
	
	if (count == 0)
	{
		printf("DATA NOT FOUND\n\n");
	}
}

void getData(Statistician s)
{
	struct node *ptr;
	struct node *tempNode = head;
	
	if (tempNode->data == 0)
	{
		head = head->next;
	}
	
	ptr = head;
	
	system("cls");
	
	printf("\nData : ");
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void displayData(Statistician s)
{
	getData(s);
	
	int length, min, max, ran, median, mod, count;
	float mean, var, sdv;
	
	min = minimum(s);
	max = maximum(s);
	ran = range(s, min, max);
	mean = getMean(s);
	median = getMedian(s);
	var = getVariance(s);
	sdv = standardDeviation(s);
	
	printf("\nMinimum Number: %d",min);
	printf("\nMaximum Number: %d",max);
	printf("\nRange: %d",ran);
	printf("\nMean: %f",mean);
	printf("\nMedian: %d",median);
	printf("\nVariance: %f",var);
	printf("\nStandard Deviation: %f",sqrt(var));
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}
