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
	"Enter the means by which to fill your sprite map - \n1) Fill with black and whites\n2) Fill with blacks\n3) Fill with whites\n";
      cin >> choice;
      uint8_t val;
      file.write((char*)&side_x,sizeof(int));
      file.write((char*)&side_y,sizeof(int));
      cout<<"Enter the number of frames: ";
      int nof;
      cin>>nof;
      file.write((char*)&nof,sizeof(int));

      switch (choice)
	{
	case 1:
		val = 1;
	  for(int j=0;j<nof;j++){
		  if(val == 1){
			  val = 255;
		  } else {
			  val = 1;
		  }
	  for (int i = 0; i < side_x * side_y; i++)
	    {
		
	      file.write ((char *) &val, 1);
	    }
	  }
	  cout<<"Succesfully filled with alternating colors\n";
	  break;
	case 2:
	  val = 0;
	  for(int j = 0;j<nof;j++){
	  for (int i = 0; i < side_x * side_y; i++){
	    file.write ((char *) &val, 1);
	  }
	  }
	  cout << "Successfuly filled with blacks\n";
	  break;
	case 3:
	  val = 255;
	  for(int j=0;j<nof;j++){
	  for (int i = 0; i < side_x * side_y; i++){
	    file.write ((char *) &val, 1);
	  }
	  }
	  cout << "Successfuly filled with whites\n";
	}
      file.close();
    }
  else
    cout << "Enter an argument - The name of the file to be edited\n";
}
