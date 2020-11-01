'''
Atharva Nitin Bhange
SE A 08
Write a Python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a)	Selection Sort
b)	Bubble sort and display top five scores.

'''


def BubbleSort(a):
    n = len(a)
    for i in range(n-1):
        for j in range(n-i-1):
            if a[j] < a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]


def SelectionSort(a):
    n = len(a)
    for i in range(n):
        mid = i
        for j in range(i+1, n):
            if (a[j] > a[mid]):
                mid = j
        a[i], a[mid] = a[mid], a[i]


score = []
while True:
    num = input("Input score: ")
    try:
        num = float(num)
    except:
        break
    score.append(num)

print("Choose which sort to use :- ")
print("1) Selection Sort")
print("2) Bubble Sort")

option = int(input("?"))

if (option == 1):
    SelectionSort(score)
    print("Top 5 score are", score[:5])
elif (option == 2):
    BubbleSort(score)
    print("Top 5 score are", score[:5])
else:
    print("Invalid Input")
