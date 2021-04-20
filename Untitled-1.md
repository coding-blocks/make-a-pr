import java.util.Scanner;

public class queencombo_2D {
	static Scanner scn = new Scanner(System.in);
	static int count=0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = scn.nextInt();
		QueensCombination2D(new boolean[n][n], 0, 0, 0, n, "");
		System.out.println();
		System.out.println(count);
	}
	public static void QueensCombination2D(boolean[][] board, int row, int col, int qpsf, int tq, String ans) {
		if (qpsf == tq) {
			System.out.print(ans+" ");
			count++;
			return;
		}
		if (col == board[0].length) {
			row++;
			col = 0;
		}
		if (row == board.length) {
			return;
		}
		// yes case
		if (isItSafeToPlaceQueen(board, row, col)) {
			board[row][col] = true;
			QueensCombination2D(board, row, col + 1, qpsf + 1, tq, ans+ "{" + (row+1) + "-" + (col+1) + "} ");
			board[row][col] = false;
		}
		// no case
		QueensCombination2D(board, row, col + 1, qpsf, tq, ans);
	}
	public static boolean isItSafeToPlaceQueen(boolean[][] board, int row, int col) {
		// vertically up
		int r = row - 1;
		int c = col;
		while (r >= 0) {
			if (board[r][c]) {
				return false;
			}
			r--;
		}
		r = row;
		c = col - 1;
		// horizontal
		while (c >= 0) {
			if (board[r][c]) {
				return false;
			}
			c--;
		}
		// diagonally left
		r = row - 1;
		c = col - 1;
		while (r >= 0 && c >= 0) {
			if (board[r][c]) {
				return false;
			}
			r--;
			c--;
		}
		// diagonally right
		r = row - 1;
		c = col + 1;
		while (r >= 0 && c < board[0].length) {
			if (board[r][c]) {
				return false;
			}
			r--;
			c++;
		}
		return true;

	}

}
