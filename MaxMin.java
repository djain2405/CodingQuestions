class MinMax
{
	int min;
	int max;
	
	MinMax(int min, int max)
	{
		this.min = min;
		this.max = max;
	}
}
public class MaxMin {

	static MinMax findMinMax(int[] arr)
	{
		MinMax result = findMinMaxRecur(arr, 0, arr.length-1);
		return result;
	}
	
	static MinMax findMinMaxRecur(int[] arr, int i, int j)
	{
		if(i > j)
			return null;
		if(i == j)
			return new MinMax(arr[i], arr[i]);
		else
		{
			MinMax left = findMinMaxRecur(arr, i, (i+j)/2);
			MinMax right = findMinMaxRecur(arr, (i+j)/2+1, j);
			if(left == null)
				return right;
			else if (right == null)
				return left;
			else
				return new MinMax(Math.min(left.min, right.min), Math.max(left.max, right.max));
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int arr[] = {4, 3, 5, 1, 2, 6, 9, 2, 10, 11, 12};
		MinMax result = findMinMax(arr);
		System.out.println(result.min + " & " + result.max);

	}

}
