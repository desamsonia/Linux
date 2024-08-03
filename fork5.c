#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char *argv[] ) {
    char *array;
    array = malloc( 20 );
    strcpy( array, "Hello" );
    switch( fork() ) {
    case 0:
        printf( "Child array: %s\n", array );
        strcpy( array, "Goodbye" );
        printf( "Child array: %s\n", array );
        free( array );
        break;
    case -1:
        printf( "Error with fork()\n" );
        break;
    default:
        printf( "Parent array: %s\n", array );
        sleep(1);
        printf( "Parent array: %s\n", array );
        free( array );
    }
    return 0;
}
