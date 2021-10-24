#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc,char *argv[])
{
    char* inputFile;
    char* outputFile;
    char* queryFile;
    int k;
    int L;
    int numberOfNN;
    int rad;
    int numOfLines = 0;
    int numOfElements;
    char* pch;
    ssize_t read;
    char* line;
    ssize_t len = 0;  
    FILE* inputFilePtr;
    FILE* queryFilePtr;
    FILE* outputFilePtr;

    if(argc != 15){
        printf("Not enough arguments\n");
        exit(1);
    }

    printf("Damiane gamiesai\n");
    
    //–i <input file>
    if(strcmp(argv[1], "-i") == 0){
        // the next argument should be the dataset path
        if( access( argv[2], F_OK ) == 0 ) {
            // file exists
            printf("File exists\n");
        } else {
            // file doesn't exist
            printf("File: %s does not exist\n", argv[2]);
            exit(1);
        }
        //–q <query file>
        inputFile = argv[2];
        if(strcmp(argv[3], "-q") == 0){
            if( access( argv[4], F_OK ) == 0 ) {
                // file exists
                printf("File exists\n");
            } else {
                // file doesn't exist
                printf("File: %s does not exist\n", argv[4]);
                exit(1);
            }  
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }
        
        queryFile = argv[4];
        //–k <int>
        if(strcmp(argv[5], "-k") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argv[6][counter]!='\0'){
                if(!isdigit(argv[6][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 6);
                exit(1);
            }
            // else int
            k = atoi(argv[6]);
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

        if(strcmp(argv[7], "-L") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argv[8][counter]!='\0'){
                if(!isdigit(argv[8][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 8);
                exit(1);
            }
            // else int
            L = atoi(argv[8]);
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

        // -o outputfile

        if(strcmp(argv[9], "-o") == 0){
            if( access( argv[10], F_OK ) == 0 ) {
                // file exists
                printf("File exists\n");
            } else {
                // file doesn't exist
                printf("File: %s does not exist\n", argv[10]);
                exit(1);
            }  
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

        outputFile = argv[10];
        
        if(strcmp(argv[11], "-N") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argv[12][counter]!='\0'){
                if(!isdigit(argv[12][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 12);
                exit(1);
            }
            // else int
            numberOfNN = atoi(argv[12]);
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

        if(strcmp(argv[13], "-R") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argv[14][counter]!='\0'){
                if(!isdigit(argv[14][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 8);
                exit(1);
            }
            // else int
            rad = atoi(argv[14]);
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

    }else{
        printf("Incorrect arguments\n");
        exit(1);
    }

    /// all good 

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



    exit(1);
}