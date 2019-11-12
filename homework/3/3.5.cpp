#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
#include <fstream>
 
#define MAX_SIZE 250000
 
struct MinHeapNode {
    std::string element;
    int i;
 
    void swap(MinHeapNode& oth) {
        std::swap(i, oth.i);
        element.swap(oth.element);
    }
};
 
void swap(MinHeapNode* x, MinHeapNode* y);
 
class MinHeap {
    MinHeapNode* harr;
    int heap_size;
public:
    MinHeap(MinHeapNode a[], int size);
    void MinHeapify(int);
    int left(int i) {
        return (i << 1) | 1;
    }
    int right(int i) {
        return (i << 1) + 2;
    }
    MinHeapNode getMin() {
        return harr[0];
    }
    void replaceMin(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }
    void eraseMin() {
        harr[0].swap(harr[heap_size - 1]);
        --heap_size;
        MinHeapify(0);
    }
};
 
MinHeap::MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}
 
void MinHeap::MinHeapify(int i) {
    while (true) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l].element < harr[i].element) {
            smallest = l;
        }
        if (r < heap_size && harr[r].element < harr[smallest].element) {
            smallest = r;
        }
        if (smallest != i) {
            harr[i].swap(harr[smallest]);
            i = smallest;
        } else {
            return;
        }
    }
}
 
void mergeFiles(const std::string& output_file, const int number_of_files)
{
    std::ifstream in[number_of_files];
    std::ofstream out(output_file);
    for (int i = 0; i < number_of_files; i++) {
        in[i].open(std::to_string(i));
        in[i].tie(nullptr);
    }
    MinHeapNode harr[number_of_files];
    int i;
    for (i = 0; i < number_of_files; i++) {
        if (!std::getline(in[i], harr[i].element))
            break;
        harr[i].i = i;
    }
    MinHeap hp(harr, i);
    int count = 0;
    while (count != i) {
        MinHeapNode root = hp.getMin();
        out << root.element << '\n';
 
        if (!std::getline(in[root.i], root.element)) {
            hp.eraseMin();
            count++;
        } else {
            hp.replaceMin(root);
        }
    }
    for (int i = 0; i < number_of_files; i++) {
        in[i].close();
    }
    out.close();
}
 
int createInitialRuns(const std::string& input_file) {
    std::ifstream in(input_file);
    in.tie(nullptr);
    std::string buffer;
    std::vector<std::string> buffer_str;
    bool more_input = true;
    int i, gen_size = 0, next_output_file = 0;
    while (more_input) {
        if (gen_size >= MAX_SIZE) {
            buffer_str.push_back(buffer);
            gen_size = buffer.length();
        }
        while (gen_size < MAX_SIZE) {
            if (!std::getline(in, buffer)) {
                more_input = false;
                break;
            }
            gen_size += buffer.length();
            if (gen_size > MAX_SIZE)
                break;
            buffer_str.push_back(buffer);
        }
        std::sort(buffer_str.begin(), buffer_str.end());
        std::ofstream out(std::to_string(next_output_file));
        for (int j = 0; j < buffer_str.size(); j++) {
            out << buffer_str[j];
            if (j != i - 1)
                out << '\n';
        }
        next_output_file++;
        buffer_str.clear();
        out.close();
    }
    in.close();
    return next_output_file;
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";
    mergeFiles(output_file, createInitialRuns(input_file));
    return 0;
}