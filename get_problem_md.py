import sys
import argparse
import time
import requests
from bs4 import BeautifulSoup as bs4
import markdownify


def cleanse_text(text):
    """ 改行&スペース除去（今後改善） """
    text = text.strip()
    return text


def extract_title(soup):
    """ タイトルを抽出 """
    title = soup.find('title')
    return title.text


def insert_linebreak(text):
    """ <pre> hoge </pre> をコードブロックにする """
    text = text.replace('<pre>', '\n``` \n')
    text = text.replace('</pre>', '``` \n')
    return text


def get_problem_states(soup):
    """ 問題文を抽出 """
    soup = soup.find('div', attrs={'id': 'task-statement'})
    statements = soup.find('span', attrs={'lang-ja'})  # 日本語のものだけ
    if statements is None:
        statements = soup
    statements = str(statements)
    statements = insert_linebreak(statements)

    # html -> md
    statements = markdownify.markdownify(statements, heading_style='ATX')
    return statements


def get_problem_md(url, md_dir=None):
    """ 問題文をマークダウンファイルとして保存する(main関数) """
    if md_dir is None:
        md_dir = './'

    html = requests.get(url)
    soup = bs4(html.content, 'html.parser')
    title = extract_title(soup)
    problem_statements = get_problem_states(soup)

    cleansed_text = f'# {title} \n' \
                    + f'## URL: {url} \n\n' \
                    + cleanse_text(problem_statements)

    # 整形した文章を.mdファイルとして書き出し
    task_name = url.split('/')[-1]
    file_path = md_dir + task_name + '.md'
    # print(cleansed_text)
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(cleansed_text)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("url", help="target url to scrape")
    # 取得対象の問題文
    parser.add_argument("-r", "--range", help="ex. 'abc' or 'a-d'")
    parser.add_argument("-d", "--dir")
    args = parser.parse_args()

    # 単一のurl(問題)の場合
    if args.range is None:
        get_problem_md(args.url, args.dir)

    # 複数(A-D問題まで等)取得する場合
    else:
        # base_urlの例: https://atcoder.jp/contests/abc199/tasks/abc199_a
        # base_urlの例: https://atcoder.jp/contests/zone2021/tasks/zone2021_a
        base_url = args.url

        # 取得対象の問題のパース（今後改善する）
        target_problem = args.range.lower()
        if target_problem == "a-d":
            target_problem = "abcd"
        if target_problem == "a-f":
            target_problem = "abcdef"
        # char_ls = target_problem.replace(' ', '').split(',')
        # target_problem = ''.join(char_ls)

        url_ls = [base_url[:-1] + e for e in target_problem]
        for url in url_ls:
            get_problem_md(url, args.dir)
            time.sleep(1)  # サーバーに負荷をかけないように(念の為)
