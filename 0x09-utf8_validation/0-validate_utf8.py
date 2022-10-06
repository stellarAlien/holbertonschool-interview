#!/usr/bin/env python3
'''
check utf-8 by checking every byte
'''


def validUTF8(data):
    """
    check if data is valid utf-8
    """
    n = 0
    for i in data:
        d = format(i, '#010b')[-8:]
        if n == 0:
            for b in d:
                if b == '0':
                    break
                n += 1
            if n == 0:  # type 0 is considered valid
                continue
            if n == 1 or n > 4:  # starting with 10 is invalid
                return False
        elif not d[0:1] == '10':  # check if next bytes are of type 1
            return False
        n = n - 1
    if n == 0:  # if  n  next bytes are of Type 1 return True
        return True
    else:
        return False
