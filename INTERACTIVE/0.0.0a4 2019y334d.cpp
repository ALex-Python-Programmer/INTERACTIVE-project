/**
 * This file is the sourse code of the INTERACTIVE project.
 * argv[1]: get/set/delete, to assign the operation type to the iacache.
 * argv[2]: the name of the dispatcher.
 * argv[3]: the name of the reciever.
 * argv[4]: the serial number.
 * argv[5]: if argv[1] is not delete, it is to assign the outout/input file name.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>
#include<windows.h>
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

char target[1024];
char version[]="0.0.0a4 2019y334d";
char help[]="INTERACTIVE help document:"n
"    This file is the sourse code of the INTERACTIVE project."n
"    The argument values(argv) stands for:"n
"        argv[1]: get/set/delete, to assign the operation type to the iacache."n
"        argv[2]: the name of the dispatcher."n
"        argv[3]: the name of the reciever."n
"        argv[4]: the serial number."n
"        argv[5]: if argv[1] is not delete, it is to assign the outout/input file name.";

int main(int argc,char* argv[]) {
	if(argc==1) {
		printf("For more information, type <%s help.>",argv[0]);
		return NOT_ENOUGH_ARGUMENT;
	}
	if(access("iacache",0)==-1) mkdir("iacache");
	NEA_CHECK(5);
	sprintf(target,"iacache\\%s#%s#%s",argv[2],argv[3],argv[4]);
	
	if(strcmp(argv[1],"version")==0) {
		printf(version);
		return OK;
	}
	else if(strcmp(argv[1],"help")==0) {
		printf(help);
		return OK;
	}
	else if(strcmp(argv[1],"get")==0) {
		NEA_CHECK(6);
		FNF_CHECK(target);
		CopyFile(target,argv[5],0);
		return OK;
	}
	else if(strcmp(argv[1],"set")==0) {
		NEA_CHECK(6);
		FNF_CHECK(argv[5]);
		CopyFile(argv[5],target,0);
		return OK;
	}
	else if(strcmp(argv[1],"delete")==0) {
		if(access(target,0)!=-1) remove(target);
		return OK;
	}
	else if(strcmp(argv[1],"exist")==0) {
		if(access(target,0)==-1) return YES;
		else return NO;
	}
	else {
		printf("Invalid function: %s",argv[1]);
		return INVALID_ARGUMENT;
	}
}
