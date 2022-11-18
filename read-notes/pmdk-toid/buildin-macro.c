#include <stdio.h>
#define X(express) __builtin_choose_expr((express), 1, 0)

int main()
{
	/* Output:
	 * X(1): 1 X(0 == 1):0
	*/
	printf("X(1): %d X(0 == 1):%d\n", X(1), X(0 == 1));
	return 0;
}
