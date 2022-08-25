#!/usr/bin/python3

"""
Minimum Operations Module
dybamic programming problem
"""


def minOperations(n):
    """minimium operations of copyAll and paste to constuct H*n string"""
    if n < 2:
        return 0
    div, ops_count = 2, 0
    while n > 1:
        if n % div == 0:
            n = n / div
            ops_count = ops_count + div
        else:
            div += 1
    return ops_count
