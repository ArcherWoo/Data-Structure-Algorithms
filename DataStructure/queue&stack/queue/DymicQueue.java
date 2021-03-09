
public class DymicQueue<E> {
    private class Node {
        //链表某个节点的实际值
        public E e;
        //链表某个节点的下一个节点
        public Node next;
 
        public Node(E e, Node next) {
            this.e = e;
            this.next = next;
        }
 
        public Node(E e) {
            this(e, null);
        }
 
        public Node() {
            this(null, null);
        }
        @Override
        public String toString(){
            return e.toString();
        }
    }
 
    //链表的头节点和尾结点
    private Node head, tail;
 
    private int size;
 
    public DymicQueue() {
 
    }
 
    //返回队列的大小
    public int size() {
        return size;
    }
 
    //返回队列是否为空
    public boolean isEmpty() {
        return size == 0;
    }
 
    //插入队列数据
    public void in(E e) {
        if (tail == null) {  //如果队列尾为空说明队列为空
            tail = new Node(e);//将数据给队尾
            head = tail;//对首和队尾一样
        } else {
            tail.next = new Node(e);//新添加的元素放入队列的尾
            tail = tail.next;//更新队列的头部指向新的尾
        }
        size++;
    }
 
    //出队   队列出去一个数据
    public E out() {
        if (this.isEmpty())
            throw new RuntimeException("队列为空");
        //出去的是队列的头部数据。拿到头部数据
        Node res = head;
        head = head.next;
        res.next = null;  
        if (head == null)
            tail = null;
        size--;
        return res.e;
    }
 
    //获取队列的头
    public E getFront() {
        if (this.isEmpty())
            throw new IllegalArgumentException("队列为空，getFront失败。");
        return head.e;
    }
 
    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append("YgzLinkedQueue: head  ");
        Node cur = head;
        while(cur != null) {
            res.append(cur + "->");
            cur = cur.next;
        }
        res.append(" tail");
        return res.toString();
    }
 
    public static void main(String[] args) {
 
        DymicQueue<Object>   dymicQueue=new DymicQueue<>();
        dymicQueue.in(1);
        dymicQueue.in(2);
        dymicQueue.in("嘿嘿");
        dymicQueue.in("哈哈");
        System.out.println(dymicQueue.toString());
        System.out.println(dymicQueue.getFront());
    }
 
}