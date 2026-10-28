import os, sys
parts = os.environ['PATH'].split(';')
keep = [p for p in parts if ('Git' + os.sep + 'mingw64') not in p and ('Git' + os.sep + 'usr') not in p]
sys.stdout.write(';'.join(keep))
