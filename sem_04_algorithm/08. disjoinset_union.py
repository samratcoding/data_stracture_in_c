class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))  # each element own parent
        self.rank = [0] * n            #  the rank is 0 for all elements

    def find(self, u):
        if u != self.parent[u]:
            # Path compression
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return  # They are already in the same set

        # Union by rank
        if self.rank[root_u] > self.rank[root_v]:
            self.parent[root_v] = root_u
        elif self.rank[root_u] < self.rank[root_v]:
            self.parent[root_u] = root_v
        else:
            self.parent[root_v] = root_u
            self.rank[root_u] += 1  # Increase the rank of the new root

    def print_parents(self):
        for i in range(len(self.parent)):
            print(f'Parent of {i} is: {self.parent[i]}')

# Example usage
if __name__ == "__main__":
    n = 5  # Number of elements
    ds = DisjointSet(n)

    # Perform some union operations
    ds.union(0, 2)
    ds.union(4, 2)
    ds.union(3, 1)

    # Find operations
    print("Find(4):", ds.find(4))  # Output: 0
    print("Find(3):", ds.find(3))  # Output: 1

    # Print the parent array for visualization
    ds.print_parents()
