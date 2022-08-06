#!/usr/bin/python3
"""
module that contains nut and bolts solution
"""
from typing import List

def canUnlockAll(boxes):
    """_summary_
    Args:
        boxes (_type_): list of lists to check
    Returns:
        _type_: _description_
    """
    if (len(boxes) == 0 or boxes is None):
        return False
    unlocked = []
    for box in boxes[1:]:
        for i in box:
            if (i > (len(boxes) - 1)):
                continue
            elif(boxes[i] and not(i in unlocked)):
                unlocked.append(i)
    if ( len(boxes) - 1 == len(unlocked)):
        return False
    return True
