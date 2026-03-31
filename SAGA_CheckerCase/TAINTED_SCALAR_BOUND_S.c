/**
    Filename: TAINTED_SCALAR_BOUND_S.c
    Vuln: TAINTED_SCALAR_BOUND_S
    SourceLine: -1
    SinkLine: 30
    Comment: 不可信任的循环边界
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

struct packet
{
    short int conid;
    short int type;
    short int comid;
    short int datalen;
    char buffer[504];
};
static size_t size_packet = sizeof(struct packet);

void TAINTED_SCALAR_BOUND_S_BAD(struct packet* hp, struct packet* data, int sfd, FILE* f)
{
    int x;
    x = recv(sfd, data, size_packet, 0);
    
    for(int i = 0; i < x; i++)  //缺陷点：x 没有进行边界检查，在此处使用了被污染的数据
    {
        data->buffer[i] = 'x';
    }
    // do something
}

void TAINTED_SCALAR_BOUND_S_GOOD(struct packet* hp, struct packet* data, int sfd, FILE* f)
{
    int x;
    x = recv(sfd, data, size_packet, 0);
    if(x > 0 && x <= sizeof(data->buffer))
    {
        for(int i = 0; i < x; i++)  //修复点：x 在之前进行边界检查
        {
            data->buffer[i] = 'x';
        }
    }
    // do something
}