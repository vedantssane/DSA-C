#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNewNode(int value);
struct Node* insert(struct Node *root, int value);
struct Node* search(struct Node *root, int key);
struct Node* minValueNode(struct Node *node);
struct Node* deleteNode(struct Node *root, int key);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);

void main() {

    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n------ Binary Search Tree ADT ------\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("INSERTED SUCCESSFULLY!!!\n");
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if(search(root, value))
                    printf("Found\n");
                else
                    printf("Not Found\n");

                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("DELETED SUCCESSFULLY!!!\n");
                break;

            case 4:
                printf("INORDER FOR GIVEN IS :\n");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("PREORDER FOR GIVEN IS :\n");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("POSTORDER FOR GIVEN IS :\n");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Thanks for choosing US!!");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}


struct Node * createNewNode(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode -> data = value;
    newNode->left = NULL;
    newNode->right=NULL;

    return newNode;
}

struct Node *insert(struct Node *root,int value) {
    if(root==NULL) {
        return createNewNode(value);
    }

    if(value<root->data) {
        root->left = insert(root->left, value);
    }

    else if (value>root->data) {
        root->right = insert (root->right , value);
    }

    return root;
}

struct Node* search(struct Node *root, int key) {

    if(root == NULL || root->data == key) {
        return root; 
    }

    if(key < root->data) {
        return search(root->left, key); 
    }

    return search(root->right, key);
}

struct Node* minValueNode(struct Node *node) {

    struct Node *current = node;
        
        while(current && current->left != NULL) {
            current = current->left;
        }
        
    return current;

}

struct Node* deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

