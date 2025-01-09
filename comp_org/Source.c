#include <stdio.h>

int initialize();
char fetch(int lineNumber);

int main()
{
	initialize();
	char line = fetch(5);
	printf("%c", line);
    return 0;
}


char fetch(int lineNumber)
{
    
    int current_line = 1;
    //fetch the instruction from the memory
    FILE* fetchP = fopen("imemin.txt", "r");
    
    char line[256];
    
    
    if (fetchP == NULL)
    {
        printf("Error opening file: \n");
    }
    else
    {
        
        // Loop through the file line by line
        while (fgets(line, sizeof(line), fetchP))
        {
            if (current_line == lineNumber) 
            {
                fclose(fetchP);
                printf("%c", line);
                return line;
            }
            current_line++;
        }
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