# author: Ahmed Hani


class Node:
    def __init__(self, data=None):
        self.data = data
        self.parent = None


class MaxHeap:
    def __init__(self, capacity):
        self.__heap_array = [None] * capacity
        self.__size = 0
        self.__capacity = capacity

    def is_empty(self):
        return self.__size == 0

    def get_maxi(self):
        return self.__heap_array[0].data

    def insert(self, data):
        if self.__size == 0:
            if self.__size < self.__capacity:
                self.__heap_array[0] = Node(data)
                self.__size += 1
            else:
                print("Heap is full!")
        else:
            if self.__size < self.__capacity:
                new_node = Node(data)
                parent_idx = int((self.__size - 1) / 2)
                new_node.parent = self.__heap_array[parent_idx]

                self.__heap_array[self.__size] = new_node
                self.__size += 1

                self.__rearrange(self.__size - 1)
            else:
                print("Heap is full!")

    def update(self, i, data):
        self.__heap_array[i].data = data

        self.__rearrange(i)

    def __heapify(self, root=0):
        while True:
            current_max = root
            left = self.get_left_idx(root)
            right = self.get_right_idx(root)

            if left < self.__size and self.__heap_array[left].data > self.__heap_array[current_max].data:
                current_max = left

            if right < self.__size and self.__heap_array[right].data > self.__heap_array[current_max].data:
                current_max = right

            if root != current_max:
                self.__heap_array[current_max], self.__heap_array[root] = self.__heap_array[root], self.__heap_array[
                    current_max]
                self.__heap_array[current_max].parent = self.__heap_array[root].parent
                self.__heap_array[root].parent = self.__heap_array[current_max]

                root = current_max
                continue

            break

    def __rearrange(self, index):
        current_node = self.__heap_array[index]
        parent_node = current_node.parent
        parent_index = int((index - 1) / 2)

        while parent_node is not None and current_node.data > parent_node.data:
            self.__heap_array[parent_index], self.__heap_array[index] = self.__heap_array[index], self.__heap_array[
                parent_index]
            self.__heap_array[parent_index].parent = self.__heap_array[index].parent
            self.__heap_array[index].parent = self.__heap_array[parent_index]

            index, parent_index = parent_index, index

            parent_node = self.__heap_array[index].parent
            current_node = self.__heap_array[index]
            parent_index = int((index - 1) / 2)

    def get_right_node(self, i):
        return self.__heap_array[2 * i + 1]

    def get_left_node(self, i):
        return self.__heap_array[2 * i + 2]

    def get_left_idx(self, i):
        return 2 * i + 2

    def get_right_idx(self, i):
        return 2 * i + 1

    def pop_maximum(self):
        if self.__size == 1:
            value = self.__heap_array[0].data
            self.__heap_array[0] = None
            self.__size = 0

            return value
        else:
            value = self.__heap_array[0].data
            self.__heap_array[0] = self.__heap_array[self.__size - 1]
            self.__size -= 1

            self.__heapify(0)

            return value

    def traverse_in_order(self):
        for i in range(0, self.__size):
            print(self.__heap_array[i].data)


if __name__ == '__main__':
    heap = MaxHeap(10)
    heap.insert(1)
    heap.insert(5)
    heap.insert(9)
    heap.insert(2)
    heap.insert(-1)

    heap.traverse_in_order()
