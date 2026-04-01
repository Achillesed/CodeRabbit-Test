#include "benchmark.h"
#include <QList>
#include <QVector>
#include <qmap.h>
void Abilities_Env_QList_good()
{
    int *source = nullptr;
    QList<int*> list;
    list.append(source);
    list.append((int*)alloca(100));
    int * source2 = list.back();
    int sink = *source2;            // 没有空指针解引用
    (void)sink;
}

void Abilities_Env_QList_bad()
{
    int *source = nullptr;
    QList<int*> list;
    list.append(source);
    int * source2 = list.back();
    int sink = *source2;            // 空指针解引用
    (void)sink;
}

void Abilities_Env_QVector_bad()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    QVector<int*> vector;
    int *source = nullptr;
    vector.push_back(source);
    int sink = *vector[0];          // 空指针解引用
    (void)sink;
}

void Abilities_Env_QVector_good()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    QVector<int*> vector;
    int *source = nullptr;
    vector.push_back(source);
    vector.push_back((int*)alloca(100));
    int sink = *vector[1];          // 空指针解引用
    (void)sink;
}

void Abilities_Env_QMap_bad()
{
    QMap<int,int*> qmap;
    int *source = nullptr;
    qmap[0] = source;
    int sink = *qmap[0];          // 空指针解引用
    (void)sink;
}

void Abilities_Env_QMap_good()
{
    QMap<int,int*> qmap;
    int *source = nullptr;
    qmap[1] = source;
    qmap[2] = (int*)alloca(100);
    int sink = *qmap[2];          // 没有空指针解引用,qmap[2]不为空
    (void)sink;
}

void Abilities_Env_Qt_main()
{
    Abilities_Env_QList_good();
    Abilities_Env_QList_bad();
    Abilities_Env_QVector_bad();
    Abilities_Env_QVector_good();
    Abilities_Env_QMap_bad();
    Abilities_Env_QMap_good();
}