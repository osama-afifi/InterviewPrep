# author: Ahmed Hani


class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    def __init__(self, capacity=10):
        self.__capacity = capacity
        self.__bucket = [None] * self.__capacity
        self.__size = 0

    def __setitem__(self, key, value):
        index = self.__hash(key)

        if self.__bucket[index] is None:
            new_node = Node(key, value)
            new_node.next = None

            self.__bucket[index] = new_node
        else:
            current = self.__bucket[index]

            if current.key == key and current.value == value:
                return

            while current.next is not None:
                current = current.next

                if current is not None:
                    if current.key == key and current.value == value:
                        return

            new_node = Node(key, value)
            new_node.next = None

            current.next = new_node

        self.__size += 1

    def __getitem__(self, key):
        index = self.__hash(key)

        if self.__bucket[index] is None:
            raise Exception("Key is not existed")

        current = self.__bucket[index]

        while current is not None and current.key != key:
            current = current.next

        if current is None:
            raise Exception("Key is not existed")
        else:
            return current.value

    def __delitem__(self, key):
        index = self.__hash(key)
        found = False

        if self.__bucket[index] is None:
            raise Exception("Key is not existed")

        head = self.__bucket[index]

        while head is not None and head.key == key:
            found = True

            new_head = head.next
            del head
            head = new_head

            self.__size -= 1

        self.__bucket[index] = head

        current = self.__bucket[index]

        if current is None:
            if not found:
                raise Exception("Key is not existed")

            return

        temp = current.next
        prev = current

        while temp is not None:
            if temp.key == key:
                next_node = temp.next
                prev.next = next_node
                del temp
                temp = next_node
                self.__size -= 1
                found = True
            else:
                prev = temp
                temp = temp.next

        if not found:
            raise Exception("Key is not existed")

    def __len__(self):
        return self.__size

    def get_capacity(self):
        return self.__capacity

    def is_empty(self):
        return self.__size == 0

    def __hash(self, key):
        return hash(key) % self.__capacity

if __name__ == '__main__':
    hashtable = HashTable(5)

    hashtable['ahmed'] = 1
    hashtable['Hani'] = 2
    hashtable['Ibrahim'] = 3
    hashtable['ahmed'] = 4
    hashtable['Alghidani'] = 5
    hashtable['Ibrahim Ibrahim'] = 6

    print(hashtable['Ibrahim'])
    print(hashtable['Hani'])
