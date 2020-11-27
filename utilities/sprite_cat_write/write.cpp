#include<fstream>
#include<iostream>

using namespace std;

int
main (int argc, char *argv[])
{
  if (argc == 2)
    {
      string path = argv[1];
      ofstream file (path);
      cout << "Enter the x dimension of the sprite map: ";
      int side_x;
      cin >> side_x;
      cout << "Enter the y dimension of the sprite map: ";
      int side_y;
      cin >> side_y;
      int choice;
      cout <<
	"Enter the means by which to fill your sprite map - \n1) Enter each pixel manually\n2) Fill with blacks\n3) Fill with whites\n";
      cin >> choice;
      uint8_t val;
      file.write((char*)&side_x,sizeof(int));
      file.write((char*)&side_y,sizeof(int));
      switch (choice)
	{
	case 1:

	  cout << "Enter the mono saturation values for each of those " <<
	    side_x * side_y << " pixels:\n";
	  for (int i = 0; i < side_x * side_y; i++)
	    {
	      cin >> choice;
	      val = static_cast < uint8_t > (choice);
	      file.write ((char *) &val, 1);
	    }
	  break;
	case 2:
	  val = 0;
	  for (int i = 0; i < side_x * side_y; i++)
	    file.write ((char *) &val, 1);
	  cout << "Successfuly filled with blacks\n";
	  break;
	case 3:
	  val = 255;
	  for (int i = 0; i < side_x * side_y; i++)
	    file.write ((char *) &val, 1);
	  cout << "Successfuly filled with whites\n";
	}
      file.close();
    }
  else
    cout << "Enter an argument - The name of the file to be edited\n";
}
