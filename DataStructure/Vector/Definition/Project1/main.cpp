#include<iostream>
#include<string.h>

int main() {
	char str[80] = "Hoc C - co ban va nang cao - tai VietJack";
	const char s[2] = "-";
	char *token;

	/* lay token dau tien */
	token = strtok_s(str, s);

	/* duyet qua cac token con lai */
	while (token != NULL)
	{
		printf(" %s\n", token);

		token = strtok_s(NULL, s);
	}

	system("pause");
	return 0;
}