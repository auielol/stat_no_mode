#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define bool int
#define TRUE 1
#define FALSE 0

void selection(int sel);

typedef bool Boolean;
typedef struct node *nodePtr;

struct node
{
	int data;
	nodePtr *next;
}NODE;

struct node *head, *tail;

typedef nodePtr Statistician, DataStore;

void doesNotExist();
bool isEmpty();

Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician s, int x);
void removeData(Statistician s, int x);
void getData(Statistician s);
void displayData(Statistician s);

int getLength(Statistician s);
int minimum(Statistician s);
int maximum(Statistician s);
int range(Statistician s, int min, int max);
float getMean(Statistician s);
float getMedian(Statistician s);
float getVariance(Statistician s);
float standardDeviation(Statistician s);
