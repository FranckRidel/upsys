#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	char install[50] = "", upOS[40] = "", cleanOS[70] = "";
	char installDeb[43] = "sudo apt-get update && sudo apt-get upgrade";
	char upOSDeb[29] = " && sudo apt-get dist-upgrade";
	char installFed[15] = "sudo dnf update";
	char upOSFed[35] = " && sudo dnf install fedora-upgrade";
	char cleanOSDeb[66] = "sudo apt-get autoremove && sudo apt-get autoclean && sudo updatedb";
;
	char cleanOSFed[58] = "sudo dnf autoremove && sudo dnf clean all && sudo updatedb";
	int os = 0, choice = 0; 

	system("clear");
	
	do{
		printf("What kind of O.S. to upgrade ?\n1) Debian\n2) Fedora\n");
		scanf("%d", &os);
	} while (os < 1 || os > 2);

	switch(os){
		case 1: strcpy(install, installDeb);
			strcpy(upOS, upOSDeb);
			break;
		case 2: strcpy(install, installFed);
			strcpy(upOS, upOSFed);
			break; 
		default: printf("An error has occurred\n");
		exit(0);
	}


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

	system(cleanOS);

	printf("\n\nSystem cleaned.\n See you soon !\n\n");

	return 0;
}
