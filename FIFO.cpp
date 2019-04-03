#include "stdafx.h"
#include <stdlib.h>
#include "FIFO.h"

//----------------------------------------------------------------------
int QFCreate( QueueFIFO* q )
{
	if( !q )
	{
		printf( "ERROR! QFCreate\n" );
		return 0;
	}
	q->pHead = q->pTail = NULL;
	return 1;
}

//----------------------------------------------------------------------
int QFEmpty( QueueFIFO* q )
{
	return !(q->pHead); //return 1 if queue is empty
}

//----------------------------------------------------------------------
void QFEnqueue( QueueFIFO* q, int x )
{
	QFIFOItem* p = (QFIFOItem*)calloc( 1, sizeof( QFIFOItem ) ); //create new item
	if( !p )
	{
		printf( "ERROR! QFEnqueue - no memory for new item\n" );
		return;
	}
	p->n_Key = x;			//insert value										
	if( !QFEmpty(q) )
		q->pTail->pNext = p;	//Add to queue
	else
		q->pHead = p;		//If the queue is empty, add to the beginning
	
	q->pTail = p;			//New item is a tail
}

//----------------------------------------------------------------------
int QFDequeue( QueueFIFO* q )
{
	if( !QFEmpty( q ) )
	{
		int x = q->pHead->n_Key; 
		QFDel( q );				
		return x; //return the value of the deleted item
	}
	printf( "QFDequeue - queue is empty!\n" );
	return 0;
}

//----------------------------------------------------------------------
void QFClear( QueueFIFO* q )
{
	while( !QFEmpty( q ) ) //Delete all items
		QFDel( q );
}

//----------------------------------------------------------------------
void QFRemove( QueueFIFO* q )
{
	QFClear( q );
}

//----------------------------------------------------------------------
void QFDel( QueueFIFO* q )
{
	if( !QFEmpty( q ) )
	{
		QFIFOItem* p = q->pHead;	//Save first item
						
	    q->pHead = p->pNext;		//New first element
		if(!q->pHead )
			q->pTail = NULL;
		
		free( p );			//Delete item from memory
	}
	else
	{
		printf( "QFDel - queue is empty!" );
		return;
	}
}

//----------------------------------------------------------------------
