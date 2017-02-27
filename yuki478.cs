using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationSharp
{
	class Program
	{
		static void Print(List<int> content)
		{
			int n = content.Count();
			for (int i = 0; i < n-1; i++) Console.Write("{0} ", content[i]);
			Console.WriteLine(content[n - 1]);
		}
		static void Main(string[] args)
		{
			int n, k;
			string[] s =Console.ReadLine().Split(' ');
			n = int.Parse(s[0]);    k = int.Parse(s[1]);
			int use = n - k - 2;
			List<int> ret=new List<int>();
			if (use > 0)
			{
				if (use % 2 == 0) ret = new List<int> { 0, 2, 1 };
				else ret = new List<int> { 1, 0, 2 };
				use--;
				int i = 3;
				while (use>0)
				{
					int diff = ret[i - 1] - ret[i - 2];
					if (Math.Abs(diff) == 2)
					{
						ret.Add(ret[i - 1] + (diff > 0 ? -1 : 1));
					}
					else
					{
						ret.Add(ret[i - 1] + (diff > 0 ? -2 : 2));
					}
					use--;	i++;
				}
				for (; i < n; i++)
				{
					ret.Add(2 * ret[i - 1] - ret[i - 2]);
				}
				Print(ret);
			}
			else
			{
				for (int i = 1; i <= n; i++) ret.Add(i);
				Print(ret);
			}
		}
	}
}
