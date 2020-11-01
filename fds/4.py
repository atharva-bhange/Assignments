'''
Atharva Nitin Bhange
SE A 08
a)	Write a Python program to store names and mobile numbers of your friends in sorted order on names. 
Search your friend from list using binary search (recursive and non- recursive). 
Insert friend if not present in phonebook
b)	Write a Python program to store names and mobile numbers of your friends in sorted order on names. 
Search your friend from list using Fibonacci search. 
Insert friend if not present in phonebook. 

'''


def BinarySearchRecursive(phonebook, low, high, name):
    if high < low:
        return False
    mid = low + ((high-low)//2)
    if name == phonebook[mid][0]:
        return True
    elif name < phonebook[mid][0]:
        return BinarySearchRecursive(phonebook, low, mid-1, name)
    else:
        return BinarySearchRecursive(phonebook, mid+1, high, name)


def BinarySearchIterative(phonebook, low, high, name):
    while low <= high:
        mid = low + ((high-low)//2)
        if name == phonebook[mid][0]:
            return True
        elif name < phonebook[mid][0]:
            high = mid-1
        else:
            low = mid+1
    return False


def FibonacciSearch(phonebook, name):
    M2 = 0
    M1 = 1
    M = M1 + M2
    n = len(phonebook)
    while M < n:
        M2 = M1
        M1 = M
        M = M1 + M2

    offset = -1

    while M > 1:

        i = min(M2+offset, n-1)

        if phonebook[i][0] < name:
            M = M1
            M1 = M2
            M2 = M - M1
            offset = i
        elif phonebook[i][0] > name:
            M = M2
            M1 = M1 - M2
            M2 = M - M1
        else:
            return True
    # Last elements as M1 can be 1 we are comming out of while loop at M1 == 1 and
    # that exact element is the element we are trying to find
    if(M1 and phonebook[offset+1] == name):
        return True

    return False


phonebook = [('alan', '9945737658'),
             ('jake', '9945737658'),
             ('john', '9945737658'),
             ('monty', '9945737658'),
             ('simon', '9945737658'),
             ('zack', '9945737658')]

search_name = input("Name of friend you want to search: ")
phone_number = input("Phone number of friend: ")

print("Choose how to search: ")
print("1) Binary Search recursively.")
print("2) Binary Search non-recursively.")
print("3) Fibonacci search.")
option = int(input())

if option == 1:
    if BinarySearchRecursive(phonebook, 0, len(phonebook), search_name):
        print(search_name, "is found in", phonebook)
    else:
        print("Friend not found in phonebook.")
        print("Adding to phonebook.")
        phonebook.append((search_name, phone_number))
        phonebook.sort(key=lambda x: x[0])
        print("Phonebook now is ", phonebook)
elif option == 2:
    if BinarySearchIterative(phonebook, 0, len(phonebook), search_name):
        print(search_name, "is found in", phonebook)
    else:
        print("Friend not found in phonebook.")
        print("Adding to phonebook.")
        phonebook.append((search_name, phone_number))
        phonebook.sort(key=lambda x: x[0])
        print("Phonebook now is ", phonebook)
elif option == 3:
    if FibonacciSearch(phonebook, search_name):
        print(search_name, "is found in", phonebook)
    else:
        print("Friend not found in phonebook.")
        print("Adding to phonebook.")
        phonebook.append((search_name, phone_number))
        phonebook.sort(key=lambda x: x[0])
        print("Phonebook now is ", phonebook)
else:
    print('Invalid Input')
