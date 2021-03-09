public class StaticQueue {
 
    private Object data[];
    //队列头
    private int front;
    //队列尾
    private int rear;
    //队列大小
    private int size;
 
    public StaticQueue(int size) {
        this.size = size;
        data = new Object[size];
    }
 
    //入队
    public void in(Object value) throws Exception {
        if (rear == size) {
            throw new RuntimeException("队列已满");
        }
        data[rear++] = value;
    }
 
    //出队
    public Object out() throws Exception {
      if(isEmpty()){
          throw  new RuntimeException("空队列异常");
      }
      Object   value=data[front];
      data[front++]=null;
      return  value;
    }
    /**
     * 是否为空队列
     * @return
     */
    public boolean isEmpty(){
        return  front == rear;
    }
    //遍历队列
    public   void  traverse(){
        for (int  i=front; i<rear; i++){
            System.out.println(data[i]);
        }
    }
 
    public static void main(String[] args) throws Exception {
        StaticQueue queue = new StaticQueue(10);
        queue.in(1);
        queue.in("ssfdf");
        queue.in("sdsfsf");
        queue.traverse();
        Object out = queue.out();
        System.out.println("出来的一个数据：  "+out);
        queue.traverse();
    }
}