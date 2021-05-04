# A - White Cells 
## URL: https://atcoder.jp/contests/abc121/tasks/abc121_a 

配点 : 100 点




### 問題文

H 行 W 列の白色のマス目があります。


あなたは h 個の行と w 個の列を選び、選んだ行または列に含まれるマス目を全て黒色で塗りつぶします。


白色のマス目はいくつ残るでしょうか。


なお、残る白色のマス目の数は行や列の選び方によらないことが証明できます。






### 制約



* 入力は全て整数である。

* 1 \leq H, W \leq 20

* 1 \leq h \leq H

* 1 \leq w \leq W









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
H W
h w
``` 





### 出力

残る白色のマス目の数を出力せよ。








### 入力例 1


``` 
3 2
2 1
``` 





### 出力例 1


``` 
1
``` 

3 行 2 列の白色のマス目があり、2 行と 1 列を選んで黒色で塗りつぶしたとき、白色のマス目は必ず 1 個だけ残ります。







### 入力例 2


``` 
5 5
2 3
``` 





### 出力例 2


``` 
6
``` 






### 入力例 3


``` 
2 4
2 4
``` 





### 出力例 3


``` 
0
```