#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

// 리스트에 새로운 노드 추가
ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

// 리스트의 첫 번째 노드 삭제
void delete_first(ListNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((head)->link == head) {
        free(head);
        head = NULL;
    }
    else {
        ListNode* last = head;
        while (last->link != head)
            last = last->link;

        ListNode* tmp = head;
        head = (head)->link;
        last->link = head;
        free(tmp);
    }
}

// 리스트의 마지막 노드 삭제
void delete_last(ListNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((head)->link == head) {
        free(head);
        head = NULL;
    }
    else {
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current->link != head) {
            prev = current;
            current = current->link;
        }

        prev->link = head;
        free(current);
    }
}

// 리스트 출력
void print_list(ListNode* head) {
    ListNode* current = head;

    if (head != NULL) {
        do {
            printf("%d->", current->data);
            current = current->link;
        } while (current != head);
    }

    printf("\n");
}

int main() {
    ListNode *head = NULL;
    int choice, data;

    do {
        printf("\n***** Menu *****\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(0) Exit\n");
        printf("Enter the menu: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Input a number: ");
            scanf_s("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("Input a number: ");
            scanf_s("%d", &data);
            insert_last(head, data);
            break;
        case 3:
            delete_first(head);
            printf("First node has been deleted.\n");
            break;
        case 4:
            delete_last(head);
            printf("Last node has been deleted.\n");
            break;
        case 5:
            print_list(head);
            break;            
        case 0:
            printf("Exit the program.\n");
            exit(1);
        default:
            printf("Invalid");
            break;
        }
    } while (choice != 0);
    return 0;
}