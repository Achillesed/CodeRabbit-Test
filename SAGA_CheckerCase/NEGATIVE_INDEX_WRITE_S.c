/**
 * Demonstrates a buffer underflow by writing to an array using a negative index.
 *
 * This function initializes a 10-element integer array, sets the index to -1,
 * and writes to array[index], illustrating an out-of-bounds (negative index) write.
 *
 * @returns 0 on completion.
 */


int NEGATIVE_INDEX_WRITE_S_BAD() 
{
    int array[10] = {0};
    int index = -1;
    array[index] = 10;      //缺陷点：数组索引 index 值为 -1
    return 0;
}

/**
 * Demonstrates a safe write to an array using a valid index.
 *
 * Writes the value 10 into a 10-element integer array at index 0 to avoid a negative-index buffer underflow.
 * @returns 0 on success.
 */
int NEGATIVE_INDEX_WRITE_S_GOOD() 
{
    int array[10] = {0};
    int index = 0;
    array[index] = 10;      //修复点：数组索引 index 值为 0
    return 0;
}