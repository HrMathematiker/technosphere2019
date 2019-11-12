#include <bits/stdc++.h>
#include <fstream>
 
#define MAX_SIZE 246000
 
struct MinHeapNode {
    std::string element;
    int i;
};
   
void swap(MinHeapNode* x, MinHeapNode* y);
 
class MinHeap {
    MinHeapNode* harr;
    int heap_size;    
    public:  
        MinHeap(MinHeapNode a[], int size);
        void MinHeapify(int);
        int left(int i) {
            return (2 * i + 1);
        }
        int right(int i) {
            return (2 * i + 2);
        }
        MinHeapNode getMin() {  
            return harr[0];
        }
        void replaceMin(MinHeapNode x) {
            harr[0] = x;
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
 
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element.compare(harr[i].element) < 0)
        smallest = l;
    if (r < heap_size && harr[r].element.compare(harr[smallest].element) < 0)
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
void swap(MinHeapNode* x, MinHeapNode* y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}
 
void mergeFiles(std::string output_file, int number_of_files)
{
    std::ifstream in[number_of_files];
    std::ofstream out(output_file);
    for (int i = 0; i < number_of_files; i++)
        in[i].open(std::to_string(i));
    MinHeapNode harr[number_of_files];
    int i;
    for (i = 0; i < number_of_files; i++) {
        if (!std::getline(in[i],harr[i].element))
            break;
        harr[i].i = i;
    }
    MinHeap hp(harr, i);
    int count = 0;
    while (count != i)  {
        MinHeapNode root = hp.getMin();
        out << root.element << '\n';
   
        if (!std::getline(in[root.i], root.element)) {
            root.element = INT_MAX;
            count++;
        }
        hp.replaceMin(root);
    }
    for (int i = 0; i < number_of_files; i++)
        in[i].close();
    out.close();
}
 
int createInitialRuns(std::string input_file) {
    std::ifstream in(input_file);
    std::string buffer;
    std::vector<std::string> buffer_str;
    bool more_input = true;
    int i, gen_size = 0, next_output_file = 0;
    while (more_input) {
        if (gen_size >= MAX_SIZE) {
            buffer_str.push_back(buffer);
            gen_size = 0;
            gen_size += buffer.length();
        }
        while(gen_size < MAX_SIZE) {
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
                out << std::endl;
        }
        next_output_file++;
        buffer_str.clear();
        out.close();
    }
    in.close();
    return next_output_file;
}
 
int main() {
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";
    mergeFiles(output_file, createInitialRuns(input_file));  
    return 0;
}