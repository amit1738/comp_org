#include <stdio.h>

int main()
{
	initalize();
    return 0;
}


//lets initialize the project
int initalize()
{
	///pointers to the files
    FILE* dmemout = fopen("dmemout.txt", "w");
    FILE* regout = fopen("regout.txt", "w");
    FILE* trace = fopen("trace.txt", "w");
    FILE* hwregtrace = fopen("hwregtrace.txt", "w");
    FILE* cycles = fopen("cycles.txt", "w");
    FILE* leds = fopen("leds.txt", "w");
    FILE* display7seg = fopen("display7seg.txt", "w");

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
