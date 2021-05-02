# F - Substring 2 
## URL: https://atcoder.jp/contests/abc196/tasks/abc196_f 

配点 : 600 点




### 問題文

0, 1 からなる文字列 S, T が与えられます。  

T が S の部分文字列となるように、T のいくつかの文字を書き換えます。  

少なくとも何文字書き換える必要がありますか？



部分文字列とは？
S のある連続した部分を取り出してできる文字列が T と一致するとき、T は S の部分文字列であるといいます。
例えば、000 は 10001 の部分文字列ですが、11 は 10001 の部分文字列ではありません。






### 制約



* S, T は 0, 1 からなる

* 1 ≤ |T| ≤ |S| ≤ 10^6









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
S
T
``` 





### 出力

答えを出力せよ。








### 入力例 1


``` 
0001
101
``` 





### 出力例 1


``` 
1
``` 

T を 001 と書き換えると、S の 2 文字目から 4 文字目が T と一致します。







### 入力例 2


``` 
0101010
1010101
``` 





### 出力例 2


``` 
7
``` 






### 入力例 3


``` 
10101000010011011110
0010011111
``` 





### 出力例 3


``` 
1
```