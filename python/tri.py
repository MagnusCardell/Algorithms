
class TrieNode:
    def __init__(self):
        self.char: str = ""
        self.children = [None] * 26
        self.isLeaf: bool = False
    

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            i = ord(c) - ord("a")
            if(node.children[i] == None):
                node.children[i] = TrieNode()
            node.children[i].char = c 
            node = node.children[i]
        node.isLeaf = True
        return
    
    def search(self, word: str) -> bool:
        node = self.root 
        for c in word:
            i = ord(c) - ord("a")
            if(node.children[i] == None):
                return False
            node = node.children[i]
        return node.isLeaf
    
    def startsWith(self, prefix: str) -> bool:
        node = self.root 
        for c in prefix:
            i = ord(c) - ord("a")
            if(node.children[i] == None):
                return False
            node = node.children[i]
        return True
    
a = Trie()
assert a.root.char == ""
assert a.root.isLeaf == False
a.insert("word")
assert a.root.children[ord("w")-ord("a")] != None

print(a.search("word"))