#ifndef shell_h
#define shell_h

#include "vga.h"

int get_argc(char *cmd){
	int argc = 0;
	if(cmd[0] == ' ' || cmd[0] == 0){argc = 0;}
	else{argc = 1;};

	for (int i = 0; cmd[i] != 0; i++){
	 if (cmd[i] == ' ' && cmd[i+1] != ' ' && cmd[i+1] != 0){argc++;};
	};
	return argc;
};

void execute_cmd(char *cmd){
	if (strcmp(cmd, "cls") == 0){
	 clear();
	 print(">");
	 return;
	}

	else if (strcmp(cmd, "sike") == 0){
	 print("Never going to give you up\n");
	 print("Never going to let you down\n");
	 print("Never gonna run around and desert you\n");
	 print("Never gonna make you cry\n");
	 print("Never gonna say goodbye\n");
	 print("Never gonna tell a lie and hurt you\n");
	 print(">");
	 return;
	}

	else if (strcmp(cmd, "exit") == 0){
	 outw(0x604, 0x2000);
	}

	else if (strcmp(cmd, "help") == 0){
	 print("cls: Clear screen\n");
	 print("exit: Stops execution\n");
	 print("info: Gives info about the OS\n");
	 print("sike: Don't use this command");
	}

	else if (strcmp(cmd, "info") == 0){
	 print("Name of the OS: KCL(Kenneth's Command Line)\n");
	 print("x86 OS 32bit\n");
	 print("Contains VGA graphics card driver and a Keyboard driver\n");
	 print("Kernel: Written in the C Programming language\n");
	 print("Bootloader: Written in x86 assembly language\n");
	 print("Coming soon: Multitasking");
	}

	else{
	 print("Cmd not found: ");
	 print(cmd);
	};
	print("\n>");
};

#endif
