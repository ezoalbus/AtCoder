# B - Intersection 
## URL: https://atcoder.jp/contests/abc199/tasks/abc199_b 

配点 : 200 点




### 問題文

長さ N の数列 A = (A\_1, A\_2, A\_3, \dots, A\_N), B = (B\_1, B\_2, B\_3, \dots, B\_N) が与えられます。  

以下の条件を満たす整数 x の個数を求めてください。 




* 1 \le i \le N を満たす全ての整数 i について A\_i \le x \le B\_i







### 制約



* 1 \le N \le 100

* 1 \le A\_i \le B\_i \le 1000

* 入力に含まれる値は全て整数









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
N
A\_1 A\_2 A\_3 \dots A\_N
B\_1 B\_2 B\_3 \dots B\_N
``` 





### 出力

答えを出力せよ。 








### 入力例 1


``` 
2
3 2
7 5
``` 





### 出力例 1


``` 
3
``` 

x は 3 \le x \le 7 と 2 \le x \le 5 の両方を満たさなければなりません。  

そのような整数 x は 3, 4, 5 の 3 個あります。 







### 入力例 2


``` 
3
1 5 3
10 7 3
``` 





### 出力例 2


``` 
0
``` 

条件を満たす整数 x が存在しないこともあります。 







### 入力例 3


``` 
3
3 2 5
6 9 8
``` 





### 出力例 3


``` 
2
```