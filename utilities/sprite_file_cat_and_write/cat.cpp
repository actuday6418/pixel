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
      int side_x,side_y,i = 0;
      file.read((char*)&side_x,sizeof(int));
      file.read((char*)&side_y,sizeof(int));
      cout<<"Contents of this "<<side_x<<"x"<<side_y<<" sprite file:\n";
      while (true)
	{
	  file.read ((char *) &x, sizeof (x));
	  if(file.eof())
		  break;
	  i++;
	  cout<<(int)x<<" ";
	  if(i%side_x == 0)	cout<<endl;
	}
      if(i != side_x*side_y)	cout<<"This sprite file is incomplete ";
    }
  else
    cout << "Enter one argument - The name of the sprite file!\n";
}
