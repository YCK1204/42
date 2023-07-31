import sys
import hashlib

string1 = sys.argv[1]
result1 = hashlib.sha256(string1.encode()).hexdigest()
print(result1)