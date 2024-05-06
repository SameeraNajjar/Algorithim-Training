/**
 * 
 * @param {*} graph 
 * @returns the array of all possible topological orders
 */
function topologicalSort(graph) {
  const visited = new Set(); // Keep track of visited nodes
  const stack = []; // Stack to hold nodes with no outgoing edges
  const result = []; // Array to hold all possible topological orders
  
  // DFS helper function to visit each node and its neighbors
  function dfs(node) {
    visited.add(node); // Mark the current node as visited
    
    for (let neighbor of graph[node]) { // For each neighbor of the current node
      if (!visited.has(neighbor)) { // If the neighbor has not been visited
        dfs(neighbor); // Recursively visit the neighbor
      }
    }
    
    stack.push(node); // Push the current node to the stack once all its neighbors have been visited
  }
  
  // Backtracking function to generate all possible topological orders
  function backtrack() {
    if (stack.length === Object.keys(graph).length) { // If the stack contains all nodes in the graph
      result.push([...stack].reverse()); // Add a copy of the current topological order to the result array
    } else {
      for (let node of Object.keys(graph)) { // For each node in the graph
        if (!visited.has(Number(node))) { // If the node has not been visited
          const allNeighborsVisited = graph[node].every((neighbor) =>
            visited.has(neighbor) // Check if all neighbors of the node have been visited
          );
          if (allNeighborsVisited) { // If all neighbors of the node have been visited
            dfs(Number(node)); // Visit the node and its neighbors
            backtrack(); // Recursively backtrack to generate more topological orders
            visited.delete(stack.pop()); // Remove the current node from the stack and mark it as unvisited
          }
        }
      }
    }
  }
  
  backtrack(); // Generate all possible topological orders
  
  return result; // Return the array of all possible topological orders
}

// Example usage with numbers instead of characters
const graph = {
  1: [3, 4],
  2: [4, 5],
  3: [5],
  4: [5],
  5: []
};

const sorted = topologicalSort(graph);
console.log(sorted);
