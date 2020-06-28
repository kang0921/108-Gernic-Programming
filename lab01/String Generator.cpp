#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

char str[ 500005 ][ 1005 ];

int main(){
    int N, M, length, i, j;

    srand( time( NULL ) );

    cin >> N >> M;
    memset( str, 0, sizeof( char ) * N * M );

    for( i = 0; i < N; i++ ){
        length = rand() % M + 1;

        for( j = 0; j < length; j++ ){
            str[ i ][ j ] = 'A' + rand() % 26;
        }
        cout << str[ i ] << endl;;
        cout << endl;
    }


    return 0;
}
