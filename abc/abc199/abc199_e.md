# E - Permutation 
## URL: https://atcoder.jp/contests/abc199/tasks/abc199_e 

配点 : 500 点




### 問題文

(1, 2, 3, \dots, N) を並び替えてできる数列 a であって、以下の条件を満たすものの数を出力してください。 




* 1 \le i \le M を満たす全ての整数 i について、a\_1, a\_2, a\_3, \dots, a\_{X\_i} の中に Y\_i 以下の数は Z\_i 個以下しか存在しない







### 制約



* 2 \le N \le 18

* 0 \le M \le 100

* 1 \le X\_i \lt N

* 1 \le Y\_i \lt N

* 0 \le Z\_i \lt N

* 入力に含まれる値は全て整数である









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
N M
X\_1 Y\_1 Z\_1
X\_2 Y\_2 Z\_2
X\_3 Y\_3 Z\_3
\hspace{23pt} \vdots
X\_M Y\_M Z\_M
``` 





### 出力

答えを出力せよ。 








### 入力例 1


``` 
3 1
2 2 1
``` 





### 出力例 1


``` 
4
``` 

条件を満たす a は以下の 4 つです。 




* (1, 3, 2)

* (2, 3, 1)

* (3, 1, 2)

* (3, 2, 1)



(1, 2, 3) や (2, 1, 3) は、a\_1, a\_2 の中に 2 以下の数が 2 つあるため条件を満たしません。 







### 入力例 2


``` 
5 2
3 3 2
4 4 3
``` 





### 出力例 2


``` 
90
``` 






### 入力例 3


``` 
18 0
``` 





### 出力例 3


``` 
6402373705728000
```