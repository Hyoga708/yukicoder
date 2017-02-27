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
			int n = int.Parse(Console.ReadLine());
			decimal[] d = new decimal[n];
			String[] s = Console.ReadLine().Split(' ');
			decimal big = 0;
			for(int i = 0; i < n; i++)
			{
				d[i] = decimal.Parse(s[i]);
				big = Math.Max(d[i], big);
			}
			
			s = Console.ReadLine().Split(' ');
			decimal x = decimal.Parse(s[0]), y = decimal.Parse(s[1]);
			x = Math.Abs(x);	y = Math.Abs(y);
			//答えが0のとき
			if (x + y == 0)
			{
				Console.WriteLine(0);
				return;
			}
			//答えが1のとき
			int check = Array.IndexOf(d, Math.Max(x, y));
			if (check != -1)
			{
				Console.WriteLine(1);
				return;
			}
			else Console.WriteLine(Math.Max((int)Math.Ceiling(Math.Max(x, y) / big), 2));
		}
	}
}
