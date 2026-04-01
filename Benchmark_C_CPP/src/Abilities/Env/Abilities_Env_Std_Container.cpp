#include "benchmark.h"
#include <vector>
#include <set>
#include <map>
using namespace std;
void Abilities_Env_Std_vector_bad1()
{
    vector<int*> container;
    int *source = NULL;
    int *temp = (int*)malloc(4);
    container.push_back(source);
    container.push_back(temp);
    int sink = *container[0];       // 空指针解引用
    (void)sink;
    free(temp);
}
void Abilities_Env_Std_vector_bad2()
{
    vector<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.push_back(source);
    container.push_back(temp);
    int sink = *container.front();       // 空指针解引用
    (void)sink;
    free(temp);
}


void Abilities_Env_Std_vector_bad3()
{
    vector<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.push_back(source);
    int sink = *container.back();       // 空指针解引用
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_vector_bad4()
{
    vector<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.push_back(source);
    container.push_back(temp);
    int sink ;
    for(auto ptr : container)
    {
        sink = *ptr;                    // 空指针解引用
    }
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_set_bad()
{
    set<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.insert(source);
    container.insert(temp);
    int sink ;
    for(auto ptr : container)
    {
        sink = *ptr;                    // 空指针解引用
    }
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_vector_good1()
{
    vector<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.push_back(source);
    container.push_back(temp);
    int sink = *container[1];       // 没有空指针解引用
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_vector_good2()
{
    vector<int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container.push_back(source);
    container.push_back(temp);
    int sink = *container.back();       // 没有空指针解引用
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_map_bad()
{
    map<int,int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container[0] = source;
    container[1] = source;
    container[2] = temp;
    int sink = *container[0];       // 空指针解引用
    (void)sink;
    free(temp);
}

void Abilities_Env_Std_map_good()
{
    map<int,int*> container;
    int *source = NULL;
    int* temp = (int*)malloc(4);
    container[0] = source;
    container[1] = source;
    container[2] = temp;
    int sink = *container[2];       // 没有空指针解引用
    (void)sink;
    free(temp);
}


void Abilities_Env_Std_main()
{
    Abilities_Env_Std_vector_bad1();
    Abilities_Env_Std_vector_bad2();
    Abilities_Env_Std_vector_bad3();
    Abilities_Env_Std_vector_bad4();
    Abilities_Env_Std_vector_good1();
    Abilities_Env_Std_vector_good2();
    Abilities_Env_Std_set_bad();
    Abilities_Env_Std_map_bad();
    Abilities_Env_Std_map_good();
}
