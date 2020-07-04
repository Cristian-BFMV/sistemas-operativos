#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PATH_MAX 4096
char *getUserName();
int rushPath(char cwd[PATH_MAX], int n, char prop[7], char param[PATH_MAX]);
void structTree(int n);
void printFile(char prop[7], char param[PATH_MAX], char absolutePath[PATH_MAX], char file[PATH_MAX], int n);

int main(int argc, char *argv[])
{
    char prop[7];
    char cwd[PATH_MAX];
    char file[PATH_MAX];
    char *ch;

    for (int i = 1; i < argc; i++)
    {
        if (strstr(argv[i], "--name") != NULL)
        {            
            ch = strtok(argv[i], "=");
            for (int i = 0; ch != NULL; i++) {
                if(i == 0)
                {
                    strcpy(prop, ch);
                } else 
                {
                    strcpy(file, ch);
                }
                ch = strtok(NULL, "");
            }
        }
        else
        {
            strcpy(cwd, argv[i]);
        }
    }

    if (strcmp(cwd, "") == 0)
    {
        getcwd(cwd, sizeof(cwd));
    }

    rushPath(cwd, 0, prop, file);

    return 0;
}

int rushPath(char cwd[PATH_MAX], int n, char prop[7], char param[PATH_MAX])
{
    DIR *myDir;
    struct stat myStat;
    struct dirent *myFile;
    char myFilePath[PATH_MAX];

    myDir = opendir(cwd);
    if (myDir == NULL)
    {
        printf("Can't open the directory '%s'\n", cwd);
        return 1;
    }
    while ((myFile = readdir(myDir)) != NULL)
    {
        sprintf(myFilePath, "%s/%s", cwd, myFile->d_name);
        stat(myFilePath, &myStat); 
        printFile(prop, param, myFilePath, myFile->d_name, n);
        if (S_ISDIR(myStat.st_mode) && !(strcmp(myFile->d_name, ".") == 0 || strcmp(myFile->d_name, "..") == 0))
        {
            rushPath(myFilePath, n + 1, prop, param);
        }
    }
    closedir(myDir);
    return 0;
}

void structTree(int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("\t");
    }
}

void printFile(char prop[7], char param[PATH_MAX], char absolutePath[PATH_MAX], char file[PATH_MAX], int n)
{
    if(strcmp(prop, "--name") == 0)
    {
        if(strcmp(file, param) == 0)
        {                
            printf("%s\n", absolutePath);
        }
    } else 
    {
        structTree(n);
        printf("/ %s\n", file);
    }
}