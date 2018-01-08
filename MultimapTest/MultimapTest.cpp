// multimap::count
#include <iostream>
#include <map>
#include <stdio.h>
int main ()
{
	std::multimap<char,int> mymm;

	mymm.insert(std::make_pair('x',50));
	mymm.insert(std::make_pair('y',100));
	mymm.insert(std::make_pair('y',150));
	mymm.insert(std::make_pair('y',200));
	mymm.insert(std::make_pair('z',250));
	mymm.insert(std::make_pair('z',300));

	for (char c='x'; c<='z'; c++)
	{
		std::cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
		std::multimap<char,int>::iterator it;
		for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
			std::cout << ' ' << (*it).second;
		std::cout << '\n';
	}

	puts("\nAnother Test!");
	for (char c='x'; c<='z'; c++)
	{
		std::cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
		std::multimap<char,int>::iterator it;
		it = mymm.find(c);
		for(unsigned int i=0; i<mymm.count(c); ++it,++i)
		{
			std::cout << ' ' << it->second;
		}
		std::cout << '\n';
	}

  return 0;
}


//#include <iostream>
//#include <map>
//
//int main ()
//{
//  std::multimap<char,int> mymm;
//
//  mymm.insert (std::make_pair('x',10));
//  mymm.insert (std::make_pair('y',20));
//  mymm.insert (std::make_pair('z',30));
//  mymm.insert (std::make_pair('z',40));
//
//  std::multimap<char,int>::iterator it = mymm.find('x');
//  mymm.erase (it);
////  mymm.erase (mymm.find('z'));
//
//  // print content:
//  std::cout << "elements in mymm:" << '\n';
//  std::cout << "y => " << mymm.find('y')->second << '\n';
//  std::cout << "z => " << mymm.find('z')->second << '\n';
//
//  return 0;
//}
