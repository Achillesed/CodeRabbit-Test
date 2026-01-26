void Features_Language_Reference_good_sink(int *&x)
{
    x = new int;
    *x = 42;
}

void Features_Language_Reference_bad_sink(int *&x)
{
    x = nullptr;
}


int Features_Language_Reference_bad(){
    int *myPointer = nullptr; // source
    Features_Language_Reference_bad_sink(myPointer);
    int ret = *myPointer; // NPD;
    delete myPointer;
    return ret;
}

int Features_Language_Reference_good(){
    int *myPointer = nullptr;
    Features_Language_Reference_good_sink(myPointer);
    int ret = *myPointer;
    delete myPointer;
    return ret;
}