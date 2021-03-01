#include "LL.h"

int getLength(Statistician s)
{
	int len = 0;
	struct node *ptr = head;
	
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	
	return len;
}

int minimum(Statistician s)
{
	int i;
	
	struct node *ptr = head;
	
	int min = ptr->data;
	
	while (ptr != NULL)
	{
		if (min > ptr->data)
		{
			min = ptr->data;
		}
		
		ptr = ptr->next;
	}
	
	return min;
}

int maximum(Statistician s)
{
	int i;
	
	struct node *ptr = head;
	
	int max = ptr->data;
	
	while (ptr != NULL)
	{
		if (max < ptr->data)
		{
			max = ptr->data;
		}
		
		ptr = ptr->next;
	}
	
	return max;
}

int range(Statistician s, int min, int max)
{
	int range;
	
	range = max - min;
	
	return range;
}

float getMean(Statistician s)
{
	int count = 0;
	int sum = 0;
	float mean = 0.0;
	
	struct node *currentNode = head;
	
	while (currentNode != NULL)
	{
		count++;
		sum += currentNode->data;
		currentNode = currentNode->next;
	}
	
	mean = (double)sum / count;
	
	return mean;
}

float getMedian(Statistician s)
{
	int sum = 0;
	float median = 0.0;
	
	struct node *ptr1 = head;
	struct node *ptr2 = head;
	struct node *prev = head;
	struct node *ptr3;
	
	if (head != NULL)
	{
		while (ptr2 != NULL && ptr2->next != NULL)
		{
			ptr3 = ptr2->next;
			ptr2 = ptr3->next;
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		
		if ((getLength(s) % 2) != 0)
		{
			median = ptr1->data;
			return median;
		}
		else
		{
			sum = ptr1->data + prev->data;
			median = (double)sum/2;
			return median;
		}
	}
}

float getVariance(Statistician s)
{
	int i, sum, mean, length = 0;
	int a[length];
	float sumSqr, var;
	
	struct node *ptr = head;
	struct node *currentNode = head;
	
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	
	while (currentNode != NULL)
	{
		a[i++] = currentNode->data;
		currentNode = currentNode->next;
	}
	
	mean = getMean(s);
	
	for (i = 0; i < length; i++)
	{
		sumSqr += (a[i] - mean)*(a[i] - mean);
	}
	
	var = sumSqr / length;
	
	return var;
}

float standardDeviation(Statistician s)
{
	float var = getVariance(s);
	float sdv = sqrt(var);
	
	return sdv;
}
