#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void exchange( char string[] )
{
	int count,length;
	char storage;
	length = strlen( string );

	for( count = 0 ; count < ( length - 1 ) / 2 ; count++ )
	{
		storage = string[count];
		string[ count ] = string[ length - 1 - count];
		string[ length - 1 - count ] = storage;
	}	
}

char plus( char integer1[] , char integer2[] )
{
	int count , maxlen , minlen , calcount = 0;

	if ( strlen( integer1 ) > strlen( integer2 ) )
	{
		maxlen = strlen( integer1 );
		minlen = strlen( integer2 );
		
		for ( count = minlen - 1 ; count < maxlen - 1 ; count++ )
		{
			integer2[count] = '0';
		}
	}
	else if ( strlen( integer2 ) > strlen( integer2 ) )
	{
		maxlen = strlen( integer2 );
		minlen = strlen( integer1 );		
		
		for ( count = minlen - 1 ; count < maxlen - 1 ; count++ )
		{
			integer1[count] = '0';
		}
	}

	char result1[50];
	memset( result1 , '\0' , sizeof( result1 ) );

	for (count = 0 ; count < maxlen ; count++ )
	{
		if( (int)integer1[count] + (int)integer2[count] + calcount - 48 * 2 > 9 )
		{
			result1[count] = integer1[count] + integer2[count] + calcount - 48 - 10;
			calcount = 1;
		}
		else if ( (int)integer1[count] + (int)integer2[count] + calcount - 48 * 2 < 10 )
		{
			result1[count] = integer1[count] + integer2[count] + calcount - 48;
			calcount = 0;
		}
	}

	exchange( result1 );
	return *result1;
}

char mutiply( char integer1[] , char integer2[] )
{
	int count,minlen,maxlen,calcount = 0,judge;

	if ( strlen( integer1 ) < strlen( integer2 ) )
	{
		minlen = strlen(integer1);
		maxlen = strlen(integer2);
		judge = 2;
	}
	else if ( strlen( integer2 ) < strlen( integer1 ) )
	{
		minlen = strlen(integer2);
		maxlen = strlen(integer1);
		judge = 1;
	}

	char result2[50];
	memset( result2 , '\0' , sizeof( result2 ) );

	for( count = 1 ; count < minlen ; count++ )
	{
		result2[count] = ( (int)integer1[count] * (int)integer2[count] + calcount ) % 10;
		calcount = ( (int)integer1[count] * (int)integer2[count]  ) / 10;
	}

	if( judge = 1 )
	{
		for( count ; count < maxlen ; count++)
		{
			result2[count] = (int)integer1[count] + calcount;
			calcount = 0;
		}
	}
	else if( judge = 2 )
	{
		for( count ; count < maxlen ; count++)
		{
			result2[count] = (int)integer2[count] + calcount;
			calcount = 0;
		}
	}

	exchange( result2 );
	return *result2;
}
int main( void )
{
	char input1[50],input2[50];
	char operator;

	scanf( "%s" , input1 );
	getc(stdin);
	scanf( "%c" , &operator );
	getc(stdin);
	scanf( "%s" , input2 );

	exchange(input1);
	exchange(input2);

	printf("input1: %s" , input1 );
	printf("operator: %c" , operator );
	printf("input2: %s" , input2 );

	switch( (int)operator )
	{
		case 43:
			printf( "Answer: %s\n", plus( input1 , input2 ) );
			break;
		case 45:
			printf( "Answer: %s\n", mutiply( input1 , input2 ) );
			break;
		default:
			printf( "Wrong operator!\n" );
			break;
	}

	return 0;
}
