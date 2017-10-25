# author: Ahmed Hani


class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head

    def is_empty(self):
        return self.__head is None

    def enqueue(self, data):
        if self.is_empty():
            self.__head = Node(data)
        else:
            temp = self.__head

            while temp.next is not None:
                temp = temp.next

            temp.next = Node(data)

    def front(self):
        if self.is_empty():
            print("Stack is Empty!")

            return -1
        else:
            return self.__head.data

    def dequeue(self):
        if self.is_empty():
            print("Queue is Empty!")

            return -1
        else:
            front_value = self.__head.data

            if self.__head.next is not None:
                new_head = self.__head.next
                del self.__head
                self.__head = new_head
            else:
                self.__head = None

            return front_value

    def __len__(self):
        if self.is_empty():
            print("Queue is Empty!")

            return -1
        else:
            counter = 1
            temp = self.__head

            while temp.next is not None:
                counter += 1
                temp = temp.next

        return counter

if __name__ == '__main__':
    queue = Queue()

    queue.enqueue(1)
    queue.enqueue(3)
    queue.enqueue(5)

    print(queue.dequeue())
    print(queue.dequeue())
    print(queue.dequeue())

    queue.enqueue(3)
    queue.enqueue(5)

    print(queue.dequeue())

