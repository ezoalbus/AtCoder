# B - Sign of Friendship 
## URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_b 

配点 : 200 点




### ストーリー

まずは友好の印として、UFO の操縦プログラムをクラッシュさせてみよう。俺は机の上の ZONe 缶に偽装した USB から、地球最強のコンピュータウイルス「KARATE」を取り出した。  

こいつを UFO に送りつけてやる。UFO がどんなシステムを使っているかは分からないが、あらゆるシステムをクラッシュさせてきた KARATE は、きっと効くはずだ。






### 問題文

あなたは今、高さ 1000 の非常に高いタワーの下にいます。タワーから距離 D 離れた位置の上空 H の高さに UFO がおり（入出力例 1 の図を参照してください）、あなたは UFO に電波を届けたいです。  

タワーと UFO の間には遮蔽物が N 個あります。i 番目の遮蔽物はタワーから UFO の方向に向かって距離 d\_i の場所に位置していて、高さは h\_i です。  

あなたはタワーを上って、あなたと UFO の間の直線上に遮蔽物が 1 つも無い状態にしたいです。上る必要のある最低の高さを求めてください。  

なお、地面は凹凸のない水平面であり、タワー及び遮蔽物は地面と垂直に建っているものとします。  

また、あなたと UFO の間の直線上にちょうど遮蔽物の上端があるとき、その遮蔽物には遮蔽されていないものとします。






### 制約



* 入力は全て整数

* 1 ≤ N ≤ 100

* 1 ≤ d\_i < D ≤ 1000

* 1 ≤ h\_i < H ≤ 1000









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
N D H
d\_1 h\_1
d\_2 h\_2
\vdots
d\_N h\_N
``` 





### 出力

答えを出力せよ。  

想定解答との絶対誤差または相対誤差が 10^{-3} 以下であれば正解と判定される。








### 入力例 1


``` 
1 10 10
3 5
``` 





### 出力例 1


``` 
2.857142857142857
``` 

タワーを \frac{20}{7} 上ると、図のようにあなたと UFO の間の直線上に遮蔽物が 1 つも無い状態になります。


![](https://img.atcoder.jp/ghi/425da28ab0802405a8541ed16d81e5cf.png)







### 入力例 2


``` 
1 10 10
3 2
``` 





### 出力例 2


``` 
0.0
``` 

タワーを登らずとも UFO に電波を届けることができます。







### 入力例 3


``` 
5 896 483
228 59
529 310
339 60
78 266
659 391
``` 





### 出力例 3


``` 
245.3080684596577
```