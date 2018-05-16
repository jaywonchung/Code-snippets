#define what_is(x) cerr<<#x<<" is "<<x<<endl;

#include <iostream>
using namespace std;

int main()
{
	int var = 1324;
	what_is(var);
	
	return 0;
}