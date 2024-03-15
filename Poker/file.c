// CSCN71030, Group 2
// Ryan Massey, Ryan Witley, Henil Jariwala
// Testing File I/O
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "file.h"

bool file()
{
	FILE* file = fopen("test.txt", "w");
	if (file == NULL)
		printf("The file doesn't exist");
		return false;

	fprintf(file, "Testing for File I/O\n");
	fclose(file);
	return true;
}