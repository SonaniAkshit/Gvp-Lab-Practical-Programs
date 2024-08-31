import java.util.Scanner;

public class Utility 
{
    public static long factorial(long value) 
	{
        if (value < 0) 
		{
            throw new IllegalArgumentException("Factorial is not defined for negative numbers.");
        }
        long result = 1;
        for (long i = 2; i <= value; i++) 
		{
            result *= i;
        }
        return result;
    }

    public static boolean isPrime(int value) 
	{
        if (value <= 1) 
		{
            return false;
        }
        for (int i = 2; i <= Math.sqrt(value); i++) 
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
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        long num = scanner.nextLong();

        System.out.println("Factorial of " + num + ": " + factorial(num));
        System.out.println("Is " + num + " prime? " + isPrime((int) num));
        System.out.println("Is " + num + " even? " + isEven(num));
        System.out.println("Is " + num + " odd? " + isOdd(num));
    }
}