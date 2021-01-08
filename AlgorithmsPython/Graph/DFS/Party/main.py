#https://www.hackerearth.com/fr/practice/machine-learning/machine-learning-algorithms/beginners-tutorial-on-xgboost-parameter-tuning-r/practice-problems/algorithm/d-count-the-numbers/submissions/
t=int(input())
while t>0:
	n=int(input())
	list_person=[int(x)-1 for x in input().split()]
	result=[None]*n
	for i in range(n):
		if result[i] is None:
			next_person=list_person[i]
			count=1
			dfs=[i,next_person]
			while i!=next_person:
				dfs.append(list_person[next_person])
				next_person=list_person[next_person]
				count+=1

			for i in dfs:
				result[i]=str(count)
	print(" ".join(result))
	t-=1