#include <iostream>

using namespace std;

struct S {
	int x;
	S( int n ) { x = n; printf( " Cons " ); }
	S( const S & a ) { x = a.x; printf( " Copy " ); }
	~S( ) { printf( "Des " ); }
};

S & f( S y , S & z) {
	y = S (3);
	return z;
}

int main ( ) {
	S s(1);
	f( s, s );
	printf( "%d ", s.x );
	return 0;
}
