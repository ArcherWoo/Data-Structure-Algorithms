import java.util.*;

public class BinarySearch{
	
	public static int Binary(int arr[], int data){
		int min = 0;
		int max = arr.length - 1;
		int mid;
		
		while(min <= max){
		
			mid = min + ((max - min) >>> 1);

			if (arr[mid] < data) {
				max = mid - 1;
			}else if (arr[mid] > data) {
				min = mid + 1;
			}else{
				return mid;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		int arr[] = {9,8,7,6,5,4,3,2};
		int data = 6;
		System.out.println(Binary(arr,data));
	}
}