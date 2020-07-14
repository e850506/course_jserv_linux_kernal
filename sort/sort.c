/* Create by unknowntpo at 2020.06.12
 * @Description:
 *      sort integer array with different method
 *             - Bubble sort
 *             - Merge sort
 *             - Selection sort
 */
#include "sort.h"

/** @brief This function swap the 2 number passed in, using tmp to
 *  store the value, and do the swap operation.
 *  @param px A pointer to int
 *  @param py A pointer to int
 */
void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
/** @brief This function sort the integer array passed in
 *  , which size is specified by the second parameter,
 *  @param a A pointer to first element of an integer array.
 *  @param size specify the size of integer array a
 *  @return integer array a
 */
int *sort_bubble(int *a, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
        display(a, size);
    }
    return a;
}
/** @brief This function display the value passed in
 *  @param p The arrray passed in
 *  @param size The size of array
 */
void display(int *p, int size)
{
    /* Display the array */
    for (int i = 0; i < size; i++)
        printf("%d", *p++);
    printf("\n");
}

int main()
{
    // int a[] = {3, 2, 1};
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    // int a[] = {3, 1, 6, 5, 4, 2, 8, 7};
    int size = 8;
    int *p = a;
    /* TODO: use callback function to apply more sort method */
    p = sort_bubble(a, size);

    display(p, size);

    return 0;
}
