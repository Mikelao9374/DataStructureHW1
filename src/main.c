#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "operators.h"

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
