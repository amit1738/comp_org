#include <stdio.h>

int main()
{
    char* filename = "test.txt";

    // open the file for writing
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return -1;
    }d

    // close the file
    fclose(fp);

    return 0;
}


//lets initialize the project
int initalize()
{
    char* 
	return 0;
}