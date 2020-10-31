fin = open("input.txt", "r")
fout = open("output.txt", "w")

ar = list(map(int,fin.read().split()))
n1 = int(ar[0])
n2 = int(ar[1])

ctr = 0
ans = ""
if(n1==0 and n2!=0):
    fout.write("IMPOSSIBLE\n")

elif(n2==0):
    fout.write('0\n')
else:
    while(n1<n2):
        ans+=str(n1)+" "
        n1*=2
        ctr+=1

    fout.write(str(ctr+1)+"\n")
    ans+="0"
    fout.write(ans+"\n")