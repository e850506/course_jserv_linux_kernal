# 2020q1 Homework1 (lab0)
contributed by < `unknowntpo` >

# 目前進度

閱讀 K&R 6.1 Basics of structures 
以理解 Structure 與 Typedef 的基本用法 (在 lab0-c linked-list 宣告時會用到)
，並透過實作計算座標的程式 ```sqrt.c``` 來練習。
>[name=unknowntpo][time=Thu, Mar 5, 2020 7:10 PM]
* 待加強: 開發日誌排版技巧

---------

:::success
“If I had eight hours to chop down a tree, I’d spend six hours sharpening my axe.” – Abraham Lincoln

「如果我有 8 小時可以砍 1 棵樹，我會花 6 小時把斧頭磨利。」 – 亞伯拉罕．林肯
(類似漢語「工欲善其事，必先利其器」)
:::

:::info
圖標說明：
:dart: --> 目前進度
:::

-----------

## 依據 lab0-c 作業分析須具備能力
>誠實面對自己

目標: linux kernel lab0 作業 設定 2/22~3/7 完成

* 作業 (HackMD)
    * my [lab0-c](https://hackmd.io/@unknowntpo/lab0-c)
    * [OscarShiang 同學範本](https://hackmd.io/@WaryvM_MTuOkXtEEalFsvQ/Sy5oUP6MU)



:::info
>參考 makefile build 出檔案的方式來學習
>筆記設置成公開
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
* [CMU C Programming Lab: Assessing Your C Programming Skills](http://www.cs.cmu.edu/~213/labs/cprogramminglab.pdf)
    * [CMU Linked List Tutorial](http://www.cs.cmu.edu/~iliano/courses/18S-CMU-CS122/handouts/10-linkedlist.pdf)

須具備基礎知識：
* :dart:C structure 基本概念
* Dynamic memory allocation
* :dart:Typedef 基本概念
    * K&R 6.7 Typedef
    * Typedef 在 structure 的應用

### Queue 基礎知識

---

:::warning
請不要建立獨立的共筆頁面來描述 Linux 核心學習日誌，這樣我和其他同學不容易給予意見，請彙整在本頁面，待日後再依據內容屬性，切分為獨立的頁面。現在請先收攏。
:notes: jserv
:::
>這段話是否能理解成，2020 Homework q1 內應該保存自己整理過後的知識重點(例如```typedef```的概念彙整)，
>而不是零碎未自行吸收整理的(e.g. Linux Kernel 開發學習日誌 2020.3.3 )這種無法根據內容給意見的流水帳呢？
>另外請問老師「開發紀錄」應該提及哪些必要資訊呢？
>[name=Chang Chen Chien][time=Wed, Mar 4, 2020 7:25 PM]

:::info
「開發紀錄」和「流水帳」本來就是兩件事:
1. 開發紀錄著重在問題和任務本質;
2. 個別任務已在作業要求做了說明，執行時自然會面臨未發現的挑戰，這就值得紀錄和探討;
3. 所見所聞所感若沒有整理，那就是流水帳;

:notes: jserv:
:::
>收到，已修正[name=Chang Chen Chien][time=Wed, Mar 4, 2020 8:39 PM] 

---

## 作業完成步驟
* 開發環境設定
* 取得程式碼並進行開發 :  :dart: 
    * clang-format 工具和一致的程式撰寫風格
    * Git Hooks 進行自動程式碼排版檢查
    * 撰寫 Git Commit Message 和自動檢查機制
    * 牛刀小試
        * 實作 ```q_size``` tutorial
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
```c
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

>The math library must be linked in when building the executable. How to do this varies by environment, but in Linux/Unix, just add ```-lm``` to the command.
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