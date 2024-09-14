import java.util.*;

public class utility 
{
    public static long factorial(long value) 
	{
		long i;
        long result = 1;
        for (i = 2; i <= value; i++) 
		{
            result *= i;
        }
        return result;
    }
    public static boolean isPrime(int value) 
	{
		int i;
        if (value <= 1) 
		{
            return false;
        }
        for (i = 2; i <= Math.sqrt(value); i++) 
		{
            if (value % i == 0) 
			{
                return false;
            }
        }
        return true;
    }

    public static boolean isEven(long value) 
	{
        return value % 2 == 0;
    }

    public static boolean isOdd(long value)
	{
        return value % 2 != 0;
    }

    public static void main(String[] args) 
	{
		
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        long num = sc.nextLong();
		
		if (num < 0) 
		{
			System.out.println("Enter only positive value.");
		}
		//else if ((num >= 'a' && num <= 'z') || (num >= 'A' && num <= 'Z')) 
		//{
		//	System.out.println("Enter only positive value.");
		//}
		else
		{
			System.out.println("Factorial:"+factorial(num));
			System.out.println("prime: " + isPrime((int) num));
			System.out.println("even: " + isEven(num));
			System.out.println("odd: " + isOdd(num));
		}
    }
}