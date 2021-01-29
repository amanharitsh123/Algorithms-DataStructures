
def leap(year):
    if year%400==0:
        return True
    elif year%100 == 0:
        return False
    elif year%4 == 0:
        return True
    else:
        return False


weeks = {0:'Sunday', 1:'Monday', 2:'Tuesday', 3:'Wednesday', 4:'Thursday', 5:'Friday', 6:'Saturday'}

dm = {4:30,6:30,11:30,9:30}
for x in range(1,13):
    if x not in dm:
        dm[x] = 31

ans = 0
wday = 6
offset = 0
for year in range(1901,2001):
    for month in range(1,13):
        day = 0
        t = month
        month = month-1
        if month == 0:
            month = 12 
        if month == 2:
            day = 29 if leap(year) else 28
        else:
            day = dm[month]
        wday += day%7
        wday = wday%7
        if wday == 0:
            ans += 1

print(ans) 



