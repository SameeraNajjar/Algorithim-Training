def create_adjacency_matrix(num_nodes, edges):
    adjacency_matrix = [[0] * num_nodes for _ in range(num_nodes)]
    for edge in edges:
        adjacency_matrix[edge[0]][edge[1]] = edge[2]  # Assigning the cost from node i to node j
    return adjacency_matrix

def transpose(matrix):
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

def matrix_difference(matrix1, matrix2):
    diff_sum = 0
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            diff_sum += abs(matrix1[i][j] - matrix2[i][j])
    return diff_sum


def reduce_matrix(matrix):
    transposed = transpose(matrix)
    reduced = [[0] * len(matrix) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            reduced[i][j] = matrix[i][j] - transposed[i][j]
    return reduced


# Example usage
num_nodes = int(input("Enter the number of nodes: "))
edges = []
print("Enter the cost from each node (i to j):")
for i in range(num_nodes):
    for j in range(num_nodes):
        cost = int(input(f"Cost from node {i} to node {j}: "))
        edges.append((i, j, cost))

adjacency_matrix = create_adjacency_matrix(num_nodes, edges)
reduced_matrix = reduce_matrix(adjacency_matrix)
sum_of_differences = matrix_difference(adjacency_matrix, reduced_matrix)

print("\nOriginal Adjacency Matrix:")
for row in adjacency_matrix:
    print(row)

print("\nReduced Adjacency Matrix:")
for row in reduced_matrix:
    print(row)

print("\nSum of Differences:", sum_of_differences)
