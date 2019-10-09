package lecture21_august1;

import java.util.Arrays;
import java.util.Scanner;

public class DynamicPrograming_LongestSubSequences {
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s1 = scn.next();
		String s2 = scn.next();
		int[][] storage = new int[s1.length() + 1][s2.length() + 1];
		for (int i = 0; i < s1.length(); i++) {
			Arrays.fill(storage[i], -1);
		}
//		int [][] storage=new int[s1.length()+1][s2.length()+1];
//		LCS(s1, s2);
//		System.out.println(LCSTD(s1, s2, storage));
//		EditDistanceTD(s1, s2, storage);
//		WildCardMatchingBU("abda", "a?d");

	}

	public static int LCS(String s1, String s2) {
		if (s1.length() == 0 || s2.length() == 0) {
			return 0;
		}
		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);
		int ans = 0;
		if (ch1 == ch2) {
			ans = LCS(ros1, ros2) + 1;
		} else {
			int o1 = LCS(s1, ros2);
			int o2 = LCS(ros1, s2);
			ans = Math.max(o1, o2);
		}
		return ans;
	}

	public static int LCSTD(String s1, String s2, int[][] storage) {
		if (s1.length() == 0 || s2.length() == 0) {
			return 0;
		}

		if (storage[s1.length()][s2.length()] != -1) {
			return storage[s1.length()][s2.length()];
		}
		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);
		int ans = 0;
		if (ch1 == ch2) {
			ans = LCSTD(ros1, ros2, storage) + 1;
		} else {
			int o1 = LCSTD(s1, ros2, storage);
			int o2 = LCSTD(ros1, s2, storage);
			ans = Math.max(o1, o2);
//			storage[s1.length()][s2.length()] = ans;
		}
		storage[s1.length()][s2.length()] = ans;
		return ans;
	}

	public static int LCSBU(String s1, String s2) {
		int[][] storage = new int[s1.length() + 1][s2.length() + 1];
		for (int row = s1.length() - 1; row >= 0; row--) {
			for (int col = s2.length() - 1; col >= 0; col--) {
				if (s1.charAt(row) == s2.charAt(col)) {
					storage[row][col] = storage[row + 1][col + 1] + 1;
				} else {
					int o1 = storage[row][col + 1];
					int o2 = storage[row + 1][col];
					storage[row][col] = Math.max(o1, o2);
				}
			}
		}
		return storage[0][0];
	}

	public static int EditDistance(String s1, String s2) {
		if (s1.length() == 0 || s2.length() == 0) {
			return Math.max(s1.length(), s2.length());
		}
		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);
		int ans = 0;
		if (ch1 == ch2) {
			ans = EditDistance(ros1, ros2);
		} else {
			int i = EditDistance(ros1, s2);
			int d = EditDistance(s1, ros2);
			int r = EditDistance(ros1, ros2);
			ans = Math.min(i, Math.min(d, r)) + 1;
		}
		return ans;
	}

	public static int EditDistanceTD(String s1, String s2, int[][] storage) {
		if (s1.length() == 0 || s2.length() == 0) {
			return Math.max(s1.length(), s2.length());
		}
		if (storage[s1.length()][s2.length()] != -1) {
			return storage[s1.length()][s2.length()];
		}
		char ch1 = s1.charAt(0);
		char ch2 = s2.charAt(0);
		String ros1 = s1.substring(1);
		String ros2 = s2.substring(1);
		int ans = 0;
		if (ch1 == ch2) {
			ans = EditDistanceTD(ros1, ros2, storage);
		} else {
			int i = EditDistanceTD(ros1, s2, storage);
			int d = EditDistanceTD(s1, ros2, storage);
			int r = EditDistanceTD(ros1, ros2, storage);
			ans = Math.min(i, Math.min(d, r)) + 1;
		}
		storage[s1.length()][s2.length()] = ans;
		return ans;
	}

	public static int EditDistanceBU(String s1, String s2) {
		int[][] storage = new int[s1.length() + 1][s2.length() + 1];
		for (int row = s1.length(); row >= 0; row--) {
			for (int col = s2.length(); col >= 0; col--) {
				if (row == s1.length()) {
					storage[row][col] = s2.length() - col;
					continue;
				}
				if (col == s2.length()) {
					storage[row][col] = s1.length() - row;
					continue;
				}
				if (s1.charAt(row) == s2.charAt(col)) {
					storage[row][col] = storage[row + 1][col + 1];
				} else {
					int i = storage[row + 1][col];
					int d = storage[row][col + 1];
					int r = storage[row + 1][col + 1];
					storage[row][col] = Math.min(i, Math.min(d, r)) + 1;
				}
			}
		}
		return storage[0][0];
	}

	public static int MCMTD(int[] arr, int si, int ei, int[][] storage) {
		if (ei - si == 1) {
			return 0;
		}
		if (storage[si][ei] != 0) {
			return storage[si][ei];
		}
		int min = Integer.MAX_VALUE;
		for (int k = si + 1; k <= ei - 1; k++) {
			int fp = MCMTD(arr, si, k, storage);
			int sp = MCMTD(arr, k, ei, storage);
			int sw = arr[si] * arr[k] * arr[ei];
			int total = fp + sp + sw;
			if (total < min) {
				min = total;
			}
		}
		storage[si][ei] = min;
		return min;
	}

	public static int MCMBU(int[] arr) {
		int n = arr.length;
		int[][] storage = new int[n][n];
		for (int slide = 1; slide <= n - 2; slide++) {
			for (int si = 0; si <= n - slide - 2; si++) {
				int ei = si + slide + 1;
				// copy
				int min = Integer.MAX_VALUE;
				for (int k = si + 1; k <= ei - 1; k++) {
					int fp = storage[si][k];
					int sp = storage[k][ei];
					int sw = arr[si] * arr[k] * arr[ei];
					int total = fp + sp + sw;
					if (total < min) {
						min = total;
					}
				}
				storage[si][ei] = min;
				//
			}
		}
		return storage[0][n - 1];
	}

	public static int WineProblem(int[] arr, int si, int ei, int yr) {
		if (si == ei) {
			return arr[si] * yr;
		}

		int start = WineProblem(arr, si + 1, ei, yr);

		int end = WineProblem(arr, si, ei + 1, yr);

		int ans = Math.max(start, end);

		return ans;
	}

	public static int WineProblemTD(int[] arr, int si, int ei, int[][] storage) {
		int yr = arr.length - ei + si;
		if (si == ei) {
			return arr[si] * yr;
		}

		if (storage[si][ei] != 0) {
			return storage[si][ei];
		}

		int start = WineProblemTD(arr, si + 1, ei, storage) + arr[si] * yr;
		int end = WineProblemTD(arr, si, ei - 1, storage) + arr[ei] * yr;

		int ans = Math.max(start, end);
		storage[si][ei] = ans;
		return ans;
	}

	public static int WineProblemBU(int[] wine) {
		int n = wine.length;
		int storage[][] = new int[wine.length][wine.length];
		for (int slide = 0; slide <= n - 1; slide++) {
			for (int si = 0; si <= n - slide - 1; si++) {
				int ei = si + slide;
				int yr = n - ei - si;
				if (si == ei) {
					storage[si][ei] = wine[si] * yr;
					continue;
				}
//				int yr=n-ei-si;
				int start = storage[si + 1][ei] + wine[si] * yr;
				int end = storage[si][ei - 1] + wine[ei] * yr;
				int ans = Math.max(start, end);
				storage[si][ei] = ans;
			}
		}
		return storage[0][n - 1];

	}

	public static boolean WildCardMatchingTD(String src, String pat, int[][] storage) {
//		char ch = src.charAt(0);
//		char chp = pat.charAt(0);
		if (src.length() != 0 && pat.length() == 0) {
			return false;
		}
		if (src.length() == 0 && pat.length() == 0) {
			return true;
		}
		char ch = src.charAt(0);
		char chp = pat.charAt(0);
		String ros = src.substring(1);
		String rop = pat.substring(1);
		boolean result = false;
		if (ch == chp || chp == '?') {
			boolean res = WildCardMatchingTD(ros, rop, storage);
		} else if (chp == '*') {
			boolean blank = WildCardMatchingTD(src, ros, storage);
			boolean multiple = WildCardMatchingTD(rop, pat, storage);
			result = blank || multiple;
		} else {
			result = false;
		}
		storage[src.length()][pat.length()] = result ? 2 : 1;
		return result;
	}

	public static boolean WildCardMatchingBU(String src, String pat) {
		boolean[][] storage = new boolean[src.length() + 1][pat.length() + 1];

		storage[src.length()][pat.length()] = true;
		for (int row = src.length(); row >= 0; row--) {
			for (int col = pat.length(); col >= 0; col--) {
				if (row == src.length()) {
					storage[row][col] = storage[row][col + 1];
				} else {
					storage[row][col] = false;
				}
				char ch = src.charAt(row);
				char chp = pat.charAt(col);
//				String ros = src.substring(1);
//				String rop = pat.substring(1);
				boolean result = false;
				if (ch == chp || chp == '?') {
					boolean res = storage[row + 1][col + 1];
				} else if (chp == '*') {
					boolean blank = storage[row][col + 1];
					boolean multiple = storage[row + 1][col];
					result = blank || multiple;
				} else {
					result = false;
				}
			}
		}
		return storage[0][0];
	}

	public static int Knapsack(int[] p, int[] w, int vidx, int cap) {
		if (vidx == p.length) {
			return 0;
		}
		int inc = 0;
//		int exc = 0;
		if (w[vidx] <= cap)
//			int inc = 0;
			inc = Knapsack(p, w, vidx + 1, cap - w[vidx]) + p[vidx];
		int exc = Knapsack(p, w, vidx + 1, cap);
		return Math.max(inc, exc);

	}

	public static int KnapsackTD(int[] p, int[] w, int vidx, int cap, int[][] storage) {
		if (vidx == p.length) {
			return 0;
		}

		if (storage[vidx][cap] != 0) {
			return storage[vidx][cap];
		}
		int inc = 0;
		int exc = 0;
		if (w[vidx] <= cap) {
//			int inc = 0;
			inc = KnapsackTD(p, w, vidx + 1, cap - w[vidx], storage) + p[vidx];
		}

		exc = KnapsackTD(p, w, vidx + 1, cap, storage);

		return storage[vidx][cap] = Math.max(inc, exc);
	}

	public static int KnapSackBU(int[] p, int[] w, int cap) {
		int storage[][] = new int[p.length][cap + 1];
		for (int row = p.length - 1; row >= 0; row--) {
			for (int col = 0; col <= cap; col++) {
//				if (row == storage.length - 1) {
//					storage[row][col] = 0;
//					continue;
//				}
				int inc = 0;
				if (w[row] <= col) {
					inc = storage[row + 1][col - w[row]];
				}
				int exc = storage[row + 1][col];
				storage[row][col] = Math.max(inc, exc);

			}
		}
		return storage[0][cap];

	}

	public static int Mixtures(int[] arr, int si, int ei) {
		int min = Integer.MAX_VALUE;

		if (si == ei) {
			return 0;
		}
		for (int k = si; k < ei; k++) {
			int fp = Mixtures(arr, si, k);
			int sp = Mixtures(arr, k, ei);
			int sw = colour(arr, si, k) * colour(arr, k + 1, ei);
			int total = fp + sp + sw;
			if (total < min) {
				min = total;
			}
		}
		return min;
	}

	public static int colour(int[] arr, int si, int ei) {
		int sum = 0;
		for (int k = si; k <= ei; k++) {
			sum += arr[k];
		}
		return sum % 100;
	}

	public static int MixturesTD(int[] arr, int si, int ei, int[][] storage) {
		int min = Integer.MIN_VALUE;

		if (si == ei) {
			return 0;
		}
		if (storage[si][ei] != -1) {
			return storage[si][ei];
		}
		for (int k = si; k < ei; k++) {
			int fp = Mixtures(arr, si, k);
			int sp = Mixtures(arr, k, ei);
			int sw = colour(arr, si, k) * colour(arr, k + 1, ei);
			int total = fp + sp + sw;
			if (total < min) {
				min = total;
			}
		}

		storage[si][ei] = min;
		return min;
	}

	public static int MixturesBU(int[] arr) {
		int n = arr.length;
		int[][] storage = new int[n][n];
		for (int slide = 1; slide <= n - 1; slide++) {
			for (int si = 0; si <= n - slide - 1; si++) {
				int ei = si + slide;
				// copy
				int min = Integer.MAX_VALUE;
				for (int k = si + 1; k <= ei - 1; k++) {
					int fp = storage[si][k];
					int sp = storage[k][ei];
					int sw = colour(arr, si, k) * colour(arr, k + 1, ei);
					int total = fp + sp + sw;
					if (total < min) {
						min = total;
					}
				}
				storage[si][ei] = min;
				//
			}
		}
		return storage[0][n - 1];
	}

	public static int rodCut(int[] arr, int len) {
		int left = 1;
		int right = len - 1;
		int max = arr[len];
		while (left <= right) {
			int fp = rodCut(arr, left);
			int sp = rodCut(arr, right);
			int total = fp + sp;
			if (total > max) {
				max = total;
			}

			left++;
			right--;
		}
		return max;

	}

	public static int rodCutTD(int[] arr, int len, int[] storage) {

		int left = 1;
		int right = len - 1;
		if (storage[len] != 0) {
			return storage[len];
		}
		int max = arr[len];
		while (left <= right) {
			int fp = rodCutTD(arr, left, storage);
			int sp = rodCutTD(arr, right, storage);
			int total = fp + sp;
			if (total > max) {
				max = total;
			}
//			storage[len]=max;

			left++;
			right--;
		}
		storage[len] = max;
		return max;
	}

	public static int rodCuttingBU(int[] arr) {
		int[] strg = new int[arr.length];
		for (int len = 0; len < strg.length; len++) {
			int max = arr[len];
			for (int i = 1, j = len - 1; i <= j; i++, j--) {
				int fp = strg[i];
				int sp = strg[j];
				int total = fp + sp;
				if (total > max)
					max = total;
			}
			strg[len] = max;
		}
		return strg[strg.length - 1];
	}
}
