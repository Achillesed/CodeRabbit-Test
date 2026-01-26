#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 user_input

/**
 * Read data from a socket and execute it as a shell command.
 *
 * Reads up to 1024 bytes from the given socket and passes the received data
 * directly to /bin/sh -c for execution. If reading from the socket fails or
 * the connection is closed (`recv` returns -1 or 0), the function returns
 * without executing a command. The received input is not validated and may
 * permit OS command injection.
 *
 * @param socket Descriptor of the connected socket to read command input from.
 */
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

/**
 * Execute a shell command using a fixed, trusted command string to avoid command injection.
 *
 * Calls execl with a predefined command argument (`COMMAND_ARG2`) so the executed shell command
 * does not depend on external or unvalidated input.
 */
void OS_CMD_INJECTION_S_GOOD()
{
    char *user_input;
    user_input = COMMAND_ARG2;
    execl(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);    //修复点
}