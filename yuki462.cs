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
			ulong mod = (ulong)1e9 + 7;
			string[] s = Console.ReadLine().Split(' ');
			int n = int.Parse(s[0]), k = int.Parse(s[1]);
			if (k == 0)
			{
				//答えはn!
				ulong ret = 1;
				for (int i = 2; i <= n; i++) ret = (ret * (ulong)i) % mod;
				Console.WriteLine(ret);
			}
			else
			{
				s = Console.ReadLine().Split(' ');
				int count = 0;
				ulong[] a = new ulong[k+2];
				for (int i = 0; i < k; i++)	a[i + 1] = ulong.Parse(s[i]);
				a[0] = 0;	a[k + 1] = (1UL << n) - 1;
				Array.Sort(a);
				ulong ret = 1;
				//a[0]=0は確定->ret=1
				for(int i = 1; i < k+2; i++)
				{
					if ((a[i] & a[i - 1]) != a[i - 1])
					{
						ret = 0;
						break;
					}
					ulong diff = a[i] ^ a[i - 1];
					ulong cnt = 0;
					for(int j = 0; j < n; j++)
					{
						if ((diff >> j) % 2L == 1L) cnt++;
					}
					for (ulong j = 2; j <= cnt; j++) ret = (ret * j) % mod;
				}
				Console.WriteLine(ret);
			}
		}
	}
}
