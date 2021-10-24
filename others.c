#include "others.h"

bool checkCommandLineArguments(int argcInt, char* argvArray[]){
    
    int k;
    int L;
    int numberOfNN;
    int rad;
    int numOfLines = 0;
    int numOfElements = 0;
    char* pch;
    ssize_t read;
    char* line;
    ssize_t len = 0; 
    int lineCounter = 0; 
    int elementCounter = 0;
    char* inputFile;
    char* queryFile;
    char* outputFile; // na to doume

    if(argcInt != 15){
        printf("Not enough arguments\n");
        return 1;
    }
    
    //–i <input file>
    if(strcmp(argvArray[1], "-i") == 0){
        // the next argument should be the dataset path
        if( access( argvArray[2], F_OK ) == 0 ) {
            // file exists
            printf("File exists\n");
        } else {
            // file doesn't exist
            printf("File: %s does not exist\n", argvArray[2]);
            return 1;
        }
        //–q <query file>
        //inputFile = argvArray[2];
        if(strcmp(argvArray[3], "-q") == 0){
            if( access( argvArray[4], F_OK ) == 0 ) {
                // file exists
                printf("File exists\n");
            } else {
                // file doesn't exist
                printf("File: %s does not exist\n", argvArray[4]);
                return 1;
            }  
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }
        
        //queryFile = argvArray[4];
        //–k <int>
        if(strcmp(argvArray[5], "-k") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argvArray[6][counter]!='\0'){
                if(!isdigit(argvArray[6][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 6);
                return 1;
            }
            // else int
            //k = atoi(argvArray[6]);
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }

        if(strcmp(argvArray[7], "-L") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argvArray[8][counter]!='\0'){
                if(!isdigit(argvArray[8][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 8);
                return 1;
            }
            // else int
            //L = atoi(argvArray[8]);
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }

        // -o outputfile

        if(strcmp(argvArray[9], "-o") == 0){
            if( access( argvArray[10], F_OK ) == 0 ) {
                // file exists
                printf("File exists\n");
            } else {
                // file doesn't exist
                printf("File: %s does not exist\n", argvArray[10]);
                return 1;
            }  
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }

        //outputFile = argvArray[10];
        
        if(strcmp(argvArray[11], "-N") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argvArray[12][counter]!='\0'){
                if(!isdigit(argvArray[12][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 12);
                return 1;
            }
            // else int
            //numberOfNN = atoi(argvArray[12]);
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }

        if(strcmp(argvArray[13], "-R") == 0){
            // we want integer
            int counter = 0;
            int flag = 0;
            while(argvArray[14][counter]!='\0'){
                if(!isdigit(argvArray[14][counter])){
                    flag = 1;
                    break;
                }
                counter++;
            }
            if(flag){
                // not an int...
                printf("Argument #%d needs to be an int\n", 8);
                return 1;
            }
            // else int
            //rad = atoi(argvArray[14]);
        }else{
            printf("Incorrect arguments\n");
            return 1;
        }

    }else{
        printf("Incorrect arguments\n");
        return 1;
    }
    return 0; //correct command line arguments
}