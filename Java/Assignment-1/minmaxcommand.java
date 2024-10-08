import java.util.*;

class minmaxcommand 
{
    public static void main(String args[]) 
	{
		
        if (args.length == 0) 
		{
            System.out.println("Please provide some integers as command-line arguments.");
            return;
        }

		int i,j,temp;
        int[] a = new int[args.length];
        int max = Integer.MIN_VALUE,min = Integer.MAX_VALUE; 

		System.out.println("\nInputed Elements:");
        for (i = 0; i < a.length; i++) 
		{
            a[i] = Integer.parseInt(args[i]);
            System.out.print(" "+a[i]);

            if (a[i] > max) 
			{
                max = a[i];
            }
            if (a[i] < min) 
			{
                min = a[i];
            }
        }
		for (i = 0; i < a.length - 1; i++) 
		{
            for (j = 0; j < a.length - 1 - i; j++) 
			{
                if (a[j] > a[j + 1]) 
				{
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        //Arrays.sort(a);
		
		System.out.println("\nSorted Array:");
        for (i = 0; i < a.length; i++) 
		{
            System.out.print(" "+a[i]);
		}
		
        System.out.println("\nMax Value: " + max);
        System.out.println("\nMin Value: " + min);
    }
}
