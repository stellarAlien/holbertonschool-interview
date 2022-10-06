#!/usr/bin/python3
"""
0-validate_utf8
"""


def validUTF8(data):
    """
    cehck if data is valid utf-8
    """
    n_bytes = 0
    for num in data:
        byte = format(num, '#010b')[-8:]
        if n_bytes == 0:
            for bit in byte:
                if bit == '0':
                    break
                n_bytes += 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not byte[0:1] == '10':
                return False
        n_bytes -= 1
    return n_bytes == 0


if __name__ == "__main__":
    validate_utf8 = __import__('0-validate_utf8').validUTF8
