'''
Write a Python program to store second year percentage of
students in array. Write function for sorting array of 
floating point numbers in ascending order using
a)	Insertion sort
b)	Shell Sort and display top five scores

'''


def InsertionSort(a):
    for i in range(1, len(a)):
        key = a[i]

        j = i-1
        while j >= 0 and key > a[j]:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = key


def ShellSort(a):
    n = len(a)
    gap = n//2

    while gap > 1:
        for i in range(gap, n):

            temp = a[i]
            j = i
            while j >= gap and a[j-gap] < temp:
                a[j] = a[j-gap]
                j -= gap

            a[j] = temp
        gap //= 2


score = []
while True:
    num = input("Input score: ")
    try:
        num = float(num)
    except:
        break
    score.append(num)

print("Choose which sort to use :- ")
print("1) Insertion Sort")
print("2) Shell Sort")

option = int(input("?"))

if (option == 1):
    InsertionSort(score)
    print("Top 5 score are", score[:5])
elif (option == 2):
    ShellSort(score)
    print("Top 5 score are", score[:5])
else:
    print("Invalid Input")
