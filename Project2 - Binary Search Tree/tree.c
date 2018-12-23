//
// Created by Salek.
//

#include "tree.h"

node_t *createNode(int item) {
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int addNode(node_t *node, node_t *newNode, char side) {
    if (node == NULL || (side != 'L' && side != 'R'))
        return -1;
    if (side == 'L') {
        node->left = newNode;
    } else {
        node->right = newNode;
    }
    return 0;
}

int findHeight(node_t *root) {
    if (root == NULL)
        return 0;
    int r, l;
    l = findHeight(root->left);
    r = findHeight(root->right);
    return 1 + (l > r ? l : r);
}

int printNode(node_t *node) {
    if(node != NULL) {
        printf("Item: %d\n", node->item);
        if (node->left != NULL)
            printf("Left: %d\n", node->left->item);
        else
            printf("Left: (nil)\n");
        if (node->right != NULL)
            printf("Right: %d\n\n", node->right->item);
        else
            printf("Right: (nil)\n\n");
        return 1;
    }
    printf("NULL Node!");
    return 0;
}

int printItem(node_t *node) {
    if(node != NULL) {
        printf("%d ", node->item);
        return 1;
    }
    printf("NULL Node!");
    return 0;
}

void printTree_preOrder(node_t *root) {
    if (root == NULL)
        return;
    printItem(root);
    printTree_preOrder(root->left);
    printTree_preOrder(root->right);
}

void printTree_inOrder(node_t *root) {
    if (root == NULL)
        return;
    printTree_inOrder(root->left);
    printItem(root);
    printTree_inOrder(root->right);
}

void printTree_postOrder(node_t *root) {
    if (root == NULL)
        return;
    printTree_postOrder(root->left);
    printTree_postOrder(root->right);
    printItem(root);
}

void printLayers(node_t *root, int size) {
    queue_t *queue = createNewQueue(size);
    enqueue(queue, root);
    int q1 = 1, q2 = 0;
    while (queue->size != 0) {
        if (q1 == 0) { //floor cleared
            printf("\n");
            int tmp = q1;
            q1 = q2;
            q2 = tmp;
        }
        node_t *node = dequeue(queue);
        printItem(node);
        if (node->left != NULL) {
            enqueue(queue, node->left);
            q2++;
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
            q2++;
        }
        q1--;
    }
    printf("\n");
}
