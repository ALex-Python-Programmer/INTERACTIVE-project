/**
 * This file is the sourse code of the CONVINIENTCALLING project.
 * argv[1]: the executable file name.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<io.h>

#define n "\n"

#define NEA_CHECK(x) if(argc<x) return NOT_ENOUGH_ARGUMENT
#define FNF_CHECK(x) if(access(x,0)==-1) return FILE_NOT_FOUND

#define USER_ERROR 0xC0000000
#define NOT_ENOUGH_ARGUMENT 0xC0000001
#define INVALID_ARGUMENT 0xC0000002
#define FILE_NOT_FOUND 0xC0000003
#define OK 0x00000000
#define NO 0x00000001
#define YES 0x00000002

char target[1024],args[1024];
time_t begin,end;
int main(int argc,char* argv[]) {
	NEA_CHECK(2);
	FNF_CHECK(argv[1]);
	if(strlen(argv[1])<5) return INVALID_ARGUMENT;
	if(tolower(argv[1][strlen(argv[1])-1])!='e'
	 ||tolower(argv[1][strlen(argv[1])-2])!='x'
	 ||tolower(argv[1][strlen(argv[1])-3])!='e'
	 ||argv[1][strlen(argv[1])-4]!='.') return INVALID_ARGUMENT;
	printf("Please input arguments(split by space):");
	gets(args);
	strcat(target,argv[1]);
	strcat(args,target);
	printf("Program starts now:\n");
	time(&begin);
	int ret=system(target);
	time(&end);
	printf("\nProcess exited after %d seconds with return value %d\n",end-begin,ret);
	system("pause");
	return OK;
}
