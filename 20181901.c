#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void count(FILE *f, int *line_num, int *word_num, int * char_num);

int main(int argc, char*argv[])
{
	FILE *fr = NULL;
	FILE *fw = NULL;

	int line_num = 0, word_num = 0, char_num = 0;

	if (argc == 1)
		exit(1);

	fr = fopen(argv[1], "r");

	if (fr == NULL)
	{
		printf("읽을 파일이 열리지 않습니다.\n");
		exit(1);
	}

	char string[MAX];
	char ch;
	unsigned int i;

	while (1)
	{
		if (feof(fr) != 0)
			break;

		fgets(string, MAX, fr);

		for (i = 0; i < strlen(string); i++)
		{
			ch = string[i];

			if ((ch == ' ') || (ch == 39)) //띄어쓰기, '로 구분
				word_num++;

			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) //알파벳만을 문자로 취급
				char_num++;
		}
		line_num++;
	}

	fclose(fr);

	printf("<Count Result>\n");
	printf("Line count:			%d\n", line_num);
	printf("Word count:			%d\n", word_num);
	printf("Character count:		%d\n", char_num);

	fw = fopen("OSParadigm.rev", "w");

	if (fw == NULL)
	{
		printf("쓸 파일이 열리지 않습니다.\n");
		exit(1);
	}

	char a;

	fr = fopen(argv[1], "r");

	while ((a = fgetc(fr)) != EOF)
	{
		if (isalpha(a))
		{
			if (islower(a))
				a = toupper(a);
			else if (isupper(a))
				a = tolower(a);
		}
		fputc(a, fw);
	}
	
	fclose(fw);
	fclose(fr);

	printf("File saved in infile.rev\n");

	return 0;
}

void count(FILE*f, int *line_num, int *word_num, int * char_num)
{
	
}

