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

/**
 * Read up to sizeof(struct packet) bytes from a socket into `data` and overwrite the received range of `data->buffer` with the character 'x' without validating the received length.
 *
 * @param data Destination packet whose `buffer` is overwritten for the received byte count.
 * @param sfd  Socket file descriptor to read from.
 *
 * Note: The function does not check that the received byte count fits within `data->buffer`, which can lead to a buffer overflow if `recv` returns a value greater than `sizeof(data->buffer)`.
 */
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

/**
 * Read from a socket into the supplied packet and, when the received length is within the buffer limit, overwrite the first received bytes of the packet buffer with 'x'.
 *
 * Reads up to size_packet bytes from socket descriptor `sfd` into `data`. If the number of bytes received is greater than zero and less than or equal to `sizeof(data->buffer)`, the function writes the character `'x'` into `data->buffer[0..x-1]`.
 *
 * @param hp Pointer to a packet context (not used by this function).
 * @param data Destination packet whose `buffer` will be modified for the received byte count.
 * @param sfd Socket file descriptor to read from.
 * @param f FILE stream (unused by this function).
 */
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