#include <stdio.h>

int initialize();
char fetch(int lineNumber);

int main()
{
	initialize();
	fetch(1);
    return 0;
}


char fetch(int lineNumber)
{
    //fetch the instruction from the memory
    FILE* fetchP = fopen("imemin.txt", "r");
    char line[256];
    if (fetchP != NULL)
    {
        int line_length = 32; // Fixed length of each line (including newline)

        // Calculate byte offset and seek
        long offset = (lineNumber - 1) * line_length; // Offset for the target line
        fseek(fetchP, offset, SEEK_SET);

        // Read the target line
        if (fgets(line, sizeof(line), fetchP) != NULL)
        {
            printf("Line %d: %s", lineNumber, line);
        }
        else {
            printf("Error: Could not fetch line %d.\n", lineNumber);
    }
	}
	else {
		printf("Error: Could not open file.\n");
	}
    fclose(fetchP);
    	return 0;

}

//lets initialize the project
int initialize()
{
	///pointers to the files
    FILE* dmemout = fopen("dmemout.txt", "w");
    FILE* regout = fopen("regout.txt", "w");
    FILE* trace = fopen("trace.txt", "w");
    FILE* hwregtrace = fopen("hwregtrace.txt", "w");
    FILE* cycles = fopen("cycles.txt", "w");
    FILE* leds = fopen("leds.txt", "w");
    FILE* display7seg = fopen("display7seg.txt", "w");

    //inilize zeros in regs
    int i= 0;
    unsigned char zero = 0x0;
    for (i = 0; i < 12; i++)
    {
        fprintf(regout,"%x\n",zero);
    }
    //clsoe the files
    fclose(dmemout);
    fclose(regout);
    fclose(hwregtrace);
    fclose(trace);
    fclose(cycles);
    fclose(leds);
    fclose(display7seg);

	return 0;
}