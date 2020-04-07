/*
 * @Title: Structure operator ->
 * @Author: unknowntpo
 * @Time: 2020.3.19 (Thu)
 * @Short Description
 *      Define a structure with members and observe its address and behavior of ->
 *      and use gdb to test the behavior.
 *
 */     
typedef struct ELE{
    int value;
    struct ELE *next;
}list_ele_t;

int main()
{
    list_ele_t *A;
    A->value = 1;
    A->next = NULL;
}
