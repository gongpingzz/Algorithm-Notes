def func(n):
    arr = []
    for i in range(n):
        arr.append(input())
    dict1 = {}
    for item in arr:
        data1 = item.split('.')[0]
        data2 = item.split('.')[1]
        if data1 in dict1.keys():
            dict2 = dict1[data1]
            if data2 in dict2.keys():
                dict2[data2] += 1
            elif int(data2) < int(list(dict2)[0]):
                dict2 = {data2:1}
        else:
            dict1[data1] = {data2:1}
    count = 0
    for k, v in dict1.items():
        count += list(v.values())[0]
    print(count)
    
func(5)
