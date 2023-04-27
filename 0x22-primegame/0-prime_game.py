#!/usr/bin/python3
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


def remaining_primes(n):
    primes = []
    for i in range(2, n + 1):
        if is_prime(i):
            primes.append(i)
    return primes


def isWinner(x, nums):
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        maria_turn = True
        primes = remaining_primes(n)

        while len(primes) > 0:
            prime_to_remove = primes.pop(0)
            primes = [p for p in primes if p % prime_to_remove != 0]

            if maria_turn:
                maria_turn = False
            else:
                maria_turn = True

        if maria_turn:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif maria_wins < ben_wins:
        return "Ben"
    else:
        return None
