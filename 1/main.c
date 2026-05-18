#include<stdio.h>
#include<cstdlib>
int main(int argc, char* argv[]) {
	printf("Привет, ");
	if (argv[1])
	{
		printf("%s",argv[1]);
	} else {
		printf("%s", getenv("USER"));
	}
	printf("\n");
}