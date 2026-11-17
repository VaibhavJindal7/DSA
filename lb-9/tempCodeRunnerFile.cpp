#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void createBST(TreeNode* node,int arr[]){
    for(int i=1;i<7;i++){
        TreeNode* newNode = new TreeNode(arr[i]);
        TreeNode* current = node;
        while(true){
            if(arr[i]<current->val){
                if(current->left==nullptr){
                    current->left=newNode;
                    break;
                }
                else{
                    current=current->left;
                }
            }
            else{
                if(current->right==nullptr){
                    current->right=newNode;
                    break;
                }
                else{
                    current=current->right;
                }
            }
        }
    }
}
void BST(TreeNode* head, int arr[], int &idx){
    if(head==nullptr){
        return;
    }
    BST(head->left,arr,idx);
    arr[idx++]=head->val;
    BST(head->right,arr,idx);
}

int main(){
   int arr[] = {5, 3, 8, 1, 4, 7, 9};
   TreeNode* head = new TreeNode(arr[0]);
   int idx=0;
   createBST(head,arr);
   BST(head,arr,idx);
   cout << "The elements of the BST in sorted order are: ";
   for(int i=0;i<7;i++){
       cout << arr[i] << " ";
   }
   cout << endl;
}
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;   

    int mid = left + (right - left) / 2;  

    mergeSort(arr, left, mid);      
    mergeSort(arr, mid + 1, right);  
    merge(arr, left, mid, right);    
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];   
    int i = low - 1;         

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;                  
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;       

    int pi = partition(arr, low, high);   

    quickSort(arr, low, pi - 1);          
    quickSort(arr, pi + 1, high);        
}