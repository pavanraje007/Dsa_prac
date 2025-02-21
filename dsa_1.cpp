class TelephoneBook:
    def __init__(self, name, tel_no):
        self.name = name
        self.tel_no = tel_no

# Quadratic Probing insertion
def Insertion_QuadProbing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone number: "))
        hashValue = t % 10  # Hash function
        j = 1
        while hashtable[hashValue] is not None:  # Handle collision
            hashValue = (hashValue + (j * j)) % 10
            j += 1
        hashtable[hashValue] = TelephoneBook(n, t)
    return hashtable

# Double Hashing insertion
def Insertion_DoubleHashing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone number: "))
        hashValue = (t % 9 + 7 - (t % 7)) % 10  # First hash
        j = 1
        while hashtable[hashValue] is not None:  # Handle collision
            hashValue = (t % 9 + j * (7 - (t % 7))) % 10  # Second hash
            j += 1
        hashtable[hashValue] = TelephoneBook(n, t)
    return hashtable

# Display hash table for Quadratic Probing
def Display_QP(hash1):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash1):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

# Display hash table for Double Hashing
def Display_DH(hash2):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash2):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

# Search in both hash tables
def Search(hash1, hash2):
    n = input("Enter name to search: ")
    found = False

    # Search in Quadratic Probing hash table
    for i, obj in enumerate(hash1):
        if obj is not None and obj.name == n:
            print("\nFound in Hashtable-1 (Quadratic Probing)!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            found = True
            break

    # Search in Double Hashing hash table
    for i, obj in enumerate(hash2):
        if obj is not None and obj.name == n:
            print("\nFound in Hashtable-2 (Double Hashing)!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            found = True
            break

    if not found:
        print("\nNot found in either hash table!")

# Main function
def main():
    # Initialize hash tables
    hash1 = [None for _ in range(10)]
    hash2 = [None for _ in range(10)]

    print("-------------------------------")
    print("    Telephone Book Application")
    while True:
        print("-------------------------------")
        print("\t1. Insert Value")
        print("\t2. Display")
        print("\t3. Search")
        print("\t4. Exit")
        print("-------------------------------")
        try:
            ch = int(input("Enter choice: "))
            if ch == 1:
                print("\nSelect collision resolution method:")
                print("\t1. Quadratic Probing")
                print("\t2. Double Hashing")
                c = int(input("Enter choice: "))
                if c == 1:
                    hash1 = Insertion_QuadProbing()
                elif c == 2:
                    hash2 = Insertion_DoubleHashing()
                else:
                    print("Invalid choice!")
            elif ch == 2:
                print("\t1. Display Quadratic Probing Table")
                print("\t2. Display Double Hashing Table")
                c1 = int(input("Enter choice: "))
                if c1 == 1:
                    Display_QP(hash1)
                elif c1 == 2:
                    Display_DH(hash2)
                else:
                    print("Invalid choice!")
            elif ch == 3:
                Search(hash1, hash2)
            elif ch == 4:
                print("Exiting program...")
                break
            else:
                print("Invalid choice!")
        except ValueError:
            print("Invalid input! Please enter a number.")
        except EOFError:
            print("No input detected. Exiting program...")
            break

# Run the program
if __name__ == "__main__":
main()
