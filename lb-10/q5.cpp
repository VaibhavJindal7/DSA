#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void serializeHelper(struct TreeNode* root, char* str) {
    if (root == NULL) {
        strcat(str, "#,");
        return;
    }

    char buffer[20];
    sprintf(buffer, "%d,", root->val);
    strcat(str, buffer);
    serializeHelper(root->left, str);
    serializeHelper(root->right, str);
}

char* serialize(struct TreeNode* root) {

    char* str = (char*)malloc(10000 * sizeof(char)); 
    str[0] = '\0'; 
    
    serializeHelper(root, str);
    return str;
}

struct TreeNode* deserializeHelper(char** data) {
    if (**data == '\0') return NULL;

    char* commaPos = strchr(*data, ',');
    if (commaPos == NULL) return NULL; 

    int len = commaPos - *data;

    char token[20];
    strncpy(token, *data, len);
    token[len] = '\0';
    *data = commaPos + 1;

    if (strcmp(token, "#") == 0) {
        return NULL;
    }
    int val = atoi(token);
    struct TreeNode* root = createNode(val);
    root->left = deserializeHelper(data);
    root->right = deserializeHelper(data);

    return root;
}
struct TreeNode* deserialize(char* data) {

    return deserializeHelper(&data);
}

void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("Original Tree (Inorder): ");
    inorder(root);
    printf("\n");

    char* serializedData = serialize(root);
    printf("Serialized String: %s\n", serializedData);

    struct TreeNode* reconstructedTree = deserialize(serializedData);
    
    printf("Reconstructed Tree (Inorder): ");
    inorder(reconstructedTree);
    printf("\n");
    free(serializedData);

    return 0;
}