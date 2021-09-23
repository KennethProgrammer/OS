#ifndef shell_h
#define shell_h

#include "vga.h"

int get_argc(char cmd[]){
	int argc = 1;
	for (int i = 0; cmd[i] != 0; i++){
	 if (cmd[i] == ' ' && cmd[i+1] != ' ' && cmd[i+1] != 0){argc++;};
	};
	return argc;
};

void execute_cmd(char cmd[]){
	if (strcmp(cmd, "cls") == 0){
	 clear();
	 print(">");
	 return;
	}

	else if (strcmp(cmd, "exit") == 0){
	 close = 1;
	 return;
	}

	else if (strcmp(cmd, "x86") == 0){
	 print("x86 is a CPU architechture created by Intel in the 1970s. This OS is designed to run on x86 32 bit CPUs.");
	}

	else if (strcmp(cmd, "help") == 0){
	 print("cls: Clear screen\n");
	 print("exit: Stops execution\n");
	 print("info: Gives info about the OS");
	}

	else if (strcmp(cmd, "info") == 0){
	 print("Name of the OS: There is no name for this OS\n");
	 print("x86 OS 32bit\n");
	 print("Contains VGA graphics card driver and a Keyboard driver\n");
	 print("Kernel: Written in the C Programming language\n");
	 print("Bootloader: Written in x86 assembly language\n");
	 print("Coming soon: Multitasking\n");
	 print("To find out more about x86 use command x86");
	}

	else{
	 print("Cmd not found: ");
	 print(cmd);
	};
	print("\n>");
};

#endif
