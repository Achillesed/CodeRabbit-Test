#include "benchmark.h"

void Abilities_Env_Teriminator_Wrapper()
{
    exit(1);
}
void Abilities_Env_Teriminator_Inter_good1(int argnum)
{
    int source = 0 ;        // divided zero source
    if(argnum)              // if argnum == 0
        Abilities_Env_Teriminator_Wrapper();
    int sink = 3/source;    // divided zero sink,
    (void)sink;
}
void Abilities_Env_Teriminator_Inter_bad1(int argnum)
{
    int source = 0 ;        // divided zero source
    Abilities_Env_Teriminator_Wrapper();
    int sink = 3/source;    // divided zero sink
    (void)sink;
}

void Abilities_Env_Teriminator_Intra_bad1(int argnum)
{
    int source = 0 ;        // divided zero source
    if(argnum)              // if argnum == 0
        exit(1);            
    int sink = 3/source;    // divided zero sink,
    (void)sink;
}
void Abilities_Env_Teriminator_Intra_good1(int argnum)
{
    int source = 0 ;        // divided zero source
    exit(1);                
    int sink = 3/source;    // divided zero sink
    (void)sink;
}



void Abilities_Env_Teriminator_main()
{
    int x;
    scanf("%d",&x);
    Abilities_Env_Teriminator_Inter_good1(x);
    Abilities_Env_Teriminator_Inter_bad1(x);
    Abilities_Env_Teriminator_Intra_good1(x);
    Abilities_Env_Teriminator_Intra_bad1(x);
}
