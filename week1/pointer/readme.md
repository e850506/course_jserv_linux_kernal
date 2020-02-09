## C語言: 超好懂的指標，初學者請進～

### 取址運算符: ```&```

參考以下Code

```c
##include <stdio.h>

int main(){
    int b = 2;
    printf("value of b = %d\n",b);
    printf("address of b = %x\n",&b);
    printf("address of b = %p\n",&b);
    return 0;
}
```
Output:
```shell
$ ./addr
value of b = 2
address of b = e6da47d8
address of b = 0x7ffee4ad47d8
```
> b 只有48位元？？

## 怎麼樣能利用一個變數的地址、去拿到這個變數呢？

```c
##include <stdio.h>

int main(){
    int b = 2;
    printf("value of b = %d\n",b);
    printf("address of b = %p\n",&b);
    printf("Value of b = %d\n, *&b"); // get the value from the addr of b
    return 0;
}
```
Output:
```shell
$ ./addr
value of b = 2
address of b = 0x7ffeef36f7d8
Value of b = 2
```
* ```b``` and ```*&b```是等價的 (*& 位置不能交換 無法解釋)
