import java.util.Scanner;
public class Strings
{
public static void main (String[] args)
{
	String[] StringList;
	int size;
	Scanner scan = new Scanner(System.in);
	System.out.print ("\nHow many integers do you want to sort? ");
	size = scan.nextInt();
	StringList = new String[size];
	System.out.println ("\nEnter the numbers...");
	for (int i = 0; i < size; i++)
		StringList[i] = scan.next();
		Sorting.insertionSort(StringList);
		System.out.println ("\nYour numbers in sorted order...");
	for (int i = 0; i < size; i++)
		System.out.print(StringList[i] + " ");
	System.out.println ();
	scan.close();
	}
}
