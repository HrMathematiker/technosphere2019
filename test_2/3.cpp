#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 
  
struct Node { 
    int count; 
    Node* left; 
    Node* right; 
}; 
  
Node* makeNewNode() 
{ 
    Node* temp = new Node; 
    temp->count = 1; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
   
void insertElement(int num, Node* root, int& ans) 
{ 
    for (int i = 31; i >= 0; i--) { 
        int a = (num & (1 << i)); 
        if (a != 0) { 
            if (root->left != NULL) 
                ans += root->left->count; 
            if (root->right != NULL) { 
                root = root->right; 
                root->count += 1; 
            } 
            else { 
                Node* temp = makeNewNode(); 
                root->right = temp; 
                root = root->right; 
            } 
        } 
        else { 
            if (root->left != NULL) { 
                root = root->left; 
                root->count++; 
            } 
            else { 
                Node* temp = makeNewNode(); 
                root->left = temp; 
                root = root->left; 
            } 
        } 
    } 
} 

int getInvCount(std::vector<int> arr) 
{ 
    Node* head = makeNewNode(); 
    int ans = 0; 
    for (int i = arr.size() - 1; i >= 0; i--) { 
        insertElement(arr[i], head, ans); 
    } 
    return ans; 
} 

int main() {
    int N, input, min = 0;
    std::cin >> N;
    std::vector<int> input_vector;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if (min > input)
            min = input;
        input_vector.push_back(input);
    }
    for (int i = 0; i < N; i++)
        input_vector[i] += std::abs(min - 1);
    std::cout << getInvCount(input_vector) << '\n';
    return 0;
}