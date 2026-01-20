/**
    Filename: TAINTED_SCALAR_ARG_S.c
    Vuln: TAINTED_SCALAR_ARG_S
    SourceLine: -1
    SinkLine: 32
    Comment: 不可信任的值作为了参数
*/

#include<stdio.h>
#include<stddef.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

#define	LENBUFFER	504
struct packet
{
	short int conid;
	short int type;
	short int comid;
	short int datalen;
	char buffer[LENBUFFER];
};

static size_t size_packet = sizeof(struct packet);

void TAINTED_SCALAR_ARG_S_BAD(struct packet* data, int sfd)
{
    int x;
    x = recv(sfd, data, size_packet, 0);
    struct packet* dataCopy = malloc(x * sizeof(struct packet));     //缺陷点：x 没有进行边界检查，在此处使用了被污染的数据
    // do something
    free(dataCopy);
}

void TAINTED_SCALAR_ARG_S_GOOD(struct packet* data, int sfd)
{
    int x;
    x = recv(sfd, data, size_packet, 0);
    if(x < 0 || x > sizeof(data->buffer)) return;
    struct packet* dataCopy = malloc(x * sizeof(struct packet));     //修复点：x 进行了边界检查
    // do something
    free(dataCopy);
}
