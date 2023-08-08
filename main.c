#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "functions.h"
#define IS_FILE 0
#define IS_DIR 1
#include <sys/stat.h>
#define NULL 0

void searchDir(char* directory, char* filename){
    struct dirent *directory_entity;

    DIR* dir = opendir(directory);

    if(dir == NULL){
        printf("Error opening directory: %s", directory);
        exit(-1);
    } else{
        //printf("$> %s opened for access\n", directory);
    }



    while((directory_entity = readdir(dir)) != NULL){
        char temp_filename[2056];
        strcpy(temp_filename, directory);
        strcat(temp_filename, "\\");
        if(strcmp(directory_entity->d_name, "..") == 0) continue;
        if(strcmp(directory_entity->d_name, ".") == 0) continue;

        strcat(temp_filename, directory_entity->d_name);
        if(isDir(temp_filename) == 1) {

            //Recursively print search sub directories
            searchDir(temp_filename, filename);
        }

        else {
            //At this point we have a working file as temp_name
            //So we perform the string comparisons to check if the given file is what we are after
            char *_temp_filename = directory_entity->d_name;
            strlwr(_temp_filename);
            if (strcmp(filename, _temp_filename) == 0){
                printf("%s found at: \t\t %s", filename,directory);
            }
        };

    }
}


int isDir(char* path){
    struct stat s;
    if(stat(path, &s) == 0){
        if(s.st_mode & S_IFDIR) return IS_DIR;
        else return -1;
    }
}


int main(int argc, char **argv) {
    char filename[] = {0};
    struct dirent *directory_entity;



    switch (argc){
        case 1:
            printf("$> Correct Usage is \n: app.exe <filename>");
            exit(-1);
        case 2:
            strcpy(filename, (strlwr(argv[1])));
            printf("$> Target file: %s\n", filename);
            break;

        default:
            printf("$> Invalid arguments length");

    }

       searchDir("C:\\Books", filename);
    return 0;
}