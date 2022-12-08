#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


void help_me(){
	printf("Справка по использованию:\nОпция -i <переменная> или --info <переменная> выводит значение указанной переменной.\n");
	printf("Опция -s <переменная=значение> или --set <переменная=значение> присваивает указанной переменной окружения новое значение.\n");
	printf("Опция -a <переменная> или --assign <переменная> и -v <значение> или --value <значение> присваивает указанной переменной окружения новое значение.\n");
	printf("Опция -d или --del <переменная> удаляет указанную переменную из окружения.\n");
	printf("Опция -с или --clear полностью очищает окружение.\n");
}

void  info_environ(char *opt){
	char *env = getenv(opt);
	if (env == NULL){
		printf("Данной переменной в окружении нет...\n");	
	}
	else{
		printf("%s\n", env);
	} 
}

void set_environ(int flag, char *arg1, char *arg2){
	if (flag == 1){
		printf("Слишком мало аргументов...\n");
		printf("Запуск программы должен выглядеть так:\n");
		printf("./environ <переменная> <значение>\n");
	}else{
		if (setenv (arg1, arg2, 1) != 0){
			printf("Невозможно установить значение для переменной %s\n", arg1);
		}
		printf("%s = %s\n", arg1, getenv(arg1));	
	}
}

void delete_environ(char *opt){
	if (unsetenv(opt) != 0)
        	printf("Невозможно удалить переменную %s\n", opt);
	else
		printf("Переменная удалена \n");
}

void printenv(){
	extern char **environ;
	int i;
	for (i = 0; environ[i] != NULL; i++){
	    printf("%s\n", environ[i]);
	}
}

void clear_environ(){
	extern char **environ;
	clearenv();	
}

void set_new(int a, int v, char *opt1, char *opt2){
	if (a == 1 && v == 1){
		if (setenv (opt1, opt2, 1) != 0){
			  printf("Невозможно установить значение для переменной %s\n", opt1);
		}
		printf("%s = %s\n", opt1, getenv(opt1));
	}
	if (a == 1 && v == 0){
		if (setenv (opt1, "", 1) != 0){
			  printf("Невозможно установить значение для переменной %s\n", opt1);
		}
		printf("%s = %s\n", opt1, getenv(opt1));	
	}

	if (a == 0 && v ==1){
		printf("Ошибка выполнения....\n");
	}
}
