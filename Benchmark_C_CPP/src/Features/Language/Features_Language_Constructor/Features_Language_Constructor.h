#ifndef CWE401_CONSTRUCTOR_MEMORY_LEAK_ABC_H_
#define CWE401_CONSTRUCTOR_MEMORY_LEAK_ABC_H_
class ABC
{
    public:
        ABC(int i);
        ~ABC();
        void print();
        int *data;
};
#endif