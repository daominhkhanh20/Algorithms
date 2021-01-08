
class solution(object):
    def countWay(self,n,mem=dict()):
        if n<0:
            return 0
        elif n==0 or n==1:
            return 1
        
        if mem.get(n,0)==0:
            mem[n]=self.countWay(n-1,mem)+self.countWay(n-2,mem)
        
        return mem.get(n)


if __name__=="__main__":
    n=int(input())
    slu=solution()
    print(slu.countWay(n))