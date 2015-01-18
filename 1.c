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

char* plus( char integer1[] , char integer2[] )
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

char* mutiply( char integer1[] , char integer2[] )
{
	int count , maxlen , minlen , calcount = 0 , judge;

	if ( strlen( integer1 ) > strlen( integer2 ) )
	{
		maxlen = strlen(integer1);
		minlen = strlen(integer2);
		judge = 1;

		for ( count = minlen - 1 ; count < maxlen - 1 ; count++ )
		{
			integer1[count] = '0';
		}
	}
	else if ( strlen( integer1 ) < strlen( integer2 ) )
	{
		maxlen = strlen(integer2);
		minlen = strlen(integer1);
		judge = 2;

		for ( count = minlen - 1 ; count < maxlen - 1 ; count++ )
		{
			integer2[count] = '0';
		}
	}

	char result2[50];
	memset( result2 , '\0' , sizeof( result2 ) );

	for( count = 0 ; count < minlen ; count++ )
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
	char input[50] , input1[50] , input2[50];
	char operator;
    int count;

    memset(input , '\0' ,50);
    memset(input1 , '\0' ,50);
    memset(input2 , '\0' ,50);

    fgets( input , 50 , stdin );

    for( count = 0 ; input[count] != ' ' ; count++ )
    {
        input1[count] = input[count];
    }

    count++;

    operator = input[count];

    count += 2;

    for( count ; input[count] != ' ' && input[count] != '\0' ; count++ )
    {
        input1[count] = input[count];
    }

	exchange(input1);
	exchange(input2);

	switch( (int)operator )
	{
		case 43:
			printf( "Answer: %s\n", *plus( input1 , input2 ) );
			break;
		case 45:
			printf( "Answer: %s\n", *mutiply( input1 , input2 ) );
			break;
		default:
			printf( "Wrong operator!\n" );
			break;
	}

	return 0;
}
