#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#define IS_FILE 0
#define IS_DIR 1
#include <sys/stat.h>
#define NULL 0

int isDir(char* path){
    struct stat s;
    if(stat(path, &s) == 0){
        if(s.st_mode & S_IFDIR) return IS_DIR;
        else return -1;
    }
}


int main(int argc, char **argv) {
    char regex[] = {0};
    char filename[] = {0};
    int USES_REGEX = 0;
    struct dirent *directory_entity;
    char* base_dir = "C:\\Books\\";
    DIR* dir = opendir(base_dir);

    if(dir == NULL){
        printf("Error opening bas directory: C:\\");
        exit(-1);
    } else{
        printf("$> C:\\ opened for access\n");
    }


    switch (argc){
        case 1:
            printf("$> Correct Usages are\n: app.exe --regex <filename>\n\n: app.exe <filename>");
            exit(-1);
        case 2:
            strcpy(filename, argv[1]);
            printf("$> Target file: %s\n", filename);
            break;
        case 3:
            strcpy(regex, argv[2]);
            //printf("Regex: %s", regex);
            USES_REGEX = 1;
            break;

        default:
            printf("$> Invalid arguments length");

    }

    //If target is an actual filename
    if(!USES_REGEX){
        while((directory_entity = readdir(dir)) != NULL){
            printf("\n%s", strcat(base_dir, directory_entity->d_name));
            //printf("\n%s    >>>   %d", strcat(base_dir,directory_entity->d_name), isDir(strcat(base_dir, directory_entity->d_name)));
        }
    }
    return 0;
}