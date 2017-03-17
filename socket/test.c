#include <stdio.h>
#include <string.h>
void myfor(char *arr) {
	while (*arr) {
		printf("---%c\n",*arr);
		arr++;
	}

}
int main() {

	char tmp[] = "hell0";
	int a = 1;
	char tmp2[5] = "world";
	//strcpy(tmp,tmp2);
	int i = 0;
/*
	for (tmp;tmp[i] != '\0';i++)
		printf("-%c\n",tmp[i]);
*/
	myfor(tmp);
	printf("--------------\n");
	printf("%c\n",tmp[5]);
	//printf("%s\n",tmp); 
	return 1;
}
