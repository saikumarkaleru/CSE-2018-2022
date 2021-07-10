public class Solution {
    public boolean hasCycle(ListNode head) {
       
        ListNode l1=head;
        ListNode l2=head;
        if(head==null)
            return false;
        while(l2!=null && l2.next!=null)
        {
            l1=l1.next;
            l2=l2.next.next;
            if(l1==l2)
            {
                return true;
            }
        }
        return false;
    }
}