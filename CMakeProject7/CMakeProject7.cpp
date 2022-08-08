// CMakeProject7.cpp: определяет точку входа для приложения.
//

#include "CMakeProject7.h"
#include <fstream>
#include <stdio.h>
#include <iconv.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
using namespace std;

char* remove_invalid_utf8(char* utf8, size_t len) {
	size_t inbytes_len = len;
	char* inbuf = utf8;

	size_t outbytes_len = len;
	char* result = (char*)calloc(outbytes_len + 1, sizeof(char));
	char* outbuf = result;

	iconv_t cd = iconv_open("UTF-8//IGNORE", "UTF-8");
	if (cd == (iconv_t)-1) {
		perror("iconv_open");
	}
	if (iconv(cd, &inbuf, &inbytes_len, &outbuf, &outbytes_len)) {
		perror("iconv");
	}
	iconv_close(cd);
	return result;
}
int main()
{
	char* utf8 = "some invalid\xFE\xFE\xFF\xFF stuff";
	char* converted = remove_invalid_utf8(utf8, strlen(utf8));
	fstream ss("ss", ios::out);
	if (ss.is_open()) {	
		ss.write(converted,strlen(converted));
		ss.close();
	}	
	cout << "BOBA";
	system("pause");
	return 0;
}
