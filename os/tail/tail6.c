// C++ program to implement your own tail
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Utility function to sleep for n seconds
void sleep(unsigned int n)
{
    clock_t goal = n * 1000 + clock();
    while (goal > clock());
}

// function to read last n lines from the file
// at any point without reading the entire file
void tail(FILE* in, int n)
{
    int count = 0;  // To count '\n' characters

    // unsigned long long pos (stores upto 2^64 – 1
    // chars) assuming that long long int takes 8
    // bytes
    unsigned long long pos;
    char str[2*SIZE];

    // Go to End of file
    if (fseek(in, 0, SEEK_END))
        perror("fseek() failed");
    else
    {
        // pos will contain no. of chars in
        // input file.
        pos = ftell(in);

        // search for '\n' characters
        while (pos)
        {
            // Move 'pos' away from end of file.
            if (!fseek(in, --pos, SEEK_SET))
            {
                if (fgetc(in) == '\n')

                    // stop reading when n newlines
                    // is found
                    if (count++ == n)
                        break;
            }
            else
                perror("fseek() failed");
        }

        // print last n lines
        printf("Printing last %d lines -\n", n);
        while (fgets(str, sizeof(str), in))
            printf("%s", str);
    }
    printf("\n\n");
}

// Creates a file and prints and calls tail() for
// 10 different values of n (from 1 to 10)
int main()
{
    FILE* fp;
    char buffer[SIZE];
    // Open file in binary mode
    // wb+ mode for reading and writing simultaneously
    fp = fopen("a.txt", "wb+");
    if (fp == NULL)
    {
        printf("Error while opening file");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    // Dynamically add lines to input file
    // and call tail() each time
    for (int index = 1; index <= 10; index++)
    {
        /* generate random logs to print in input file*/
        for (int i = 0; i < SIZE - 1; i++)
            buffer[i] = rand() % 26 + 65; // A-Z
        buffer[SIZE] = '\0';

        /* code to print timestamp in logs */
        // get current calendar time
        time_t ltime = time(NULL);

        // asctime() returns a pointer to a string
        // which represents the day and time
        char* date = asctime(localtime(<ime));

        // replace the '\n' character in the date string
        // with '\0' to print on the same line.
        date[strlen(date)-1] = '\0';

        /* Note in text mode '\n' appends two characters,
        so we have opened file in binary mode */
        fprintf(fp, "\nLine #%d [%s] - %s", index,
                                    date, buffer);

        // flush the input stream before calling tail
        fflush(fp);

        // read last index lines from the file
        tail(fp, index);

        // sleep for 3 seconds
        // note difference in timestamps in logs
        sleep(3);
    }

    /* close the file before ending program */
    fclose(fp);

    return 0;
}
