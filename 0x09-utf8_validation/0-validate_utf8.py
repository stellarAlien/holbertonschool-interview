#!/usr/bin/python3
"""
0-validate_utf8
"""


def validUTF8(data):
    """
    check if data is valid utf-8
    """
    count = 0
    for c in data:
            if count == 0:
                if (c >> 5) == 0b110:
                    count = 1
                elif (c >> 4) == 0b1110:
                    count = 2
                elif (c >> 3) == 0b11110:
                    count = 3
                elif (c >> 7):
                    return False
            else:
                if (c >> 6) != 0b10:
                    return False
                count -= 1
    return count == 0


if __name__ == "__main__":
    validate_utf8 = __import__('0-validate_utf8').validUTF8
