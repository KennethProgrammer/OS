bytes = open('boot.bin', 'rb').read()
bytes = bytes[ :-16]
open('boot.bin', 'wb').write(bytes)

import os

size = os.path.getsize("kernel.bin")

size = (40*512) - size

bytes2 = [0x0 for _ in range(size)]
open('kernel.bin', 'ab').write(bytearray(bytes2))
