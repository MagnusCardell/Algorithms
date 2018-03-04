
class BinaryTree():

    def __init__(self,value):
      self.left = None
      self.right = None
      self.value = value #int value

    def getLeftChild(self):
        return self.left
    def getRightChild(self):
        return self.right
    def setNodeValue(self,value):
        self.value = value
    def getNodeValue(self):
        return self.value

    

def main():
    graph = {'A': ['B', 'C'],
             'B': ['C', 'D'],
             'C': ['D']}

    BinaryTree root()
    
    combine_two_graphs(graph, graph)
    initiateTree()
    print(graph)

main()