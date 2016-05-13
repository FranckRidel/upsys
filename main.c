#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	char install[43] = "sudo apt-get update && sudo apt-get upgrade";
	char upOS[29] = " && sudo apt-get dist-upgrade";
	int choice = 0; 

	system("clear");

	printf("Hi %s ! What kind of update ?\n1) Programs only\n2) Programs + system\n", getenv("USER"));
	scanf("%d", &choice);
	
	switch (choice){
		case 1: printf("\n\nPrograms will be upgraded\n\n");
				break;
		case 2:	strcat(install, upOS);
				printf("\n\nPrograms and system will be upgraded\n\n");
				break;
		default: printf("Wrong choice. Stop script\n");
				exit(0);
				break;
	}

	system(install);
	
	printf("\n\nUpdate OK. Cleaning system...\n\n");

	system("sudo apt-get autoremove && sudo apt-get autoclean && sudo updatedb");

	printf("\n\nSystem cleaned./n See you soon !\n\n");

	return 0;
}
