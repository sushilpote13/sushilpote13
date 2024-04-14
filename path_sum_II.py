oohho,target,list,element,found,x,k,z=[5,4,8,11,'null',13,4,7,2,'null','null',5,1],2,[],[],False,2,0,0
def check(ans,target):
    global found
    if sum(ans)==target:
        element.append(ans)
        found=True
while True:
    list.append(oohho[0])
    i=1
    try:
        while True :
            for time in range(x):
                if oohho[i]=="null":
                    oohho[i]=0
                element.append(oohho[i])
                i+=1
            x=x+2
            list.append(element)
            element=[]
    except:
        break
try:
    while found==False:
        check([list[0]],target)
        for i in range(2):
            ans=[list[0],list[1][i]]
            check(ans,target)
            for j in range(2):
                if list[2][k]==0:
                    k+=1
                    break
                ans=[list[0],list[1][i],list[2][k]]
                check(ans,target)
                for j in range(2):
                    if list[3][z]==0:
                        z+=1
                        break
                    ans=[list[0],list[1][i],list[2][k],list[3][z]]
                    check(ans,target)
                    z+=1
                k+=1
except:
    if found==False:
        print("not found")
    else:
        print(element)