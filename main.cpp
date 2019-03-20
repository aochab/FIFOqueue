#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "FIFO.h"

using namespace std;

int main()
{
	srand( (unsigned)time( NULL ) );

	QueueFIFO* q = (QueueFIFO*)calloc( 1, sizeof( QueueFIFO ) );
	if( !QFCreate( q ) )
	{
		printf( "ERROR! QFCreate\n" );
		return 0;
	}

	for( int i = 0; i < 20; i++ )
		QFEnqueue( q, rand() % 50 + 1 );

	QFEnqueue( q, 20 );
	QFEnqueue( q, 500 );
	QFEnqueue( q, 3 );

	for( int i = 0; i < 23; i++ )
		printf( "Nr %d, value: %d\n", i + 1, QFDequeue( q ) );

	free( q );
	q = NULL;
	return 0;
}

