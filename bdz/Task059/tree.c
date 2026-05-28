#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* create_node(int key) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int key) {
    if(root == NULL) {
        root = create_node(key);
        return root;
    }
    if(key > root->key) {
        if(root->right == NULL) {
            root->right = create_node(key);
        }
        else {
            root->right = insert(root->right, key);
        }
    }
    if(key < root->key) {
        if(root->left == NULL) {
            root->left = create_node(key);
        }
        else {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

Node* search(Node* root, int key) {
    if(root == NULL) return NULL;
    if(root->key == key) return root;
    if(key < root->key) return search(root->left, key);
    if(key > root->key) return search(root->right, key);
}

// Самый малый элемент правой ветви
static Node* min_right(Node* root) {
    if(root == NULL) return root;
    if(root->right == NULL) return root;
    root = root->right;
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int key) {
    if(search(root, key) == NULL) return root; // если такого узла нет - ничего не делать
    if(root == NULL) return NULL;
    
    if(key < root->key) {
        root->left = delete(root->left, key);
    }
    else if(key > root->key) {
        root->right = delete(root->right, key);
    }
    else {
        //Node* del = root; // мы нашли тот узел, который надо удалить
        if(root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        }
        else if(root->right == NULL && root-> left != NULL) {
            Node* left = root->left;
            free(root);
            return left;
        }
        else if(root->right != NULL && root-> left == NULL) {
            Node* right = root->right;
            free(root);
            return right;
        }
        else {
            Node* min_r = min_right(root);
            root->key = min_r->key;
            root->right = delete(root->right, min_r->key);
        }
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void free_tree(Node* root) {
  if(root == NULL) return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
