# author: Ahmed Hani


class Node:
    def __init__(self, char='root', parent=None):
        self.char = char
        self.terminal = False
        self.parent = parent
        self.children = {}


class Trie:
    def __init__(self):
        self.__root = Node()

    def add_word(self, word):
        current_node = self.__root

        for ch in word:
            if ch not in current_node.children:
                current_node.children[ch] = Node(ch, current_node)

            current_node = current_node.children[ch]

        current_node.terminal = True

    def search(self, word):
        current_node = self.__root

        for ch in word:
            if ch not in current_node.children:
                return False

            current_node = current_node.children[ch]

        return current_node.terminal

    def remove_word(self, word):
        current_node = self.__root

        for ch in word:
            if ch not in current_node.children:
                print("Word is not existed y3m!")

                return

            current_node = current_node.children[ch]

        if current_node.terminal:
            current_node.terminal = False

            while not current_node.terminal and len(current_node.children) == 0 and current_node.parent != None:
                current_node.parent.children.pop(current_node.char)
                current_node = current_node.parent


if __name__ == '__main__':
    trie = Trie()