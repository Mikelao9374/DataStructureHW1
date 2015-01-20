#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char Result[50];

void CheckFirstNumber( char String[] )
{
    int Counter;

    for( Counter = 0 ; Counter < strlen( String ) ; Counter++ )
    {
        if( String[ Counter ] < '0' && String[ Counter ] > '9' )
        {
            printf( "Error! Wrong input of first number!\n");
            exit(1);
        }
    }
}

void CheckOperator( char String[] )
{
    int Counter;

    for( Counter = 0 ; Counter < strlen( String ) ; Counter++ )
    {
        if( Counter != 0 )
        {
            printf( "Error! Wrong input of operator!\n");
            exit(1);
        }
    }
}

void CheckSecondNumber( char String[] )
{
    int Counter;

    for( Counter = 0 ; Counter < strlen( String ) ; Counter++ )
    {
        if( String[ Counter ] < '0' && String[ Counter ] > '9' )
        {
            printf( "Error! Wrong input of second number!\n");
            exit(1);
        }
    }
}

void Exchange( char String[] )
{
    int Counter;
    char Storage;

    for ( Counter = 0 ; Counter < ( strlen( String ) / 2 ) ; Counter++ )
    {
        Storage = String[ Counter ];
        String[ Counter ] = String[ strlen( String ) - 1 - Counter ];
        String[ strlen( String ) - 1 - Counter ] = Storage;
    }
}

void Plus( char String1[] , char String2[] , char Result[])
{
    int Counter , Maxlen , Minlen , CalCounter = 0;

    if( strlen( String1 ) > strlen( String2 ) )
    {
        Maxlen = strlen( String1 );
        Minlen = strlen( String2 );

        for( Counter = 0 ; Counter < Minlen  ; Counter++ )
        {
            if( String1[ Counter ] + String2[ Counter ] + CalCounter - '0' > 9 )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0' - 10;
                CalCounter = 1;
            }
            else if( String1[ Counter ] + String2[ Counter ] + CalCounter - '0' < 10 )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0';
                CalCounter = 0;
            }
        }

        for ( Counter = Minlen ; Counter < Maxlen  ; Counter++ )
        {
            Result[ Counter ] = String1[ Counter ] + CalCounter;
            CalCounter = 0;
        }
    }
    else if( strlen( String2 ) > strlen( String1 ) )
    {
        Maxlen = strlen( String2 );
        Minlen = strlen( String1 );

        for( Counter = 0 ; Counter < Minlen ; Counter++ )
        {
            if( ( int )String1[ Counter ] + ( int )String2[ Counter ] + CalCounter - '0' > '9' )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0' - 10;
                CalCounter = 1;
            }
            else if( ( int )String1[ Counter ] + ( int )String2[ Counter ] + CalCounter - '0' <= '9' )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0';
                CalCounter = 0;
            }
        }

        for ( Counter = Minlen - 1 ; Counter < Maxlen ; Counter++ )
        {
            Result[ Counter ] = String2[ Counter ] + CalCounter;
            CalCounter = 0;
        }
    }
    else
    {
        Maxlen = strlen( String1 );

        for( Counter = 0 ; Counter < Maxlen ; Counter++ )
        {
            if( ( int )String1[ Counter ] + ( int )String2[ Counter ] + CalCounter - '0' > '9' )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0' - 10;
                CalCounter = 1;
            }
            else if( ( int )String1[ Counter ] + ( int )String2[ Counter ] + CalCounter - '0' <= '9' )
            {
                Result[ Counter ] = String1[ Counter ] + String2[ Counter ] - '0';
                CalCounter = 0;
            }
        }
    }
}

void Mutiply( char String1[] , char String2[] , char Result[] )
{
    int Counter1 , Counter2 , CalCounter = 0;

    for( Counter1 = 0 ; Counter1 < strlen( String1 )  ; Counter1++ )
    {
        for( Counter2 = 0 ; Counter2 < strlen( String2 )  ; Counter2++ )
        {
            if( Result[ Counter1 + Counter2 ] == '\0' )
            {
                Result[ Counter1 + Counter2 ] = '0';
            }

            if ( Result[ Counter1 + Counter2 ] + CalCounter + ( String1[ Counter1 ] - '0' ) * ( String2[ Counter2 ] - '0' ) % 10 > '9' )
            {
                Result[ Counter2 ] = Result[ Counter2 ] + CalCounter + ( String1[ Counter1 ] - '0' ) * ( String2[ Counter2 ] - '0' ) % 10 - 10;
                CalCounter = ( ( String1[ Counter1 ] - '0' ) * ( String2[ Counter2 ] - '0' ) / 10 ) + 1;
            }
            else
            {
                Result[ Counter2 ] = Result[ Counter2 ] + CalCounter + ( String1[ Counter1 ] - '0' ) * ( String2[ Counter2 ] - '0' ) % 10;
                CalCounter = ( String1[ Counter1 ] - '0' ) * ( String2[ Counter2 ] - '0' ) / 10;
            }
        }
        if( CalCounter != 0 )
        {
            if( Result[ Counter2 ] == '\0' )
            {
                Result[ Counter2 ] = '0';
            }
            Result[ Counter2 ] = Result[ Counter2 ] + CalCounter;
            CalCounter = 0;
        }
    }

    Exchange( Result );
}

int main( void )
{
    char InputStorage[50] , *Input , Input1[50] , Input2[50] , Operator[50] , Result[50];
    memset( Input1 , '\0' , 50 );
    memset( Input2 , '\0' , 50 );
    memset( Operator , '\0' , 50 );
    memset( Result , '\0' , 50 );

    fgets( InputStorage , 50 , stdin );

    Input = strtok( InputStorage , " \n" );
    strcpy( Input1 , Input );
    Input = strtok( NULL , " \n" );
    strcpy( Operator , Input );
    Input = strtok( NULL , " \n" );
    strcpy( Input2 , Input );

    CheckFirstNumber( Input1 );
    CheckOperator( Operator );
    CheckSecondNumber( Input2 );

    Exchange( Input1 );
    Exchange( Input2 );

    switch( (int)*Operator )
    {
        case '+':
            Plus( Input1 , Input2 , Result );
            printf( "Answer is: %s\n" , Result );
            exit(0);
            break;
        case '*':
            Mutiply( Input1 , Input2 , Result );
            printf( "Answer is: %s\n" , Result );
            exit(0);
            break;
        default:
            printf( "Error! Wrong input of operator!\n" );
            exit(1);
            break;
    }
}
