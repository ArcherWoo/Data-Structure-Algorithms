import java.util.*;

class MyQueue{
	// store elements
	private List<Integer> data;
	// a pointer to indicate the start position
	private int p_start;

	public MyQueue(){
		data = new ArrayList<Integer>();
		p_start = 0;
	}

	public boolean enQueue(int x){
		data.add(x);
		return true;
	}

	public boolean deQueue(){
		if(isEmpty() == true){
			return false;
		}
		p_start++;
		return true;
	}

	public int Front(){
		return data.get(p_start);
	}

	public boolean isEmpty(){
		return p_start >= data.size();
	}

}

public class queue{

	public static void main(String[] args) {
		MyQueue q = new MyQueue();
		q.enQueue(10);
		q.enQueue(20);
		if (q.isEmpty() == false) {
			System.out.println(q.Front());
		}
		q.deQueue();
		if (q.isEmpty() == false) {
			System.out.println(q.Front());
		}
		q.deQueue();
		if (q.isEmpty() == false) {
			System.out.println(q.Front());
		}
	}
}