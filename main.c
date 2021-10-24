#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc,char *argv[])
{
    char* input_path;
    char* output_path;
    char* query_path;
    int k;
    int L;
    int number_of_nearest;
    int radius;

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
        input_path = argv[2];
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
        
        query_path = argv[4];
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

        output_path = argv[10];
        
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
            number_of_nearest = atoi(argv[12]);
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
            radius = atoi(argv[14]);
        }else{
            printf("Incorrect arguments\n");
            exit(1);
        }

    }else{
        printf("Incorrect arguments\n");
        exit(1);
    }
    
    exit(1);
}