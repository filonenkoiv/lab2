#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

extern void help_me();

extern void  info_environ(char *opt);

extern void set_environ(int flag, char *arg1, char *arg2);

extern void delete_environ(char *opt);

extern void printenv();

extern void clear_environ();

extern void set_new(int a, int v, char *opt1, char *opt2);

int main(int argc, char *argv[]){
	int flag = 0;
	int a = 0;
	int v = 0;
	if(argc == 1) { 
		printenv();	
		return 0;
	}

	if (argc < 4){
		flag = 1;
	}
	const char *short_options = "hi:s:a:v:d:c";

	const struct option long_options[] = {
		{"help", 0, NULL, 'h'},
		{"info", 1, NULL, 'i'},
		{"set", 1, NULL, 's'},
		{"assign", 1, NULL, 'a'},
		{"value", 1, NULL, 'v'},
		{"del", 1, NULL, 'd'},
		{"clear", 0, NULL, 'c'},
		{NULL, 0, NULL, 0}
	};

	int res;
	int option_index;
	
	char *opt1, *opt2;

	while ((res = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1){
		switch(res){
			case 'h': 
				help_me();			
				break;

			case 'i':				
				info_environ(optarg);	
				break;

			case 's':
				set_environ(flag, argv[2], argv[3]);
				break;

			case 'a':
				a = 1;
				opt1 = optarg;
				break;
			case 'v':
				v = 1;
				opt2 = optarg;
				break;
			case 'd':
				delete_environ(optarg);
        			printenv();             
				break;

			case 'c':
				clear_environ();
				printenv();
				break;

			case '?': default: {
				printf("Неизвестная команда...\n");				
				break;
			};			
		}
	}
	set_new(a, v, opt1, opt2);
	return 0;
}
