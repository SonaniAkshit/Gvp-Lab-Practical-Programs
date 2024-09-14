import java.util.*;

class stringsort
{
		public static void main(String args[])
		{
			int i;
			if (args.length == 0) 
			{
				System.out.println("Please provide some integers as command-line arguments.");
				return;
			}
			String[] str = new String[args.length];
			
			System.out.println("\nInputed Elements:");
			for (i = 0; i < str.length; i++) 
			{
				str[i] = args[i];
				System.out.print(" "+str[i]);

			}
			Arrays.sort(str);
			System.out.println("\nSorted Array:");
			for (i = 0; i < str.length; i++) 
			{
				System.out.print(" "+str[i]);
			}
		}
}