# 解法メモ

## ABC199
### C問題
#### 問題文

長さ 2N の文字列 S があります。  

この文字列に対して Q 個のクエリが与えられます。i 番目のクエリでは 3 つの整数 T\_i, A\_i, B\_i が与えられるので、以下の処理をします。 




* T\_i = 1 のとき : S の A\_i 文字目と B\_i 文字目を入れ替える

* T\_i = 2 のとき : S の前半 N 文字と後半 N 文字を入れ替える(A\_i, B\_i の値は用いない)  

 例えば S が FLIP のときにこのクエリを処理すると、S は IPFL となる。



これら Q 個のクエリを与えられた順に全て処理した後の S を出力してください。 






#### 制約



* 1 \le N \le 2 \times 10^5

* S は長さ 2N の英大文字のみからなる文字列

* 1 \le Q \le 3 \times 10^5

* T\_i は 1 または 2

* T\_i = 1 のとき、1 \le A\_i \lt B\_i \le 2N

* T\_i = 2 のとき、A\_i = B\_i = 0

#### 解法メモ
/* 
公式解説
クエリを問題文の通りに処理すると、(例えば全て T_i = 2 の場合に) 計算量が \Theta(QN) となってしまい実行時間制限に間に合いません。<br>
そのため、T_i = 2 の場合を高速に処理しなければなりません。
今前半 N 文字と後半 N 文字が反転されているかを表す変数 t を持っておきます。(最初 t は偽です)
T_i = 2 のクエリのときは t の真偽を反転するだけで済みます。
T_i = 1 のクエリのとき、t が偽ならそのまま A_i 文字目と B_i 文字目を入れ替えればよいです。
t が真のとき、データ上の S は実際の S と比べて前半 N 文字と後半 N 文字が反転されています。実際の S のx 文字目は、x \le N のときデータ上の S では x + N 文字目に対応し、x \gt N のときはデータ上の S の x - N 文字目に対応します。<br>
よって、A_i, B_i をこのように変換してからデータ上の S で文字の交換を行えばよいです。

全てのクエリを処理し終わった後、最後に t が真なら S の前半 N 文字と後半 N 文字を反転してから出力し、偽なら S をそのまま出力すればよいです。<br>
この解法の計算量は O(N + Q) となるので、実行時間制限にも十分間に合います。
*/

/* 
自分の言葉
C問題は愚直に解くとTLEする問題が多い。

問題を見たときに考えるべきこと:
1. 愚直に解くと，最悪の計算量は\Theta(QN) 
    - S の前半 N 文字と後半 N 文字を入れ替える計算量は，O(N)
2. じゃあ，毎回入れ替えないでうまく解ける方法はないか探す
    -> 実際に操作せずに，反転されているかをフラグで保持だけにする（ここにたどり着いたらもう勝ち）
    - 帳尻があるように微調整

*/

### D問題