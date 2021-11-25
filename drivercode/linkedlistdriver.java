import java.util.*;

public class Main {
    
    static class Node{
    int val;
    Node next;
        
    Node () {
    this.next = null; 
   }
    Node(int val) {
    this.val = val; 
    this.next = null; 
   }
}

   public static void main(String[] args) {
        Main obj=new Main();
	    System.out.println("Random array:");
       int[] a=obj.ra(5);
       System.out.println("Converting array to linkedlist");
       Node outputNode=obj.convert(a);
       obj.printList(outputNode);
       System.out.println();
       System.out.println("Inserting Node 777777");
       obj.insertNode(outputNode,777777, 3);
       obj.printList(outputNode);
       System.out.println();
       System.out.println("Deleting Node");
       obj.deleteNode(outputNode,3);
       obj.printList(outputNode);
       System.out.println();
       System.out.println("Deleting kth Node from end");
       obj.deleteKthNodeFromEnd(outputNode,2);
       obj.printList(outputNode);
       System.out.println();
       System.out.println("Reverse list");
       Node root=obj.reverse(outputNode);
       obj.printList(root);
       System.out.println();
       System.out.println("Comparing lists");
       boolean result=obj.areEqual(outputNode,root);
       System.out.println(result);
       System.out.println("Comparing lists");
       result=obj.areEqual(root,root);
       System.out.println(result);
       System.out.println();
       System.out.println("Merge two lists");
       
       System.out.println("List 1");
       int[] x={1,3,5,7};
       Node node1=obj.convert(x);
       obj.printList(node1);
       System.out.println();
       
       System.out.println("List 2");
       int[] y={2,4,6,8};
       Node node2=obj.convert(y);
       obj.printList(node2);
       System.out.println();
       
       System.out.println("Merging...");
       Node finalNode=obj.mergeSortedLists(node1,node2);
       obj.printList(finalNode);
       
	}
    
    public static void printList(Node head){
           while(head!=null)
    {
       System.out.print(head.val+" ");
        head=head.next;
    }
    }
   public int[] ra(int size){
    Random random=new Random();
    int arr[]=new int[size];
    for(int i=0;i<size;i++){
        arr[i]=random.nextInt();
    }
    
    return arr;
}
    
     public Node convert(int[] arr1){
        Node root=new Node(arr1[0]);
        Node current=root;
        for(int i=1;i<arr1.length;i++){
            current.next=new Node(arr1[i]);
            current=current.next;
        }
        return root;
    }
    
    public Node insertNode(Node head, int val, int pos) {
   if (pos < 1 )
        System.out.println("invalid position given");
    if(pos==1)
    {Node tem=new Node(val);
    tem.next=head;
    head=tem;
    return head;
    }
    int cnt=1;
    Node curr=head;
    while(cnt<pos-1)
    {
        curr=curr.next;
        cnt++;  
    }
    Node tem=new Node(val);
    tem.next=curr.next;
    curr.next=tem;
     
  return head; 
}

    Node deleteNode (Node head, int position) {
    if(position<0)return head;
    if(position==1)
        return head.next;
    int pos=1;
    Node curr=head;
    while(pos<position-1)
    {
        curr=curr.next;
        pos++;
    }
    curr.next=curr.next.next;
    
 return head; 
}
    
    public Boolean areEqual(Node head1, Node head2) {
    
    while(head1!=null || head2!=null)
    {
        if(head1.val!=head2.val)
        return false;
     head1=head1.next;
     head2=head2.next;
   }
  return true; 
}
   // K = 1 means delete last node.
    Node deleteKthNodeFromEnd(Node head, int k) {
        int len=0;
        Node temp=head;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
    //int len=list.size(head);
    if(k>len)return head;
    if(k==len)return head.next;
    Node curr=head;
    Node end=head;
    int i=1;
    
    while (i<=k)
    {end=end.next;
     i++;}
    
    while(end.next!=null)
    {
        curr=curr.next;
        end=end.next;
    }
    
    curr.next=curr.next.next;
    
  return head; 
}

// Reverse a linkedlist. 
Node reverse(Node node)  
{  
Node previous = null;  
Node curr = node;  
Node next = null;  

while (curr != null)   
{  
next = curr.next;  
curr.next = previous;  
previous = curr;  
curr = next;  
}  
node = previous;  
return node;  
}  
  
Node  mergeSortedLists(Node  head1, Node  head2) {

    Node result = null;
     
    if (head1 == null)
        return(head2);
    else if (head2 == null)
        return(head1);
 if (head1.val <= head2.val)
    {
        result = head1;
        result.next = mergeSortedLists(head1.next, head2);
    }
    else
    {
        result = head2;
        result.next = mergeSortedLists(head1, head2.next);
    }
    return result;
}

}
