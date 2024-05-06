import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_huffman_tree(text):
    frequencies = calculate_frequencies(text)
    heap = [Node(char, freq) for char, freq in frequencies.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        new_node = Node(None, left.freq + right.freq)
        new_node.left = left
        new_node.right = right
        heapq.heappush(heap, new_node)

    return heapq.heappop(heap)


def calculate_frequencies(text):
    frequencies = {}
    for char in text:
        frequencies[char] = frequencies.get(char, 0) + 1
    return frequencies


def build_huffman_codes(root, current_code, codes):
    if root is None:
        return

    if root.char is not None:
        codes[root.char] = current_code

    build_huffman_codes(root.left, current_code + "0", codes)
    build_huffman_codes(root.right, current_code + "1", codes)


def encode_text(text, codes):
    encoded = ""
    for char in text:
        encoded += codes[char]
    return encoded


def decode_text(encoded, root):
    decoded = ""
    current_node = root
    for bit in encoded:
        if bit == "0":
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.char is not None:
            decoded += current_node.char
            current_node = root

    return decoded


def build_huffman_codes_and_table(text):
    tree = build_huffman_tree(text)
    codes = {}
    build_huffman_codes(tree, "", codes)
    return codes


def main():
    print("Enter the paragraph to encode:")
    paragraph = input()
    codes = build_huffman_codes_and_table(paragraph)
    print("Huffman codes:")
    print(codes)
    encoded_par = encode_text(paragraph, codes)
    print("Encoded paragraph:", encoded_par)
    print("Enter the string to decode:")
    to_decode = input()
    huffman_tree = build_huffman_tree(paragraph)  # Use the tree generated from original text
    print("Decoded:", decode_text(to_decode, huffman_tree))
    print("Enter the encoded string to decode:")
    encoded_text = input()
    print("Decoded:", decode_text(encoded_text, huffman_tree))
    print(
        "The number of total bits needed to encode the paragraph is:",
        len(encode_text(paragraph, codes))
    )


if __name__ == "__main__":
    main()
