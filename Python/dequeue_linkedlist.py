# author: Ahmed Hani


class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None

class Dequeue:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head

    def is_empty(self):
        return self.__head is None

    def add_first(self, data):
        if self.is_empty():
            self.__head = Node(data)

            self.__head.next = None
            self.__head.prev = None
        else:
            new_node = Node(data)

            new_node.next = self.__head
            new_node.prev = None

            self.__head = new_node

    def add_last(self, data):
        if self.is_empty():
            self.__head = Node(data)

            self.__head.next = None
            self.__head.prev = None
        else:
            new_node = Node(data)
            temp = self.__head
            prev = None

            while temp is not None:
                prev = temp
                temp = temp.next

            new_node.prev = prev
            new_node.next = None
            prev.next = new_node

    def insert(self, i, data):
        if i == 0:
            self.add_first(data)
        elif i == self.__len__() - 1:
            self.add_last(data)
        elif i >= self.__len__():
            print("Index out of bounding")
        else:
            index = 1
            temp = self.__head

            while temp.next is not None:
                if index == i:
                    new_node = Node(data)
                    current_node = temp
                    next_node = current_node.next

                    next_node.prev = new_node
                    new_node.next = next_node
                    new_node.prev = current_node
                    current_node.next = new_node
                    break
                else:
                    index += 1
                    temp = temp.next

    def remove_first(self):
        if self.is_empty():
            print("Dequeue is Empty!")

            return -1
        else:
            if self.__head.next is not None:
                new_head = self.__head.next
                new_head.prev = None
                self.__head = new_head
            else:
                self.__head = None

    def remove_last(self):
        if self.is_empty():
            print("Dequeue is empty!")
        else:
            temp = self.__head

            while temp.next is not None:
                temp = temp.next

            temp.prev.next = None
            del temp

    def front(self):
        return self.__head.data

    def last(self):
        temp = self.__head

        while temp.next is not None:
            temp = temp.next

        return temp.data

    def print(self):
        if self.is_empty():
            print("Dequeue is Empty!")
        else:
            print(self.__head.data)
            temp = self.__head.next

            while temp is not None:
                print(temp.data)
                temp = temp.next

    def __len__(self):
        if self.is_empty():
            print("Dequeue is Empty!")

            return -1
        else:
            counter = 1
            temp = self.__head

            while temp.next is not None:
                counter += 1
                temp = temp.next

        return counter


if __name__ == '__main__':
    dequeue = Dequeue()

    dequeue.add_last(2)
    dequeue.add_last(4)
    dequeue.add_last(5)
    dequeue.add_first(1)
    dequeue.add_first(6)
    dequeue.insert(3, 7)

    dequeue.print()