# author: Ahmed Hani


class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head

    def is_empty(self):
        return self.__head is None

    def add(self, data):
        if self.is_empty():
            self.__head = Node(data)
        else:
            temp = self.__head

            while temp.next is not None:
                temp = temp.next

            temp.next = Node(data)

    def print(self):
        if self.is_empty():
            print("Linked List is Empty!")
        else:
            print(self.__head.data)
            temp = self.__head.next

            while temp is not None:
                print(temp.data)
                temp = temp.next

    def remove_by_index(self, idx):
        if self.is_empty():
            print("Linked List is Empty!")
        else:
            if idx == 0:
                if self.__head.next is not None:
                    new_head = self.__head.next
                    del self.__head
                    self.__head = new_head
                else:
                    self.__head = None

            else:
                idx_counter = 1
                found = False
                temp = self.__head.next
                prev = self.__head

                while temp is not None:
                    if idx_counter == idx:
                        found = True
                        next_node = temp.next
                        prev.next = next_node
                        del temp

                        break
                    else:
                        prev = temp
                        temp = temp.next
                        idx_counter += 1

                if not found:
                    print("Index out of range!")

    def remove_by_value(self, value):
        found = False

        if self.__head.data == value:
            found = True

            new_head = self.__head.next
            del self.__head
            self.__head = new_head
        else:
            temp = self.__head.next
            prev = self.__head

            while temp is not None:
                if temp.data == value:
                    found = True
                    next_node = temp.next
                    prev.next = next_node
                    del temp

                    break
                else:
                    prev = temp
                    temp = temp.next

        if not found:
            print("Value isn't existed in the LinkedList!")

    def __len__(self):
        counter = 0

        if self.is_empty():
            return counter
        else:
            counter = 1
            temp = self.__head.next

            while temp is not None:
                temp = temp.next
                counter += 1

        return counter

    def __reversed__(self, method='iterative'):
        final_node = None

        if method is 'iterative':
            temp = self.__head
            prev = final_node

            while temp is not None:
                next_node = temp.next
                temp.next = prev
                prev = temp
                temp = next_node

            self.__head = prev

        if method is 'recursive':
            self.__reverse_aux(self.__head, final_node)

    def __reverse_aux(self, current_node, previous_node):
        if current_node.next is None:
            self.__head = current_node
            current_node.next = previous_node

            return

        next_node = current_node.next
        current_node.next = previous_node

        self.__reverse_aux(next_node, current_node)

    def clear(self):
        temp = self.__head.next

        while temp is not None:
            next_node = temp.next
            del temp
            temp = next_node

        self.__head = None

    def concate(self, ll2):
        temp = self.__head.next
        prev = None

        while temp is not None:
            prev = temp
            temp = temp.next

        final_node = prev
        final_node.next = ll2.get_head()

    def concate_sorted(self, ll2):
        first_head = self.__head
        second_head = ll2.get_head()

        if first_head.data <= second_head.data:
            new_head = first_head
            it_first, it_second = new_head.next, second_head
        else:
            new_head = second_head
            it_first, it_second = first_head, new_head.next

        self.__head = new_head
        last = new_head

        while it_first is not None or it_second is not None:
            if it_first is None:
                last.next = it_second
                last = last.next
                it_second = it_second.next
            elif it_second is None:
                last.next = it_first
                last = last.next
                it_first = it_first.next

            elif it_first.data <= it_second.data:
                last.next = it_first
                last = last.next

                it_first = it_first.next
            else:
                last.next = it_second
                last = last.next
                it_second = it_second.next

if __name__ == '__main__':
    ll = LinkedList()
