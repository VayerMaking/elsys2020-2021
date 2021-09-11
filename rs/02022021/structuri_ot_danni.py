class ListNode:
    def __init__(self, value):
        self.value = value
        self.next_elem = None

class List:
    def __init__(self):
        self.head = None

    def add(self, value):
        current = self.head

        if not self.head:
            self.head = ListNode(value)
            return

        while current.next_elem != None:
            current = current.next_elem
        current.next_elem = ListNode(value)



    def __str__(self):
        current = self.head
        elements = []
        while current != None:
            elements.append(str(current.value))
            current = current.next_elem
        return " ".join(elements)

    def reverse(self):
        # TODO
        # counter = 0;
        # while i.next_elem != None:
        # #     print("asdf")
        l1 = self.head
        l2 = self.head.next_elem
        # print("l1: ", l1)
        # print("l2: ", l2)
        # # l2.next_elem = l1
        # # self.head =
        # l1, l2 = l2, l2.next_elem
        # print("l1: ", l1)
        # print("l2: ", l2)
        while l2.next_elem != None:
            l1, l2 = l2, l2.next_elem
        self.head = l2.next_elem



li = List()
li.add(1)
li.add(2)
li.add(3)
li.add(4)
li.add(5)
li.add(6)

print('List: ', li)
assert str(li) == '1 2 3 4 5 6'
li.reverse()
print('Reversed list: ', li)
assert str(li) == '6 5 4 3 2 1'


class TreeNode:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def insert(self, value):
        if self.value:
            if value < self.value:
                if self.left is None:
                    self.left = TreeNode(value)
                else:
                    self.left.insert(value)
            elif value >= self.value:
                if self.right is None:
                    self.right = TreeNode(value)
                else:
                    self.right.insert(value)
        else:
            self.value = value

    def __str__(self, level=0):
        string = "\t" * level + repr(self.value) + "\n"
        if self.left:
            string += self.left.__str__(level + 1)
        if self.right:
            string += self.right.__str__(level + 1)
        return string

class BinaryTree:
    def __init__(self):
        self.root = TreeNode(None)

    def insert(self, value):
        self.root.insert(value)

    def __str__(self):
        return str(self.root)

    def min_path(self, value):
        # TODO
        pass


tree = BinaryTree()
tree.insert(5)
tree.insert(6)
tree.insert(3)
tree.insert(4)
tree.insert(9)
tree.insert(7)
tree.insert(13)
tree.insert(1)
tree.insert(6)

print()
print('Tree: ')
print(tree)

assert 0 == tree.min_path(5)
assert 1 == tree.min_path(6)
assert 1 == tree.min_path(3)
assert 3 == tree.min_path(13)
