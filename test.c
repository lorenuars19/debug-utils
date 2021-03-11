#include "debug_utils.h"

int main(void)
{
	int a;
	long b;
	float c;
	double d;
	char   *e = "Hello World";

	a = 2;
	b = 3;
	c = 4;
	d = 5;
	DEBUG(a);
	DEBUG(b);
	DEBUG(c);
	DEBUG(d);
	// DEBUG(e);
}
