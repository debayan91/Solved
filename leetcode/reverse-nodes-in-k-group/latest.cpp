class Solution {
public:
    pair<ListNode*, ListNode*> rev(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return {head, head};
        ListNode* temp = head->next;
        ListNode* prev = head;
        while (temp != nullptr) {
            ListNode* n = temp->next;
            temp->next = prev;
            prev = temp;
            temp = n;
        }
        head->next = nullptr;
        return {prev, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* start;
        ListNode* end;
        ListNode* iter;
        while (temp != NULL) {
            start = temp;
            iter = temp;
            ListNode* last_end;
            if (start != head)
                last_end = end;
            // is there even a k - group ?
            int counter = k - 1;
            while (iter != NULL && counter) {
                iter = iter->next;
                counter--;
            }
            if (!iter) {
                // last node reached
                return head;
            } else {
                end = iter;
                // we have start and end
                if(start == head){
                    ListNode* nex = end->next;
                    end->next = NULL;
                    pair<ListNode*, ListNode*> l = rev(start);
                    head = l.first;
                    l.second->next = nex;
                    end = l.second;
                }else{
                    ListNode* last = last_end;
                    ListNode* nex = end->next;
                    end->next = NULL;
                    pair<ListNode*, ListNode*> l = rev(start);
                    last->next = l.first;
                    l.second->next = nex;
                    end = l.second;
                }
            }
            temp = end->next;
        }
        end->next == NULL;
        return head;
    }
};