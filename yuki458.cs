using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationSharp
{
	class Program
	{
		static void Main(string[] args)
		{
			List<int> prime = new List<int>();
			bool[] check = new bool[20000];
			for (int i = 0; i < 20000; i++) check[i] = true;
			check[0] = check[1] = false;
			for(int i = 2; i < 2000; i++)
			{
				if (check[i] == true)
				{
					prime.Add(i);
					for (int j = 2 * i; j < 20000; j += i) check[j] = false;
				}
			}

			int n = int.Parse(Console.ReadLine());
			int[] dp = new int[n + 1];
			dp[0] = 1;
			for(int i = 0; i < prime.Count(); i++)
			{
				if (n < prime[i]) break;
				for(int j = n-prime[i]; j >= 0; j--)
				{
					if (dp[j] == 0) continue;
					dp[j + prime[i]] = Math.Max(dp[j + prime[i]], dp[j] + 1);
				}
			}
			Console.WriteLine(dp[n] - 1);
		}
	}
}
