import random, subprocess, sys

SEED = 12345
ROUNDS = 120
rng = random.Random(SEED)

def oracle_tokens(A):
    n=len(A); m=len(A[0])
    return [str(A[i][j]) for j in range(m) for i in range(n-1,-1,-1)]

def fmt(A):
    n=len(A); m=len(A[0])
    parts=[f"{n} {m}"]+[" ".join(map(str,r)) for r in A]
    return ("\n".join(parts)+"\n").encode()

def run(exe,data):
    p=subprocess.run([exe],input=data,capture_output=True,timeout=180)
    assert p.returncode==0,(exe,p.returncode,p.stderr[:200])
    return p.stdout.decode().split()

fails=0; shapes=set()
for t in range(1,ROUNDS+1):
    mode=t%8
    if mode==0: n,m=1,rng.randint(1,500)
    elif mode==1: n,m=rng.randint(1,500),1
    elif mode==2: n=rng.randint(1,40); m=rng.randint(1,40)
    elif mode==3: n=rng.randint(200,500); m=rng.randint(1,5)
    elif mode==4: n=rng.randint(1,5); m=rng.randint(200,500)
    elif mode==5: n=rng.randint(1,500); m=rng.randint(1,500)
    elif mode==6: n=500; m=rng.randint(1,500)
    else: n=rng.randint(1,500); m=500
    shapes.add((n,m))
    lo,hi=rng.choice([(-10**9,10**9),(0,0),(-1,1),(-10**9,-10**9),(10**9,10**9)])
    A=[[rng.randint(lo,hi) for _ in range(m)] for _ in range(n)]
    data=fmt(A)
    exp=oracle_tokens(A)
    o1=run('./solution.exe',data); o2=run('./solution2.exe',data)
    if o1!=exp:
        print(f'ROUND {t}: MAIN MISMATCH n={n} m={m}'); fails+=1; break
    if o2!=exp:
        print(f'ROUND {t}: SOL2 MISMATCH n={n} m={m}'); fails+=1; break
    lines=[l for l in ("\n".join(o1)).split("\n")]
    txt=open('perf/last.out','wb'); txt.write((" ".join(o1)).encode()); txt.close()
print(f'seed={SEED} rounds={ROUNDS} distinct_shapes={len(shapes)} failures={fails}')
sys.exit(1 if fails else 0)
