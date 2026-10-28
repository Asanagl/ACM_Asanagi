import subprocess, os

os.chdir('verify')

tests = [
    ('ex00.cpp', '', '2\n', '负数取余修正'),
    ('ex01.cpp', '', '70\n', '复合赋值'),
    ('ex02.cpp', '', '6 5\n6 6\n', '自增自减'),
    ('ex03.cpp', '', '1\n0\n', '关系运算'),
    ('ex04.cpp', '73\n', '1 0 0\n', '逻辑运算'),
    ('ex05.cpp', '0 12\n', 'not divisible\n', '短路'),
    ('ex06.cpp', '', '10000000000\n', '1LL 溢出'),
    ('ex07.cpp', '', 'equal\n', '浮点 eps'),
    ('ex08.cpp', '', '8\n', '^ 不是乘方'),
    ('ex09.cpp', '', '66\nB\n', 'A+1'),
    ('ex10.cpp', '', '12\nC\n', '字符运算'),
    ('ex11.cpp', '8\n', 'digit 8\n', '字符分类'),
    ('ex12.cpp', '75\n', 'pass\n', 'if'),
    ('ex12.cpp', '40\n', '', 'if 不成立'),
    ('ex13.cpp', '13\n', 'odd\n', 'if/else'),
    ('ex14.cpp', '86\n', 'B\n', 'else if'),
    ('ex15.cpp', '20 1\n', 'enter\n', '嵌套if 1'),
    ('ex15.cpp', '20 0\n', 'buy a ticket\n', '嵌套if 2'),
    ('ex15.cpp', '15 1\n', 'too young\n', '嵌套if 3'),
    ('ex16.cpp', '2000\n', 'leap year\n', '闰年 2000'),
    ('ex16.cpp', '1900\n', 'common year\n', '闰年 1900'),
    ('ex16.cpp', '2024\n', 'leap year\n', '闰年 2024'),
    ('ex17.cpp', '20 * 6\n', '120\n', 'switch'),
    ('ex18.cpp', '8 5\n', '8\n', '条件运算符'),
    ('ex19.cpp', '12030\n', '03021\n', 'while 倒序'),
    ('ex20.cpp', '100\n', '5050\n', 'for 求和'),
    ('ex21.cpp', '7\n', 'Please enter a positive integer: accepted 7\n', 'do-while'),
    ('ex21.cpp', '-2\n0\n7\n', 'Please enter a positive integer: Please enter a positive integer: Please enter a positive integer: accepted 7\n', 'do-while 多轮'),
    ('ex22.cpp', '100\n', '5050\n', 'while 求和'),
    ('ex23.cpp', '5\n', '5 4 3 2 1 0\n', '倒序'),
    ('ex24.cpp', '97\n', 'prime\n', '质数 97'),
    ('ex24.cpp', '1\n', 'not prime\n', '质数 1'),
    ('ex24.cpp', '12\n', 'not prime\n', '质数 12'),
    ('ex25.cpp', '7\n', '16\n', '奇数和 for'),
    ('ex27.cpp', '5\n', '9\n', 'continue 修正一'),
    ('ex29.cpp', '42\n', '4 2\n', '双层 break'),
    ('ex30.cpp', '', '(1,1) (1,2) (1,3) \n(2,1) (2,2) (2,3) \n', '嵌套执行顺序'),
    ('ex31.cpp', '4\n', '*\n**\n***\n****\n', '直角三角形'),
    ('ex33.cpp', '3\n3\n0\n5\n', '6\n0\n15\n', 't 组'),
    ('ex34.cpp', '3 5 -2\n', '6\n', 'EOF'),
    ('ex35.cpp', '12 34\n99 1\n0 0\n', '46\n100\n', '哨兵'),
    ('ex36.cpp', '3\n', '14\n', '平方和'),
    ('ex37.cpp', '6\n10 20 30 40 50 60\n', '1\n', '计数'),
    ('ex38.cpp', '20\n', '2432902008176640000\n', '阶乘'),
    ('ex39.cpp', '5\n7 -2 0 12 4\n', 'sum 21\npositive 3\nmaximum 12\n', '边读边处理'),
    ('ex40.cpp', '1234\n', '10\n', '数位和'),
    ('ex41.cpp', '', '153\n370\n371\n407\n', '水仙花'),
    ('ex42.cpp', '12 34\n99 1\n0 0\n', '46\nNO\n', '数字翻转'),
    ('ex44.cpp', '2\n3 0\n1 1\n-1 1\n-2 2\n5 7\n-6 1\n99 10\n-99 20\n18 1\n50 20\n', '1\n5\n', '蚂蚁'),
    ('ex45.cpp', '5\n9 5 6 8 9\n', '7.67\n', '平均分'),
    ('ex46.cpp', '5\n', '0102030405\n06070809\n101112\n1314\n15\n', '数字三角形'),
    ('ex48.cpp', '', '3.14\n07\n', 'cout 格式'),
    ('ex49.cpp', '10 110\n100 200 150 140 129 134 167 198 200 111\n', '5\n', '摘苹果'),
    ('ex50.cpp', '290\n230\n280\n200\n300\n170\n340\n50\n90\n80\n200\n60\n', '-7\n', '津津样例1'),
    ('ex50.cpp', '290\n230\n280\n200\n300\n170\n330\n50\n90\n80\n200\n60\n', '1580\n', '津津样例2'),
    ('ex51.cpp', '12\n', '1 2 3 4 6 12 \n', '约数'),
    ('ex52.cpp', '', '0 25 75\n4 18 78\n8 11 81\n12 4 84\n', '百鸡'),
    ('ex53.cpp', '4\n', '1 2\n1 3\n1 4\n2 3\n2 4\n3 4\n', '数对'),
    ('ex54.cpp', '100\n', '7\n', '倍增'),
    ('ex55.cpp', '1000000\n', '500000500000\n', '等差公式'),
    ('ex56.cpp', '100 73\n', 'found 73\nguesses 6\n', '二分'),
]

fails = 0
for f, inp, expected, note in tests:
    exe = './' + f[:-4] + '.exe'
    try:
        r = subprocess.run([exe], input=inp, capture_output=True, text=True, timeout=5)
    except subprocess.TimeoutExpired:
        print(f'FAIL {f} [{note}]: TIMEOUT')
        fails += 1
        continue
    got = r.stdout
    if got == expected:
        print(f'ok   {f} [{note}]')
    else:
        print(f'FAIL {f} [{note}]:\n  expected: {expected!r}\n  got:      {got!r}')
        fails += 1

print(f'---\ntotal {len(tests)} tests, {fails} failed')
