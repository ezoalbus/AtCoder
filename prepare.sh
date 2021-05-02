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

poetry run python ../../get_problem_md.py $url -r a-f 

code .