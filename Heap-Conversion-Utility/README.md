## Heap Conversion Utility

### Overview
This program implements a utility for converting an array of integers into a max heap and subsequently converting it into a min heap. It utilizes the heap data structure to efficiently perform these operations.

### Features
- **Max Heap Creation**: Converts the input array into a max heap.
- **Min Heap Conversion**: Converts the max heap into a min heap.
- **File Input**: Reads the input array from a file for easy testing with custom data sets.
- **Dynamic Array Size**: The size of the array can be adjusted dynamically as per requirements.

### Usage
1. **Compile**: Compile the program using any C++ compiler. For example:
   ```bash
   g++ -o heap_conversion heap_conversion.cpp
   ```
2. **Run**: Execute the compiled binary. Ensure the input file path is provided as a command-line argument. For example:
   ```bash
   ./heap_conversion data.txt
   ```
   Replace `data.txt` with the path to your input file.

### Input File Format
- The input file should contain a list of integers separated by spaces or new lines.

### Example
Suppose we have an input file named `data.txt` with the following contents:
```
8 7 6 5 4 3 2 1
```
Running the program with this input file will produce the following output:
```
Max Heap: 8 7 6 5 4 3 2 1
Min Heap: 1 2 3 5 4 8 6 7
```

### Notes
- Ensure the input file exists and is accessible by the program.
- This program is designed for educational purposes and can be further extended or optimized as needed.
