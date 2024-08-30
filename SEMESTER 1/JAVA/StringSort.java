/*import java.util.*;

class StringSort 
{
    public static void main(String args[]) 
	{
        if (args.length == 0) 
		{
            System.out.println("Please provide some integers as command-line arguments.");
            return;
        }

        for (int i = 0; i < args.length - 1; i++) 
		{
            for (int j = 0; j < args.length - 1 - i; j++) 
			{
                if (args[j].compareTo(args[j + 1]) > 0) 
				{
                    String temp = args[j];
                    args[j] = args[j + 1];
                    args[j + 1] = temp;
                }
            }
        }
        System.out.println("Sorted Strings:");
        for (String str : args) 
		{
            System.out.println(str);
        }
    }
}*/
import java.util.*;

class StringSort
{
		public static void main(String args[])
		{
			if (args.length == 0) 
			{
				System.out.println("Please provide some integers as command-line arguments.");
				return;
			}
			String[] str = new String[args.length];
			
			System.out.println("\nInputed Elements:");
			for (int i = 0; i < str.length; i++) 
			{
				str[i] = args[i];
				System.out.print(" "+str[i]);

			}
			Arrays.sort(str);
			System.out.println("\nSorted Array:");
			for (int i = 0; i < str.length; i++) 
			{
				System.out.print(" "+str[i]);
			}
		}
}