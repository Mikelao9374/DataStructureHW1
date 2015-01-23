#include <string.h>

#include "operators.h"

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
