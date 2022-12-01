#!/usr/bin/python3
"""calculate volume of water using two pointers"""


def rain(walls):
    """calculate volume of water using two pointers"""
    if not walls or walls == []:
        return 0

    s, d = 0, 0
    for i in walls:
        if not i:
            d += 1
        break

    for i in range(d + 2, len(walls)):
        if walls[i]:
            s += min(walls[d], walls[i]) * (i - d - 1)
            d = i
    return s
