/**
 * @brief Demonstrates a buffer under-read caused by accessing an array with a negative index.
 *
 * This function declares a five-element integer array and intentionally uses a negative index,
 * resulting in an out-of-bounds read (buffer under-read).
 *
 * @returns 0
 */

int NEGATIVE_INDEX_READ_S_BAD() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = -1;
    int a = arr[index];     //缺陷点：数组索引 index 值为 -1
    return 0;
}

/**
 * Performs a safe access of a local integer array using a valid index.
 *
 * Accesses the first element of a five-element array (index 0) and returns 0.
 *
 * @returns 0.
 */
int NEGATIVE_INDEX_READ_S_GOOD() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 0;
    int a = arr[index];     //修复点：数组索引 index 值为 0
    return 0;
}