// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>
#include <lcom/liblm.h>
#include <lcom/proj.h>

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"


// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
	// sets the language of LCF messages (can be either EN-US or PT-PT)
	lcf_set_language("EN-US");

	// enables to log function invocations that are being "wrapped" by LCF
	// [comment this out if you don't want/need it]
	lcf_trace_calls("/home/lcom/labs/proj/trace.txt");

	// enables to save the output of printf function calls on a file
	// [comment this out if you don't want/need it]
	lcf_log_output("/home/lcom/labs/proj/output.txt");

	// handles control over to LCF
	// [LCF handles command line arguments and invokes the right function]
	if (lcf_start(argc, argv))
		return 1;

	// LCF clean up tasks
	// [must be the last statement before return]
	lcf_cleanup();

	return 0;
}

static int print_usage() {
	printf("Usage: <single/player1/player2>\n");

	return 1;
}

int(proj_main_loop)(int argc, char *argv[]) {



	if (argc < 1)
		return print_usage();


	if(strcmp(argv[0],"single") == 0){
		if(game_loop(MODE)){
			return 1;
		}
	}
	else if(strcmp(argv[0],"player1") == 0){
		if(game_loop_multi(MODE, 1)){
			return 1;
		}
	}
	else if(strcmp(argv[0],"player2") == 0){
		if(game_loop_multi(MODE, 2)){
			return 1;
		}
	}else{
		return print_usage();
	}


	return 0;
}

