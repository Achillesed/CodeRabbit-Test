#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 user_input

void OS_CMD_INJECTION_S_BAD(int socket)
{
    char user_input[1024];
    int recvResult = recv(socket, user_input, sizeof(user_input), 0);
    if (recvResult == -1 || recvResult == 0)
    {
        return;
    }
    execl(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);    //缺陷点
}

void OS_CMD_INJECTION_S_GOOD()
{
    char *user_input;
    user_input = COMMAND_ARG2;
    execl(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);    //修复点
}