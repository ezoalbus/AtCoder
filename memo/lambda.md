## lambda式

基本文法

``` cpp
int main() {
    // 末尾の()で関数の呼び出し
    []{cout << "Hello World" << endl;}();
    return 0;
}
```

変数に代入

``` cpp
int main() {
    auto func = []{cout << "Hello World" << endl;};
    func(); // 呼び出し
    return 0;
}

引数を与える

``` cpp
int main() {
        [](string const & str) // 引数の定義
        {       // 関数本体
                cout << str << endl;
        }
        ( "I am Argument!");    // 関数呼び出しと引数
        return 0;
}
```


戻り値を返す

``` cpp
int main(int argc, char const* argv[])
{
        auto a = [] { return 0;} (); // 戻り値を推測させる
        auto b = [] () -> float { return 3.14; } (); //明示的に戻り値を定義
 
        cout << a << endl;
        cout << b << endl;
        return 0;
}
```

変数のキャプチャ

ラムダ式は、式が定義される関数のスコープの変数をキャプチャできます。JavaScriptでいうクロージャがスコープにある変数を参照できることをイメージしてみてください。[]はラムダキャプチャー(コピーか参照か)

``` cpp
int main(int argc, char const* argv[])
{
        string x = "I am string";
        [&] { cout << x << endl; } (); //参照
        [=] { cout << x << endl; } (); //コピー
        return 0;
}
```

参照の場合の代入

参照で上書きをしてみます。

``` cpp
int main(int argc, char const* argv[])
{
        string s1 = "I am s1";
        [&] { s1 = "Overwrite s1!"; } ();
        cout << s1 << endl;
        return 0;
}
```