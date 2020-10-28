#include<fstream>
#include<iostream>

using namespace std;

int
main (int argc, char *argv[])
{
  if (argc == 2)
    {
      string path = argv[1];
      ifstream file (path);
      uint8_t x;
      int side,i = 0;
      file.read((char*)&side,sizeof(int));
      cout<<"Contents of this "<<side<<"x"<<side<<" sprite file:\n";
      while (true)
	{
	  file.read ((char *) &x, sizeof (x));
	  if(file.eof())
		  break;
	  i++;
	  cout<<(int)x<<" ";
	  if(i%side == 0)	cout<<endl;
	}
      if(i != side*side)	cout<<"This sprite file is incomplete ";
    }
  else
    cout << "Enter one argument - The name of the sprite file!\n";
}
