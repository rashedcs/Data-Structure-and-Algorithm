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
