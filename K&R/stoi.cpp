#include <iostream>
#include <string.h>
using namespace std;

/**
 *	将字符串转为 int-数字
 */
 int stoi(string str)
 {
	char buf[64];
	if (str.length() <= 64) 
	{
		strcpy(buf, str.c_str());
	} else {
		return 0; /*	溢出	*/
	}

	return atoi(buf);
 }