#!/bin/sh

contest_name=$1
url="https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_a"

contest_cat=${contest_name:0:3}

# a ではじまり，c で終わるか（abc, arc, agc）
if [[ "$contest_cat" =~ ^a && "$contest_cat" =~ c$ ]]; then
    cd $contest_cat
else
    cd others
fi

mkdir $contest_name && cd $contest_name

# 問題文の取得
poetry run python ../../get_problem_md.py $url -r a-f 

# スクリプトの作成
for c in a b c d e f; do
    {
    echo "#include <bits/stdc++.h>"
    echo "using namespace std;"
    echo ""
    echo -e "int main() {\n}"     
    } >> "${contest_name}_${c}.cpp"
done

# VSCodeで編集
code .