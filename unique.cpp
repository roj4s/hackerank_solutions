#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}


/*
 * Complete the 'condense' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* condense(SinglyLinkedListNode* head) {

    if(!head){
        return head;
    }

    SinglyLinkedListNode* orderedHead = (struct SinglyLinkedListNode*) malloc(sizeof(struct SinglyLinkedListNode));
    orderedHead->data = head->data;
    orderedHead->next = NULL;
    SinglyLinkedListNode* current = head->next;

    while(current){        
        SinglyLinkedListNode* currentOrdered = orderedHead;
        bool insert = true;  

        cout << current->data << "\n";      

        while(currentOrdered->next){
            if(current->data == currentOrdered->data){
                insert = false;
                break;                
            }         
            currentOrdered = currentOrdered->next;
        }

        if(insert){
            SinglyLinkedListNode* newNode = (struct SinglyLinkedListNode*) malloc(sizeof(struct SinglyLinkedListNode));
            newNode->data = current->data;
            newNode->next = NULL;
            currentOrdered->next = newNode;
            
        }
        current = current->next;
    }
    
    return orderedHead;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    SinglyLinkedListNode* result = condense(head->head);

    print_singly_linked_list(result, "\n", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
