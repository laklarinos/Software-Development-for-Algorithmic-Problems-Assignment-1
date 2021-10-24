#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc,char *argv[])
{
    char *inputFile = argv[2];
    char *queryFile = argv[4];
    int k = atoi(argv[6]);
    int l = atoi(argv[8]);
    char *outputFile = argv[10];
    int numOfNN = atoi(argv[12]);
    int rad = atoi(argv[14]);
    int numOfLines = 0;
    int numOfElements = 0;
    char chr;
    size_t len = 0;
    ssize_t read;
    char* line;
    char* pch;

    FILE *inputFilePtr;
    FILE *queryFilePtr;
    FILE *outputFilePtr;
    
    printf("Gamiesai!\n");

    // check if files exist
    if(access( inputFile, F_OK )) {
        printf("File : %s does not exist\n", inputFile);
        exit(1);
    }
    if(access( queryFile, F_OK )) {
        printf("File : %s does not exist\n", queryFile);
        exit(1);
    }
    if(access( outputFile, F_OK )) {
        printf("File : %s does not exist\n", outputFile);
        exit(1);
    }

    printf("to moyni ths manass soy");

    // open the files
    inputFilePtr = fopen(inputFile,"r");
    if( inputFilePtr == 0){
        perror("Problem when opening : ");
    }

    queryFilePtr = fopen(queryFile,"r");
    if( queryFilePtr == 0){
        perror("Problem when opening : ");
    }

    outputFilePtr = fopen(outputFile,"r");
    if( outputFilePtr == 0){
        perror("Problem when opening : ");
    }
    ryr6
    while ((read = getline(&line, &len, inputFilePtr)) != -1) 
    {
        numOfLines++;
        // printf("Retrieved line of length %zu:\n", read);
        // printf(" = %s", line);
        pch = strtok (line," ");
        while (pch != NULL)
        {
            if(*pch != '\r')
            {
                printf ("%s\n",pch);
                numOfElements++;
            } 
            pch = strtok (NULL, " ");

            printf(" element = %d\n",numOfElements);
        }
    }
    //printf("num of Items: %d\n",numOfLines);

    fclose(inputFilePtr);
    fclose(queryFilePtr);
    fclose(outputFilePtr);
}