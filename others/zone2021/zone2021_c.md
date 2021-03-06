# C - MAD TEAM 
## URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c 

配点 : 400 点




### ストーリー

さて、本格的に UFO と対峙する仲間を集めることにしよう。それも、とびきり MAD で優秀な。  

俺は数多の天才たちと競い合ってきた「AtCoder」上でメンバーを集めることにした。  

名の知れたプログラマに片っ端から声をかけてもいいが、どうせなら得意分野のバランスが良い少数精鋭で最高なチームを作るとしよう。






### 問題文

N 人のメンバー候補がおり、それぞれの人は、パワー・スピード・テクニック・知識・発想力の 5 種類の能力値を持っています。  

i 番目の人のパワーは A\_i 、スピードは B\_i 、テクニックは C\_i 、知識は D\_i 、発想力は E\_i です。  

あなたは、N 人のメンバー候補から 3 人を選び、1 つのチームを作ります。  

チーム全体のパワーをチームメンバーのパワーの最大値で定義します。スピード・テクニック・知識・発想力についても同様に定義します。  

チームの総合力を、チーム全体のパワー・スピード・テクニック・知識・発想力の最小値で定義します。  

チームの総合力としてありえる最大値を求めてください。






### 制約



* 入力は全て整数

* 3 ≤ N ≤ 3000

* 1 ≤ A\_i, B\_i, C\_i, D\_i, E\_i ≤ 10^9









### 入力

入力は以下の形式で標準入力から与えられる。



``` 
N
A\_1 B\_1 C\_1 D\_1 E\_1
A\_2 B\_2 C\_2 D\_2 E\_2
\vdots
A\_N B\_N C\_N D\_N E\_N
``` 





### 出力

答えを出力せよ。








### 入力例 1


``` 
3
3 9 6 4 6
6 9 3 1 1
8 8 9 3 7
``` 





### 出力例 1


``` 
4
``` 

3 人全員をチームに入れるほかありません。  

この時、チーム全体の各能力値は以下のようになります。 




* チーム全体のパワー : \max(3, 6, 8) = 8

* チーム全体のスピード : \max(9, 9, 8) = 9

* チーム全体のテクニック : \max(6, 3, 9) = 9

* チーム全体の知識 : \max(4, 1, 3) = 4

* チーム全体の発想力 : \max(6, 1, 7) = 7



したがって、チームの総合力は \min(8, 9, 9, 4, 7) = 4 となります。 







### 入力例 2


``` 
5
6 13 6 19 11
4 4 12 11 18
20 7 19 2 5
15 5 12 20 7
8 7 6 18 5
``` 





### 出力例 2


``` 
13
``` 

1, 2, 3 番目の人を採用すると、チームの総合力は \min(20, 13, 19, 19, 18) = 13 です。







### 入力例 3


``` 
10
6 7 5 18 2
3 8 1 6 3
7 2 8 7 7
6 3 3 4 7
12 8 9 15 9
9 8 6 1 10
12 9 7 8 2
10 3 17 4 10
3 1 3 19 3
3 14 7 13 1
``` 





### 出力例 3


``` 
10
```


