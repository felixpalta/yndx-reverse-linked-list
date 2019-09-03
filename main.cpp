#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* node) {
    if (node) {

        ListNode * oldPrev = node;
        ListNode * oldNext = node->next;
        node->next = nullptr;

        while (oldNext) {
            node = oldNext;
            oldNext = node->next;
            node->next = oldPrev;
            oldPrev = node;
        }
    }
    return node;
}

ListNode *vecToList(const std::vector<int> & v) {
    ListNode * head = nullptr;
    ListNode * node = nullptr;
    for (auto & val : v) {
        ListNode * newNode =new ListNode(val);
        if (node) {
            node->next = newNode;
            node = node->next;
        } else {
            node = newNode;
            head = node;
        }
    }
    return head;
}

std::vector<int> ListToVec(ListNode * node) {
    std::vector<int> ret;
    while (node) {
        ret.push_back(node->val);
        node = node->next;
    }
    return ret;
}

std::string printList(ListNode * node) {
    std::ostringstream oss;
    oss << "[ ";
    while (node) {
        oss << node->val << " ";
        node = node->next;
    }
    oss << "]\n";
    return oss.str();
}

std::vector<int> TestCases[] = {
    {}, {},
    {1}, {1},
    {1, 2}, {2, 1},
    {1, 2, 3}, {3, 2, 1},
    {3, 2, 1}, {1, 2, 3},
    {1, 2, 3, 4, 7, 99, 0 , 0, 0, 0, 12}, {12, 0, 0, 0, 0, 99, 7, 4, 3, 2, 1}
};

void TestReverse() {
    for (int i = 0; i < sizeof(TestCases)/sizeof(TestCases[0]); i += 2) {
        ListNode * input = vecToList(TestCases[i]);
        auto expected = TestCases[i+1];
        auto result = reverseList(input);
        if (expected != ListToVec(result)) {
            std::cout << "TEST FAILED at i=" << i << std::endl
                     << "Input: " << printList(vecToList(TestCases[i]))
                     << "Expected: " << printList(vecToList(expected))
                     << "Result: " << printList(result);
            return;
        }
    }
    std::cout << "SUCCESS!\n" ;
}

int main()
{
    TestReverse();
    return 0;
}
