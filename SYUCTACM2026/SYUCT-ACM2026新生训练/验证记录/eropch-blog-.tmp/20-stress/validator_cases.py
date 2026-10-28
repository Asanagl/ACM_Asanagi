import subprocess
import sys
from pathlib import Path

BIN = Path(r"C:/Users/Asanagi/eropch-blog/.tmp/20-bin")


def validate(data):
    r = subprocess.run([str(BIN / "validator.exe")], input=data, capture_output=True, timeout=30)
    return r.returncode, (r.stderr.decode(errors="replace").strip().splitlines() or [""])[0]


cases = [
    ("too-few-cells", "2 2\r\n1 2\r\n3\r\n"),
    ("too-many-cells", "1 1\r\n1\r\n5\r\n"),
    ("value-too-big", "1 1\r\n10000001\r\n"),
    ("value-too-small", "1 1\r\n-10000001\r\n"),
    ("n-zero", "0 1\r\n1\r\n"),
    ("m-too-big", "1 501\r\n" + " ".join(["1"] * 501) + "\r\n"),
    ("missing-eoln", "1 1 5\r\n"),
    ("valid-1x1", "1 1\r\n-7\r\n"),
    ("valid-1x500", "1 500\r\n" + " ".join(["1"] * 500) + "\r\n"),
    ("valid-500x1", "500 1\r\n" + "\r\n".join(["1"] * 500) + "\r\n"),
]

bad = 0
for name, data in cases:
    rc, msg = validate(data.encode())
    want_ok = name.startswith("valid")
    ok = (rc == 0) if want_ok else (rc != 0)
    if not ok:
        bad += 1
    print(f"{'PASS' if ok else 'FAIL'} {name}: rc={rc} {msg}")

print(f"validator negative/positive checks failures={bad}")
sys.exit(0 if bad == 0 else 1)
