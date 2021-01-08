# https://leetcode.com/problems/target-sum/
def countways(s, l):
    temp, sums = 0, 0
    for i in l:
        sums += i

    # Algorithms
    # example [1,2,3,4,5]  s=3
    # assume, we find a sample such that 1-2+3-4+5
    # a subset positive is [1,3,5], a subset negative is [2,4]
    # sum(P): sum all element in subset positive
    # sum(N): sum all element in subset negative
    # sum(P)-sum(N)=s  ==> sum(P)-sum(N)+sum(P)+sum(N)=s+sum(P)+sum(N)=s+sum(list)
    # ==> 2*sum(P)=s+sum(list) ==> if s+sum(list) is old return 0

    if s > sums or -s < -sums or (s+sums) % 2 == 1:
        return 0

    a = int((s+sums)/2+1)
    dp = [0]*a
    dp[0] = 1
    for i in l:
        k = len(dp)-1
        while k >= i:
            # number of ways to attain S =number of ways to attain S without k
            # + number of ways to attain S-V with V
            dp[k] += dp[k-i]
            k -= 1

    return dp[len(dp)-1]


if __name__ == "__main__":
    l = list(map(int, input().split(' ')))
    s = int(input())

    a = countways(s, l)
    print(a)
