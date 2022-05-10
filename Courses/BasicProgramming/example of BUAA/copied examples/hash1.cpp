#include <stdio.h>
 
unsigned int bkdr_hash(const char* key)
{
	char* str = const_cast<char*>(key);
			
	unsigned int seed = 31;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return hash;
}
 
int main()
{
	printf("%d\n",bkdr_hash("hijklmn"));
	printf("%d\n",bkdr_hash("hijklmn"));
	return 0;
}


