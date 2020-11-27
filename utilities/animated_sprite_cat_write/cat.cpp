#include<fstream>
#include<iostream>

using namespace std;

/*
 *******ALGORITHM******
 Open the file (Input argument)
 Read sprite size and number of frames meta data from the sprite file
 iterate through each of the next bytes in the file and read them
 **********************
*/

int
main (int argc, char *argv[])
{
  if (argc == 2)
    {
      string path = argv[1];
      ifstream file (path);
      uint8_t x;
      int side_x,side_y,nof,i = 0; //nof = number of frames
      file.read((char*)&side_x,sizeof(int));
      file.read((char*)&side_y,sizeof(int));
      file.read((char*)&nof,sizeof(int));
      cout<<"Contents of this "<<side_x<<"x"<<side_y<<" sprite file with "<<nof<<" frames:\n";
      while (true)
	{
	  file.read ((char *) &x, sizeof (x));
	  if(file.eof())
		  break;
	  i++;
	  cout<<(int)x<<" ";
	  if(i%side_x == 0)	cout<<endl;
	}

      if(i != side_x*side_y*nof){
	      cout<<"This sprite file is incomplete. Coordinate "<< i%side_x
		      <<" "<<i/side_x<<" was the last written.\n";
      }
    }
  else
    cout << "Enter one argument - The name of the sprite file!\n";
}
