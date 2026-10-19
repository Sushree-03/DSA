#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* tail = head;
        int s = 1;

        while (tail->next) {
            tail = tail->next;
            s++;
        }

        k = k % s;
        if (k == 0)
            return head;

        tail->next = head;

        int st = s - k;
        ListNode* newt = tail;

        while (st--) {
            newt = newt->next;
        }

        ListNode* newHead = newt->next;
        newt->next = NULL;

        return newHead;
    }
};

int main() {
    int n, k;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the list elements: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* node = new ListNode(x);

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated list: ";

    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}