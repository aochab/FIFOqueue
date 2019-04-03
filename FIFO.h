#ifndef _FIFO_INCLUDE_
#define _FIFO_INCLUDE_

typedef struct tagQFIFOItem
{
	int n_Key;				//value of item
	tagQFIFOItem* pNext;			//pointer on next item
}QFIFOItem;

typedef struct
{
	QFIFOItem* pHead;			//first element
	QFIFOItem* pTail;			//last element
}QueueFIFO;

int QFCreate( QueueFIFO* q );			//qeueue initiating
int QFEmpty( QueueFIFO* q );			//if FIFO empty returned 1 else 0
void QFEnqueue( QueueFIFO* q, int x );		//insert new item at the end
int QFDequeue( QueueFIFO* q );			//take out the first item
void QFClear( QueueFIFO* q );			//clean the queue, set head and tail as NULL
void QFRemove( QueueFIFO* q );			//clears the queue 
void QFDel( QueueFIFO* q );			//remove only first item

#endif
