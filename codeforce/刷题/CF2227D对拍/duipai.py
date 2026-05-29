#!/usr/bin/env python3
import sys
import os
import random
import subprocess

# -------------------- 配置 --------------------
SOLVE_CPP = "CF_2227_D.cpp"          # 待测程序源码
EXE_NAME = "solve"               # 编译出的可执行文件
TEST_COUNT = 1000                # 对拍次数
MAX_N = 7                        # n 的最大值（暴力 O(n³) 能承受的范围）
# ---------------------------------------------

def compile_solve():
    """编译待测程序"""
    cmd = ["g++", "-std=c++17", "-O2", SOLVE_CPP, "-o", EXE_NAME]
    ret = subprocess.run(cmd, capture_output=True)
    if ret.returncode != 0:
        print("编译失败：")
        print(ret.stderr.decode())
        sys.exit(1)

def generate_test(n):
    """生成一个合法的测试用例，返回 n 和序列 a (1-indexed)"""
    a = []
    for i in range(n):
        a.append(i)
        a.append(i)
    random.shuffle(a)
    # 确保恰好有两个 0
    return n, a

def brute_force(n, a):
    """
    暴力计算正确答案：
    枚举所有子数组，检查是否包含至少两个 0 且为回文，若满足则计算 MEX，取最大值。
    """
    ans = 1  # 至少包含一个 0 时 MEX 至少为 1，但合法区间有两个 0，故 MEX >= 2
    length = 2 * n
    for l in range(length):
        for r in range(l, length):
            # 检查是否包含至少两个 0
            zero_cnt = sum(1 for i in range(l, r + 1) if a[i] == 0)
            if zero_cnt < 2:
                continue
            # 检查回文
            is_pal = True
            left, right = l, r
            while left < right:
                if a[left] != a[right]:
                    is_pal = False
                    break
                left += 1
                right -= 1
            if not is_pal:
                continue
            # 计算 MEX
            present = [False] * (n + 2)  # 最多到 n
            for i in range(l, r + 1):
                x = a[i]
                if x < len(present):
                    present[x] = True
            mex = 0
            while present[mex]:
                mex += 1
            ans = max(ans, mex)
    return ans

def run_solve(n, a):
    """运行待测程序，传入测试数据，返回输出中的整数结果（假设输出只有一行一个整数）"""
    input_str = f"{n}\n{' '.join(map(str, a))}\n"
    proc = subprocess.run(
        ["./" + EXE_NAME],
        input=input_str,
        capture_output=True,
        text=True,
        timeout=5
    )
    if proc.returncode != 0:
        print("运行时错误：", proc.stderr)
        sys.exit(1)
    try:
        return int(proc.stdout.strip().split()[0])
    except:
        print("无法解析输出：", proc.stdout)
        sys.exit(1)

def main():
    print(f"编译 {SOLVE_CPP} ...")
    compile_solve()
    print(f"开始对拍 {TEST_COUNT} 次，n 范围 2 ~ {MAX_N}")
    for i in range(1, TEST_COUNT + 1):
        n = random.randint(2, MAX_N)
        n, a = generate_test(n)
        try:
            my_ans = run_solve(n, a)
            expected = brute_force(n, a)
        except Exception as e:
            print(f"第 {i} 次测试崩溃：{e}")
            break
        if my_ans != expected:
            print(f"❌ 第 {i} 次发现错误！")
            print(f"n = {n}")
            print(f"序列 = {a}")
            print(f"你的输出 = {my_ans}")
            print(f"正确输出 = {expected}")
            # 保存错误用例
            with open("error_case.txt", "w") as f:
                f.write(f"{n}\n{' '.join(map(str, a))}\n")
            sys.exit(1)
        else:
            print(f"第 {i} 次 AC  (n={n}, ans={my_ans})")
    print(f"🎉 全部 {TEST_COUNT} 次测试通过！")

if __name__ == "__main__":
    main()
