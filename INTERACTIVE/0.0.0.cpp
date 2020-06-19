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
#define USER_ERROR 0xC0000000
#define NOT_ENOUGH_ARGUMENT 0xC0000001
#define INVALID_ARGUMENT 0xC0000002
#define FILE_NOT_FOUND 0xC0000003
#define OK 0x00000000

char target[1024]="iacache\\";
char version[]="0.0.0";
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
		printf("For more information, press <%s help.>",argv[0]);
		return NOT_ENOUGH_ARGUMENT;
	}
	if(access("iacache",0)==-1) mkdir("iacache");
	if(strcmp(argv[1],"version")==0) {
		printf(version);
		return OK;
	}
	else if(strcmp(argv[1],"help")==0) {
		printf(help);
		return OK;
	}
	else if(strcmp(argv[1],"get")==0) {
		if(argc<6) return NOT_ENOUGH_ARGUMENT;
		strcat(target,argv[2]);
		strcat(target,"#");
		strcat(target,argv[3]);
		strcat(target,"#");
		strcat(target,argv[4]);
		if(access(target,0)==-1) return FILE_NOT_FOUND;
		CopyFile(target,argv[5],0);
		return OK;
	}
	else if(strcmp(argv[1],"set")==0) {
		if(argc<6) return NOT_ENOUGH_ARGUMENT;
		strcat(target,argv[2]);
		strcat(target,"#");
		strcat(target,argv[3]);
		strcat(target,"#");
		strcat(target,argv[4]);
		if(access(argv[5],0)==-1) return FILE_NOT_FOUND;
		CopyFile(argv[5],target,0);
		return OK;
	}
	else if(strcmp(argv[1],"delete")==0) {
		if(argc<5) return NOT_ENOUGH_ARGUMENT;
		strcat(target,argv[2]);
		strcat(target,"#");
		strcat(target,argv[3]);
		strcat(target,"#");
		strcat(target,argv[4]);
		if(access(target,0)!=-1) remove(target);
		return OK;
	}
	else {
		printf("Invalid function: %s",argv[1]);
		return INVALID_ARGUMENT;
	}
}
