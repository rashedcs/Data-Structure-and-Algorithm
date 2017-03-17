http://k2code.blogspot.in/2012/01/given-integer-array-and-number-x-find.html
http://code.cloudkaksha.org/arrays/to-check-if-an-array-has-pair-of-elements-with-given-sum



import java.util.Scanner;
import java.util.*;
import java.io.*;
import java.util.HashMap;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import java.util.Arrays;


public class codechef 
{

      public static void printPairsUsingTwoPointers(int[] numbers, int k)
      {
       // if(numbers.length < 2)   return;
        Arrays.sort(numbers);
        
        int left = 0; int right = numbers.length -1;
        
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == k)
            {
                System.out.printf("(%d, %d) %n", numbers[left], numbers[right]);
                left = left + 1;
                right = right -1;
                
            }
            else if(sum < k)
            {
                left = left +1;
                
            }
            else if (sum > k)
            {
                right = right -1;
            }
         }
      }
      
      public static void main(String args[]) 
      {
         printPairsUsingTwoPointers( new int[]{4, 4, 8}, 8);
      }
      
}



















public class codechef {

	public static void printSumPairs(int input[], int k)
	{
	    Map<Integer, Integer> pairs = new HashMap<Integer, Integer>();

	    for(int i=0; i<input.length;i++)
	    {
	        if(pairs.containsKey(input[i]))
	            System.out.println(input[i] +", "+ pairs.get(input[i]));
	        else
	            pairs.put(k-input[i], input[i]);
	    }
	}
	
	
	
   public static void main(String[] args) 
   {        
      int []a = {4,6,4};
      printSumPairs(a,8);        
   }




}







