import java.util.Scanner;
class switch_demo
{
	public static void main(String ar[])
	{
		int A[][],B[][],C[][],rows,cols;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter no of rows");
		rows=sc.nextInt();
		System.out.println("enter no of cols");
		cols=sc.nextInt();
		A=new int[rows][cols];
		B=new int[rows][cols];
		C=new int[rows][cols];
		System.out.println("enter the ellements of Array A");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				A[i][j]=sc.nextInt();
			}
		}
		
		System.out.println("enter the ellements of Array B");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				B[i][j]=sc.nextInt();
			}
		}
		
		System.out.println("Addition of A & B");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				C[i][j]=B[i][j]+A[i][j];
			}
		}
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				System.out.print(C[i][j] + "\t");
			}
			System.out.println();
		}	
	}
}