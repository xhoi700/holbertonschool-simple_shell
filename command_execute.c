#include"shell.h"
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
/**
 * execute - Function that executes the shell
 * @cmd_array: First operand a pointer
 * Return: Return an int
 */
int execute(char *cmd_arr[])
{
	pid_t pid;
	char *exe_path;
	int status;

	exe_path = command_path(cmd_arr[0]);
	if (exe_path == NULL)
	{
		write(1, cmd_arr[0], strlen(cmd_arr[0]));
		write(1, ": not found\n", 12);
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error at creating a child process\n");
		exit (1);
	}
	if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (WEXITSTATUS(status) != 0)
		{
			exit(2);
		}
	}
	else if (pid == 0)
	{
		execve(exe_path, cmd_arr, environ);
		perror("Error");
		exit(1);
	}
	free(exe_path);
	return (0);
}
