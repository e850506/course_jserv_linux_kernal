# 2020q1 Homework1 (lab0)
contributed by < `unknowntpo` >

# 目前進度

* ~~K&R 6.2 Structure and functions~~
    * Follow the practice in K&R 6.2 Structure and Functions, to implement a program that can check whether a point is in rectangle or not.
* K&R p.131 pointer and structure operator precedence
    >[name=unknowntpo] [time=Wed, Mar 11, 2020 8:00 AM]
* queue.c
    * ~~q_new()~~
    * ~~q_size()~~
    * ~~q_free()~~
    * :dart: q_insert_head()
        * ```free(str)``` 的問題
# Outline
[TOC]

:::success
“If I had eight hours to chop down a tree, I’d spend six hours sharpening my axe.” – Abraham Lincoln

「如果我有 8 小時可以砍 1 棵樹，我會花 6 小時把斧頭磨利。」 – 亞伯拉罕．林肯
(類似漢語「工欲善其事，必先利其器」)
:::

:::info
圖標說明：
:dart: --> 目前進度
:::

## 依據 lab0-c 作業分析須具備能力
>誠實面對自己

目標: linux kernel lab0 作業 設定 2/22~3/7 完成

* 作業 (HackMD)
    * my [lab0-c](https://hackmd.io/@unknowntpo/lab0-c)
    * [OscarShiang 同學範本](https://hackmd.io/@WaryvM_MTuOkXtEEalFsvQ/Sy5oUP6MU)
    * [Adrain Huang 同學範本](https://github.com/AdrianHuang/lab0-c/commits/master?fbclid=IwAR1xOM3X-epOMTBtn-KpreTcr_o3IuxpBeTkXJ1zqTMBObLxF4sebxG2_sE)
        * Adrian Huang 針對給定的 lab0-c 專案進行更動，在他的 GitHub repository 中包含簡潔卻富含資訊量的 git  commit messages
    * [ZhuMon 同學範本](/@ZhuMon/lab0-c)
    * [Randy 同學範本](https://hackmd.io/@randy870819/system-prog-lab0?fbclid=IwAR3spFl04I9SYw_aRsYDtHl4oDX3rlQxlC8ujqgbywIBqhbzZIpA9bjLbwU)
        * Makefile 分析
    * Ryspon 同學範本
        * [2020q1 第 1 週隨堂測驗解題思路](/@Ryspon/HJVH8B0XU?fbclid=IwAR2VLjJWs_3hmp_jTWgtTooeFAOUz4dQ08lKThvHsUePNpr6AKCZShSlcJc)
        * Ryspon 針對第 1 週隨堂測驗，給出他的解題思路，請見下方共筆。在不存在環狀結構的狀況下，給定一個遞迴函式能對 linked list 元素進行排序。
除了解題，他嘗試擴充為 circular doubly-linked list 並重新實作對應的排序。

:::info
>參考 makefile build 出檔案的方式來學習
* target: e.g. linked-list 實作
* prerequisites: c structure. NULL pointer. Dynamic_memory allocation...
* command: 學習過程
```make
target: prerequisites
    command
```
:::

### Linked Lists 基礎知識

課內學習資源：
* :dart: [CMU C Programming Lab: Assessing Your C Programming Skills](http://www.cs.cmu.edu/~213/labs/cprogramminglab.pdf)
     
    * 閱讀日期 2/28~3/25 
        * [CMU Linked List Tutorial](http://www.cs.cmu.edu/~iliano/courses/18S-CMU-CS122/handouts/10-linkedlist.pdf)
            * Linked list
            * List-segment
            * Cycle_detection
            * Queue
            * Stack (未讀)

須具備基礎知識：
* ~~:dart:C structure 基本概念~~
* ~~Dynamic memory allocation~~
* ~~:dart:Typedef 基本概念~~
    * K&R 6.7 Typedef
    * Typedef 在 structure 的應用



## 作業完成步驟
* 開發環境設定
* 取得程式碼並進行開發 :
    * clang-format 工具和一致的程式撰寫風格
    * Git Hooks 進行自動程式碼排版檢查
    * 撰寫 Git Commit Message 和自動檢查機制
    * 牛刀小試
        * :dart: 實作 ```q_size``` tutorial
    * 以 Valgrind 分析記憶體問題
    * Valgrind 使用案例
* 自動測試程式
    * 追蹤記憶體配置和釋放的狀況
    * ```qtest``` 命令直譯器的實作
    * Signal 處理和應用
    * 命令直譯器的初始化準備
    * [你所不知道的C語言: Stream I/O, EOF 和例外處理](https://hackmd.io/@sysprog/c-stream-io)
* 作業要求

---

## 目前進度:

### ```q_size()```
```cpp
int q_size(queue_t *q)
{
    return q->size;
}
```
```make test ``` 評分
```shell
+++ TESTING trace trace-14-perf:
# Test performance of size
---     trace-14-perf   6/6
```

### ```q_new()```

```cpp
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if(!q)
        return NULL;
    // q is an empty queue now, so head and tail are NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0; // set the size to zero.
    /* TODO: Dummy node implementation and
     * experiment the different with current ver. */
    return q;
}
```

```make test``` 評分
```shell
+++ TESTING trace trace-10-malloc:
# Test of malloc failure on new
---	trace-10-malloc	6/6
```
> YA~6分，表示有得分很開心，我們實作的 malloc function 是可以的，之後實作完整個作業後再開啟 new branch 來嘗試 Dummy node 的使用。[name=unknowntpo] [time=Thu, Mar 26, 2020 9:35 PM]
 
---

### ```q_free()```

### ```q_insert head()```

```cpp=51
/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    /* If q is NULL, return false */
    if (!q)
        return false;
    /* declare new head */
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    /* If malloc of newh failed, return false */
    if (!newh)
        return false;
    /* Declare a pointer to array of char */
    char *str;
    int len = strlen(s);
    str = malloc(len + 1);
    /* If malloc failed, return false */
    if (!str) {
        free(newh);
        return false;
    }
    /* Connect the link */
    newh->next = q->head;
    q->head = newh;
    /* If q->tail is NULL, means LL is empty, assign it to newh */
    if (!q->tail)
        q->tail = newh;

    /* if currently tail point to NULL, make it point to newh */
    if (!q->tail)
        q->tail = newh;
    /* Copy s to str */
    str = strncpy(str, s, len);
    str[len] = '\0';
    newh->value = str;
    q->size++;
    /* Free str to avoid memory leak */
    // free(str);
    return true;
}
```
#### strncpy 問題
:::spoiler



為什麼在做完 string copy, 並 return 之前，我嘗試釋放一個自己 malloc 的記憶體區塊 str 時，反而在使用```make test```測試的時候產生亂碼並出現錯誤訊息呢？
```
$ make check
  CC	queue.o
  LD	qtest
./qtest -v 3 -f traces/trace-eg.cmd
cmd>
cmd> # Demonstration of queue testing framework
cmd> # Use help command to see list of commands and options
cmd> # Initial queue is NULL.
cmd> show
q = NULL
cmd> # Create empty queue
cmd> new
q = []
cmd> # Fill it with some values.  First at the head
cmd> ih dolphin
q = [UUUUUUUU����]
cmd> ih bear
q = [UUUUU���� �ޭCBV]
cmd> ih gerbil
q = [UUUUUUU���� �ޭCBV �ޭCBV]
cmd> # Now at the tail
cmd> it meerkat
Insertion of meerkat failed
q = [UUUUUUU���� �ޭCBV �ޭCBV]
cmd> it bear
Insertion of bear failed
q = [UUUUUUU���� �ޭCBV �ޭCBV]
cmd> # Reverse it
cmd> reverse
q = [UUUUUUU���� �ޭCBV �ޭCBV]
cmd> # See how long it is
cmd> size
Queue size = 3
q = [UUUUUUU���� �ޭCBV �ޭCBV]
cmd> # Delete queue.  Goes back to a NULL queue.
cmd> free
ERROR: Attempted to free unallocated block.  Address = 0x564243addef0
ERROR: Attempted to free unallocated or corrupted block.  Address = 0x564243addef0
ERROR: Corruption detected in block with address 0x564243addef0 when attempting to free it
ERROR: Attempted to free unallocated block.  Address = 0x564243addeb0
ERROR: Attempted to free unallocated block.  Address = 0x564243addeb0
ERROR: Attempted to free unallocated or corrupted block.  Address = 0x564243addeb0
ERROR: Corruption detected in block with address 0x564243addeb0 when attempting to free it
ERROR: Time limit exceeded.  Either you are in an infinite loop, or your code is too inefficient
q = NULL
ERROR: Freed queue, but 1 blocks are still allocated
cmd> # Exit program
cmd> quit
Freeing queue
ERROR: Freed queue, but 1 blocks are still allocated
Makefile:42: recipe for target 'check' failed
make: *** [check] Error 1
```
#### 解決
FB 問答回覆
>在 ```q_insert head()``` 中的 91 行，將 newh->value = str 時 newh->value 跟 str 指向同一個地方，當 free(str) 會讓
newh->value 指向一個空的地方。
還有在 q_insert_head 中 85 行 strncpy 執行完後可以不用 str[len] = '\0'; ，strncpy 會幫你填 '\0'。
[name=張佳鴻]

我的解讀
> 為了從 s 複製一個字串的內容而動態配置的記憶體片段，原本是由 str 指向它 ， 但是經由 newh->value = str 這個動作，現在換成是 newh->value 與str 來指向它並存在 linked list 內，所以並不需要釋放這個記憶體片段

老師補充
>感謝 張佳鴻 回覆。注意 Linux Programmer's Manual 的說明: "If there is no null byte among the first n bytes of src, the string placed in dest will not be null-terminated." / "If the length of src is less than n, strncpy() writes additional null bytes to dest to ensure that a total of n bytes are written."
>
我查的資料
>in Linux Programmer's Manual
"The stpncpy() and strncpy() functions copy at most len characters from
     src into dst.  If src is less than len characters long, the remainder of
     dst is filled with `\0' characters.  Otherwise, dst is not terminated.
     The source and destination strings should not overlap, as the behavior is
     undefined."
:::

:::spoiler
### 閱讀 K&R 6.1 Basics of structures
#### Declaration of structure
可行的宣告方式：
```cpp
struct {...} x, y, z;
```
or
```cpp
struct struct_tag {
    type member1;  // type can be int, struct, float
    type member2;
} struct_variable;
```

It's important to note that:
* ```struct_tag``` is optional
* when ```struct_variable``` is declared, system will allocate memory to it.
        
To access the member ```member1``` in a structure ```struct_tag```, we can use:
```cpp
struct_variable.member1;
```
### 善用 Typedef 簡化程式宣告

For example,
Consider following code ```mysqrt.c```
which calculate the distance between origin and point ```pt```:
```cpp
#include <stdio.h>
#include <math.h>

typedef struct {
   int x;
   int y;
} point;

int main() {
    point pt = {10, 20}; // declare and initialize a structure and its members
    double dist;
    printf("pt = (%d,%d)\n", pt.x, pt.y);
    dist = sqrt( (double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("distance from origin to pt = %lf\n", dist);
}
```

compile it. 
```shell
$ gcc mysqrt.c -o mysqrt 
```

Output:
```shell
$ mysqrt.c:23: undefined reference to `sqrt'
collect2: error: ld returned 1 exit status
```
:::warning
初步猜測 ```ld``` 可能與 linker 有關
透過 google 搜尋關鍵字:
undefined reference to ```sqrt```
:::

在 [stack overflow](https://stackoverflow.com/questions/10409032/why-am-i-getting-undefined-reference-to-sqrt-error-even-though-i-include-math)

有人問一樣的問題

Answer:

> The math library must be linked in when building the executable. How to do this varies by environment, but in Linux/Unix, just add ```-lm``` to the command.
The math library is named ```libm.so```, and the ```-l``` command option assumes a ```lib``` prefix and ```.a``` or ```.so``` suffix.[name=wallyk]

> 我的理解
linker 在連結的時候沒有找到 ```libm.so``` 這個檔案裡的 ```sqrt()``` function 

修改 gcc 指令：
```shell
$ gcc mysqrt.c -o mysqrt -lm 
```

得到正確結果
```shell
$ ./mysqrt
pt = (10,20)
distance from origin to pt = 22.360680
```

##### 衍伸問題
```libm.so``` 是什麼呢？
跟 ```<math.h>``` 有什麼關係？
如何解釋 ```undefined reference``` ?

:::warning
請參閱 [你所不知道的 C 語言：動態連結器篇](https://hackmd.io/@sysprog/c-dynamic-linkage) 和 [你所不知道的 C 語言：連結器和執行檔資訊](https://hackmd.io/@sysprog/c-linker-loader)，有對應的解說。
:notes: jserv
:::

>收到，待補上心得
>[name=unknowntpo][time=7:55 March 7 2020] 

### Typedef 後的變數是否只能與同一個 Typedef 下的變數相容  

參考 ISO / IEC 98996.7.7 Type definitions:
> In a declaration whose storage-class specifier is ```typedef```, each declarator defines an identifier to be a typedef name that denotes the type specified for the identifier in the way described in 6.7.5. Any array size expressions associated with variable length array declarators are evaluated each time the declaration of the typedef name is reached in the order of execution.
A typedef declaration does not introduce a new type, only a synonym for the type so specified. That is, in the following declarations:
> ```cpp
> typedef T type-ident;
> type-ident D;
> ```
> 
> ```type_ident``` is defined as a typedef name with the type specified by the declaration specifiers in ```T``` (known as T), ==and the identifier in D has the type **derived-declaratortype-list T**== where the derived-declarator-type-list is specified by the declarators of D.
A typedef name shares the same name space as other identifiers declared in ordinary declarators.

(Page 135). 

Keywords:
* storage-class specifier.
* declarator

----

我的理解：
consider the code below:

```cpp
typedef int myint;
myint x;
```

* declaration specifier: ```int```
* type identifier: ```myint```
* declarator: ```x```
* A ```typedef``` does not introduce a new type, only a synonym of the type so specified.
* A ```typedef``` name shares the same name space as other identifiers declared in ordinary declarators.

參照 Example 2:

After the declarations:
```cpp
typedef struct s1 { int x; } t1, *tp1;
typedef struct s2 { int x; } t2, *tp2;
```

* Type ```t1``` and the type pointed to by ```tp1``` are compatible. 
* Type ```t1``` is also compatible with type ```struct s1```, 
* but not compatible with the types:
    * ```struct s2```,
    * ```t2```, 
    * the type pointed to by ```tp2```,
    * ```int```.
#### 關於 typedef 的 name space
根據 [typedef statement in C](https://overiq.com/c-programming-101/typedef-statement-in-c/)

關於 typedef 的 namespace，
如果 typedef 的宣告放在所有 function 外面，那他的 scope 就是 global 
，那所有的 function 都能使用這個 typedef.
但如果 typedef 的宣告放在某個 function 裡面，他的 scope 就是 local
，那在其他地方就不能使用它。

e.g.
Consider the code below,
```cpp=1
#include<stdio.h>

void foo(void);

int main()
{
    typedef unsigned char uchar;
    uchar ch = 'a';
    printf("ch inside main() : %c\n", ch);
    foo();
    return 0;
}

void foo(void)
{
    uchar ch = 'a'; // Error
    unsigned char ch = 'z';
    printf("ch inside foo() : %c\n", ch);
}
```
因為在
```c
typedef unsigned char uchar
```
的 scope 沒有包含```foo()```，
所以出現以下 error:
```shell
test_typedef.c: In function ‘foo’:
test_typedef.c:16:5: error: unknown type name ‘uchar’; did you mean ‘char’?
     uchar ch = 'a'; // Error
     ^~~~~
     char
test_typedef.c:17:19: error: conflicting types for ‘ch’
     unsigned char ch = 'z';
                   ^~
test_typedef.c:16:11: note: previous definition of ‘ch’ was here
     uchar ch = 'a'; // Error
```

##### 衍生問題 
namespace 是什麼？ scope 是什麼?

:::warning
這些詞彙是 [Programming Language Theory](https://en.wikipedia.org/wiki/Category:Programming_language_theory) (PLT) 的術語，可簡易理解為:
1. namespace 著重於 identifier (即編譯器解析原始程式碼之後所任得的單元，可以是變數或函式名稱) 的區別方式;
2. scope 在中文翻譯是「作用區域」，不特別區隔 identifier，但考慮到同樣名稱但真正有效的範圍，例如:
```cpp
int i = 0;
int foo() { i++; }
int main() {
    int i = 100;
    for (int i = 1; i < 100; i++) ;
}
```
變數 `i` 的數值取決於在哪裡取得 (evaluate)，顯然在 `foo`, `main`, `for` 都會不同，而且參照的物件也不同，有 local 也有 global。

:notes: jserv
:::

### K&R 6.2 - Check whether a point is in rectangle or not

The full code is in [gist](https://gist.github.com/unknowntpo/ebfdacc4a2e085a496d89b76c7628baa).

參考資料
[你所不知道的 C 語言：前置處理器應用篇](/@sysprog/c-preprocessor?type=view)

在 [Linux Kernel 開發日誌 2020.3.9](/YmvJFVXYR7aQfdaV7SHtMw) 中，
K&R p.130 的 ```canonrect()``` function
macro 作動不對 導致數值比較錯誤

Debug 後發現 
```cpp
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

relational operator ```>``` 寫反了。

#### 延伸問題

gdb debug 後發現
```shell
(gdb) l 96
91       * Return: a rect which data type is 'struct rect'.
92       */
93      rect cononrect (rect r)
94      {
95          rect temp;
96          temp.pt1.x = min(r.pt1.x, r.pt2.x);
97          temp.pt1.y = min(r.pt1.y, r.pt2.y);
98          temp.pt2.x = max(r.pt1.x, r.pt2.x);
99          temp.pt2.y = max(r.pt1.y, r.pt2.y);
100         return temp;
```
```gdb
Breakpoint 1, cononrect (r=...) at rect.c:96
(gdb) print temp
$1 = {pt1 = {x = 1, y = 0}, pt2 = {x = 5, y = 5}}
(gdb) print r
$2 = {pt1 = {x = 10, y = 10}, pt2 = {x = 0, y = 0}}
(gdb)
```
在 ```cononrect()``` 內， temp 一開始的數值是 
```gdb
$1 = {pt1 = {x = 1, y = 0}, pt2 = {x = 5, y = 5}}
```
推測是因為沒有被初始化的關係，所以有非預期的數值
```cpp
pt1.x = 1
pt2.x = 5
pt2.y = 5
```

出現
所以
在 gdb 內 assign variable 給 ```temp``` 
模擬 line 95 如果我們已經初始化 temp 的狀況。
```shell
(gdb) set variable temp = {{0,0},{0,0}}
```

之後再修改程式碼:
```cpp=95
rect temp = {{0, 0}, {0, 0}};
```

再使用 gdb 來測試
```shell
Breakpoint 1, cononrect (r=...) at rect.c:95
95          rect temp = {{0, 0}, {0, 0}};
(gdb) n
96          temp.pt1.x = min(r.pt1.x, r.pt2.x);
(gdb) print temp
$3 = {pt1 = {x = 0, y = 0}, pt2 = {x = 0, y = 0}}
(gdb)
```




發現到我們成功初始化 ```temp``` 了！

但其實我們不需要初始化，畢竟不管 ```temp``` 內的 member 是什麼數字，之後都會馬上被 assign 成別的數。


----
### K&R p.131 pointer and structure operator precedence

consider a structure
```cpp
struct {
    int len;
    char *str;
}*p;
```
>murmur: 這個宣告是否合法？
>[name=unknowntpo]

then,
* ```++p -> len```: 
    * access the address of structure member ```len```,
    * and imcrement ```len```
* ```(++p)->len```:
    * imcrement ```p``` and then access structure member len.

* ```*p->str++```:
    * access ```str```: ```(p->str)```
    * evaluate ```str```: ```(p->str)++ ```
    * get the value of ```str```.
    * evaluate```++```: increment the value that ```str``` point to. 
:::warning 
查詢 imcrement operator increment 的時間 
```*p->str++```: 解釋可能錯誤，該如何更好地用英文解釋這些運算的行為呢？ 我對用詞的掌握好像不太精準，可能會造成別人誤解
:::

* ```(*p->str)++```:
    * get access to ```str``` :```(p->str)```
    * get the value of ```str```: ```*(p->str)```
    * imcrement the value that ```str``` pointed to. ```*(p->str)++```
* ```*p++->str```:
    * ```p++```: 先 evaluate p++, 在下一個 sequence point 前 increment p;
    * ```p++->str```: get access to ```str```
    * get the value of ```str```
* 撰寫程式來測試這些操作是否為 Undefined Behavior
```cpp=1
#include <stdio.h>

struct {
    int len;
    char *str;
}*p;

int main() {

    p->len = 1;
    p->str = "hello";
    //printf("p -> len = %d", p->len);
    //printf("++p -> len = %d", ++p->len);
    return 0;
}
```
遇到 segmentation fault.
```shell
(gdb) b 10
Breakpoint 1 at 0x5fe: file pointer.c, line 10.
(gdb) r
Starting program: /home/ubuntu/course_jserv_linux_kernel/week1/struct/pointer

Breakpoint 1, main () at pointer.c:10
10          p->len = 1;
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
0x0000555555554605 in main () at pointer.c:10
10          p->len = 1;
(gdb)
```
segmentation fault:
查詢 [Core Dump (Segmentation fault) in C/C++](https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/)

推測可能是 
* structure 的宣告與
* structure pointer 的觀念沒弄清楚。
* 搞不懂 ```*p``` 的 scope, 所以存取了不能沒有存取權限的記憶體。

閱讀 K&R 6.4 Pointers to Structures 後再修改程式。

>小心得：
>基礎觀念還是要仔細學習，不能輕率，
>不然到最後還是要繞一大圈，反而更花時間
>[name=unknowntpo] [time=Thu, Mar 12, 2020 11:08 AM]












