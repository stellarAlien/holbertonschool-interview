#!/usr/bin/python3
'''
Given a pile of coins of different values, determine the fewest number of
coins needed to meet a given amount total.
'''


def makeChange(coins, total):
    '''this implementation assumes that the coins list is sorted in
    descending order of value,
    so that we can loop through the list in
    that order and always consider the largest possible coin first.'''
    if total <= 0:
        return 0
    # initialize a list to store the minimum number of coins needed for
    # each total from 0 to the given total
    minCoins = [float('inf')] * (total+1)
    # 0 coins are needed to make a total of 0
    minCoins[0] = 0
    # for each coin in the list
    for coin in coins:
        # for each total from the value of the coin to the given total
        for i in range(coin, total+1):
            # if using the current coin reduces the minimum number of coins
            # needed for this total
            if minCoins[i-coin] + 1 < minCoins[i]:
                # update the minimum number of coins needed for this total
                minCoins[i] = minCoins[i-coin] + 1
    # if the minimum number of coins needed for the given
    # total is still infinite,
    # it means the total cannot be met
    if minCoins[total] == float('inf'):
        return -1
    # otherwise, return the minimum number of coins needed for the given total
    return minCoins[total]
