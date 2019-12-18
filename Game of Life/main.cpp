#include "ClassicBoard.h"
#include "DoughnutBoard.h"
#include "MirrorBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;




// CREATE A FUNCTION TO PRINT ALL ARRAYS FOR ALL TYPES ********* MEDIUM PRIORITY



int main(int argc, char* argv[])
{
  ifstream sequenceFile; //reads data from files
  ofstream new_sequence_file; //writes data to files
  string file_input;
  int file_row;
  int file_column;
  bool option_bool = true;
  int assignment_choice;
  while(option_bool) //getting option from user to see if they want to provide a file or random assignment
  {
    cout << endl;
    cout << "Please select an option by entering the corresponding number." << endl;
    cout << "1) Random Assignment." << endl << "2) Enter a map file." << endl;
    cin >> assignment_choice;
    if (cin.fail() || (!(assignment_choice == 1) && !(assignment_choice == 2)))
    {
      cout << "Please enter a valid option." << endl << endl;
    }
    else
    {
      option_bool = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }

  int column_length;
  int row_length;         //array stuff
  double density;

  if (assignment_choice == 1) //if user picks random assignment
  {
    bool array_bool = true;
    bool row_bool = true;
    bool density_bool = true;
    bool column_bool = true;
    while (array_bool) //while loop to see if user puts in valid inputs for row, column, and density
    {
      if (row_bool) //checking row
      {
        cout << endl;
        cout << "Enter the row length." << endl;
        cin >> row_length;
        if (cin.fail())
        {
          cout << "Please enter a valid row length." << endl << endl;
          cin.clear();
          cin.ignore(1000, '\n');
          continue;
        }
        row_bool = false;
        cin.clear();
        cin.ignore(1000, '\n');
      }
      if (column_bool) //checking column
      {
        cout << endl;
        cout << "Enter the column length." << endl;
        cin >> column_length;
        if (cin.fail())
        {
          cout << "Please enter a valid column length." << endl << endl;
          cin.clear();
          cin.ignore(1000, '\n');
          continue;
        }
        column_bool = false;
        cin.clear();
        cin.ignore(1000, '\n');
      }
      if (density_bool) //checking density
      {
        cout << endl;
        cout << "Enter the initial population density in the interval: (0,1]." << endl;
        cin >> density;
        if (cin.fail() || !(density > 0) || (density > 1))
        {
          cout << "Please enter a valid density." << endl << endl;
          cin.clear();
          cin.ignore(1000, '\n');
          continue;
        }
        density_bool = false;
        cin.clear();
        cin.ignore(1000, '\n');
      }
      array_bool = false;
    }
  }

  if (assignment_choice == 2)
  {
    string line;
    string file_name;
    //code reading file and check if file exists, empty,
    bool file_bool = true;
    while (file_bool)
    {
      cout << endl;
      cout << "Please enter a file name." << endl;
      cin >> file_name;
      sequenceFile.open(file_name);
      sequenceFile.clear();
      sequenceFile.seekg(0, ios::beg); //reset the reading position to the beginning
      if (!sequenceFile.is_open()) //checks if the file is open
      {
        cout << "Please enter a valid file name." << endl << endl;
        continue;
      }
      else if (sequenceFile.peek() == ifstream::traits_type::eof()) // check if file is empty
      {
        cout << "Cannot enter an empty file. Please use file with data." << endl << endl;
        continue;
      }
      sequenceFile >> file_row;
      sequenceFile >> file_column;
      int number_entries = 0;
      if ((file_row > 0) && (file_column > 0)) //checks if first two lines are the valid row and columns
      {
        sequenceFile.clear();
        sequenceFile.seekg(0, ios::beg); //reset the reading position to the beginning
        getline(sequenceFile, line);
        getline(sequenceFile, line);    //skips the first two lines so the program can start reading the "array" inputs
        while (getline(sequenceFile, line))
        {
          for (int i = 0; i < line.length(); ++i) //checks the number of valid entires
          {
            if ((line[i] == 'X') || (line[i] == '-'))
            {
              number_entries++; //basically checks the number of entries in the file
            }
          }
        }
        if (!((file_column * file_row) == number_entries)) //checks if the number of rows/columns are correct
        {
          cout << "Please check the file." << endl << "It may contain an incorrect number of rows or columns." << endl << endl;
          cin.clear();
          cin.ignore(1000, '\n');
          continue;
        }
        else
        {
          file_bool = false; //FINALLY APPROVES OF THE FILE.
        }
      }
      else
      {
        cout << "Please enter a file with valid rows and columns." << endl << endl;
      }
    }
  }

  bool board_bool = true;
  int board_choice;
  while (board_bool) //checks to see what kind of board users choose
  {
    cout << endl;
    cout << "Please select an option by entering the corresponding number." << endl;
    cout << "1) Classical Board." << endl << "2) Doughnut Board." << endl << "3) Mirror Board." << endl;
    cin >> board_choice;
    if (cin.fail() || (!(board_choice == 1) && !(board_choice == 2) && !(board_choice == 3)))
    {
      cout << "Please enter a valid choice." << endl << endl;
    }
    else
    {
      board_bool = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }

  bool print_bool = true;
  int print_choice;
  while (print_bool)
  {
    cout << endl;
    cout << "Please select an option by entering the corresponding number." << endl;
    cout << "1) Print to console with brief pauses between generations." << endl;
    cout << "2) Print to console by hitting the Enter key." << endl;
    cout << "3) Print to a file." << endl;
    cin >> print_choice;
    if (cin.fail() || (!(print_choice == 1) && !(print_choice == 2) && !(print_choice == 3)))
    {
      cout << "Please enter a valid choice." << endl << endl;
    }
    else
    {
      print_bool = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }

  if (print_choice == 3)
  {
    bool name_bool = true;
    while (name_bool)
    {
      cout << endl;
      cout << "Please enter a file name." << endl;
      cin >> file_input;
      new_sequence_file.open(file_input);
      if (!new_sequence_file.is_open()) // checks if the file is open
      {
        cout << "Please enter a valid file name." << endl;
      }
      else
      {
        name_bool = false;
      }
    }
  }

  if (board_choice == 1) //if board choice is classical
  {
    ClassicBoard board;
    if (assignment_choice == 1) //if user chooses a random board
    {
      board.SetRandom(row_length, column_length, density);
    }
    if (assignment_choice == 2)    //if user chooses to input a file
    {
      board.FileBoardCreate(file_row, file_column); //creates a classic board
      sequenceFile.clear();
      string line;
      sequenceFile.seekg(0, ios::beg);
      getline(sequenceFile, line);
      getline(sequenceFile, line);  //skips the first two lines
      int row_location = 0;
      int column_location = 0;
      while (getline(sequenceFile, line)) //starts reading the array in the file
      {
        column_location = 0;
        for (int i = 0; i < file_column; ++i) //declaring the arrays from the files.
        {
          if (line[i] == 'X')
          {
            board.FileBoardInit(row_location, column_location, line[i]);  //filling in data into array if data is X
          }
          else
          {
            board.FileBoardInit(row_location, column_location, line[i]); //filling in data into array if data is -
          }
            column_location++;
        }
        column_location = 0;
        row_location++;
      }
    }
    bool game_bool = true;
    int generation = 0;
    while (game_bool) //while loop to keep the game going until the generations become stable or empty
    {
      int dec1 = 0;
      int dec2 = 0;
      int dec3 = 0;
      int dec4 = 0;

      bool generation_bool = true;
      int row_count = 0;
      int column_count = 0;
      int general_count = 0;
      board.setColumnLocation(0);
      board.setRowLocation(0);     //brings the location back up to top right cornersboard
      while (generation_bool) //while loop to iterate through the 2-D array
      {


        int cell = board.CellDetermine();
        dec1 = board.Lonely_Cell();
        dec2 = board.Stable_Cell();
        dec3 = board.Perfect_Cell();
        dec4 = board.Crowding_Cell();
        column_count++;
        board.setColumnLocation(column_count);
        if (board.getColumnLocation() == board.getColumn())
        {
          general_count++;
          if (general_count == board.getRow())
          {
            break;
          }
          column_count = 0;
          row_count++;
          board.setColumnLocation(column_count);
          board.setRowLocation(row_count);
        }
      }

      if (board.getBool())//(dec1 == -1) && (dec2 == -1) && (dec3 == -1) && (dec4 == -1)) //checks to see if any of the actions were performed. If not, then game is over.
      {
        game_bool = false;
        if (generation == 0)        //IF THE FIRST GENERATION IS STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game Of Life has been stabilized." << endl;
          }
        }
        else    //IF OTHER GENERATIONS ARE STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has been stabilized." << endl;
          }
        }
        break;
      }
      int X_count = board.getXValue();     //calculating how many X's there are
      if (X_count == 0) //if array is empty
      {
        game_bool = false;
        if (generation == 0) //if the first generation is empty
        {
          if (print_choice == 1 || print_choice == 2)  //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3)    //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        else //if it is not the first generation
        {
          if (print_choice == 1 || print_choice == 2) //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3) //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        break;
      }
      //printing
      if (print_choice == 1) //printing to console with a brief 3 second pause.
      {
        cout << endl << endl << "Generation: " << generation;
        // board.getArray2();
        board.getArray();
        board.ArrayCopy();
        sleep(1);
        //print to console with brief pause.
      }
      if (print_choice == 2)
      {
        cout << endl << endl << "Generation: " << generation;
        board.getArray();
        board.ArrayCopy();
        cin.get();
        //print to console with pressing enter key.
      }
      if (print_choice == 3)
      {
        board.PrintToFile(new_sequence_file, generation);
        board.ArrayCopy();
        //ask for file and print to that.
      }
      generation++;
    }
    cout << "Game is finished. Please press Enter." << endl;
    sequenceFile.close();
    new_sequence_file.close();
    cin.get();
  } //done with classic board choices here.

  if (board_choice == 2) //if board choice is doughnut
  {
    DoughnutBoard board;
    if (assignment_choice == 1) //if user chooses a random board
    {
      board.SetRandom(row_length, column_length, density);
    }
    if (assignment_choice == 2)    //if user chooses to input a file
    {
      board.FileBoardCreate(file_row, file_column); //creates a classic board
      sequenceFile.clear();
      string line;
      sequenceFile.seekg(0, ios::beg);
      getline(sequenceFile, line);
      getline(sequenceFile, line);  //skips the first two lines
      int row_location = 0;
      int column_location = 0;
      while (getline(sequenceFile, line)) //starts reading the array in the file
      {
        column_location = 0;
        for (int i = 0; i < file_column; ++i) //declaring the arrays from the files.
        {
          if (line[i] == 'X')
          {
            board.FileBoardInit(row_location, column_location, line[i]);  //filling in data into array if data is X
          }
          else
          {
            board.FileBoardInit(row_location, column_location, line[i]); //filling in data into array if data is -
          }
            column_location++;
        }
        column_location = 0;
        row_location++;
      }
    }
    bool game_bool = true;
    int generation = 0;
    while (game_bool) //while loop to keep the game going until the generations become stable or empty
    {
      int dec1 = 0;
      int dec2 = 0;
      int dec3 = 0;
      int dec4 = 0;

      bool generation_bool = true;
      int row_count = 0;
      int column_count = 0;
      int general_count = 0;
      board.setColumnLocation(0);
      board.setRowLocation(0);     //brings the location back up to top right cornersboard
      while (generation_bool) //while loop to iterate through the 2-D array
      {


        int cell = board.CellDetermine();
        dec1 = board.Lonely_Cell();
        dec2 = board.Stable_Cell();
        dec3 = board.Perfect_Cell();
        dec4 = board.Crowding_Cell();
        column_count++;
        board.setColumnLocation(column_count);
        if (board.getColumnLocation() == board.getColumn())
        {
          general_count++;
          if (general_count == board.getRow())
          {
            break;
          }
          column_count = 0;
          row_count++;
          board.setColumnLocation(column_count);
          board.setRowLocation(row_count);
        }
      }

      if (board.getBool())//(dec1 == -1) && (dec2 == -1) && (dec3 == -1) && (dec4 == -1)) //checks to see if any of the actions were performed. If not, then game is over.
      {
        game_bool = false;
        if (generation == 0)        //IF THE FIRST GENERATION IS STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game Of Life has been stabilized." << endl;
          }
        }
        else    //IF OTHER GENERATIONS ARE STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has been stabilized." << endl;
          }
        }
        break;
      }
      int X_count = board.getXValue();     //calculating how many X's there are
      if (X_count == 0) //if array is empty
      {
        game_bool = false;
        if (generation == 0) //if the first generation is empty
        {
          if (print_choice == 1 || print_choice == 2)  //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3)    //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        else //if it is not the first generation
        {
          if (print_choice == 1 || print_choice == 2) //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3) //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        break;
      }
      //printing
      if (print_choice == 1) //printing to console with a brief 3 second pause.
      {
        cout << endl << endl << "Generation: " << generation;
        // board.getArray2();
        board.getArray();
        board.ArrayCopy();
        sleep(1);
        //print to console with brief pause.
      }
      if (print_choice == 2)
      {
        cout << endl << endl << "Generation: " << generation;
        board.getArray();
        board.ArrayCopy();
        cin.get();
        //print to console with pressing enter key.
      }
      if (print_choice == 3)
      {
        board.PrintToFile(new_sequence_file, generation);
        board.ArrayCopy();
        //ask for file and print to that.
      }
      generation++;
    }
    cout << "Game is finished. Please press Enter." << endl;
    sequenceFile.close();
    new_sequence_file.close();
    cin.get();
  }


  if (board_choice == 3) //if board choice is mirror
  {
    MirrorBoard board;
    if (assignment_choice == 1) //if user chooses a random board
    {
      board.SetRandom(row_length, column_length, density);
    }
    if (assignment_choice == 2)    //if user chooses to input a file
    {
      board.FileBoardCreate(file_row, file_column); //creates a classic board
      sequenceFile.clear();
      string line;
      sequenceFile.seekg(0, ios::beg);
      getline(sequenceFile, line);
      getline(sequenceFile, line);  //skips the first two lines
      int row_location = 0;
      int column_location = 0;
      while (getline(sequenceFile, line)) //starts reading the array in the file
      {
        column_location = 0;
        for (int i = 0; i < file_column; ++i) //declaring the arrays from the files.
        {
          if (line[i] == 'X')
          {
            board.FileBoardInit(row_location, column_location, line[i]);  //filling in data into array if data is X
          }
          else
          {
            board.FileBoardInit(row_location, column_location, line[i]); //filling in data into array if data is -
          }
            column_location++;
        }
        column_location = 0;
        row_location++;
      }
    }
    bool game_bool = true;
    int generation = 0;
    while (game_bool) //while loop to keep the game going until the generations become stable or empty
    {
      int dec1 = 0;
      int dec2 = 0;
      int dec3 = 0;
      int dec4 = 0;

      bool generation_bool = true;
      int row_count = 0;
      int column_count = 0;
      int general_count = 0;
      board.setColumnLocation(0);
      board.setRowLocation(0);     //brings the location back up to top right cornersboard
      while (generation_bool) //while loop to iterate through the 2-D array
      {


        int cell = board.CellDetermine();
        dec1 = board.Lonely_Cell();
        dec2 = board.Stable_Cell();
        dec3 = board.Perfect_Cell();
        dec4 = board.Crowding_Cell();
        column_count++;
        board.setColumnLocation(column_count);
        if (board.getColumnLocation() == board.getColumn())
        {
          general_count++;
          if (general_count == board.getRow())
          {
            break;
          }
          column_count = 0;
          row_count++;
          board.setColumnLocation(column_count);
          board.setRowLocation(row_count);
        }
      }

      if (board.getBool())//(dec1 == -1) && (dec2 == -1) && (dec3 == -1) && (dec4 == -1)) //checks to see if any of the actions were performed. If not, then game is over.
      {
        game_bool = false;
        if (generation == 0)        //IF THE FIRST GENERATION IS STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game Of Life has been stabilized." << endl;
          }
        }
        else    //IF OTHER GENERATIONS ARE STABILIZED
        {
          if (print_choice == 1 || print_choice == 2)
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has been stabilized." << endl;
          }
          if (print_choice == 3)
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has been stabilized." << endl;
          }
        }
        break;
      }
      int X_count = board.getXValue();     //calculating how many X's there are
      if (X_count == 0) //if array is empty
      {
        game_bool = false;
        if (generation == 0) //if the first generation is empty
        {
          if (print_choice == 1 || print_choice == 2)  //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3)    //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        else //if it is not the first generation
        {
          if (print_choice == 1 || print_choice == 2) //print on console if choices are either pause or enter
          {
            cout << endl << endl << "Generation: " << generation;
            board.getArray();
            cout << "Game of Life has emptied." << endl;
          }
          if (print_choice == 3) //print on file if choice is printing on file
          {
            board.PrintToFile(new_sequence_file, generation);
            new_sequence_file << "Game of Life has emptied." << endl;
          }
        }
        break;
      }
      //printing
      if (print_choice == 1) //printing to console with a brief 3 second pause.
      {
        cout << endl << endl << "Generation: " << generation;
        // board.getArray2();
        board.getArray();
        board.ArrayCopy();
        sleep(1);
        //print to console with brief pause.
      }
      if (print_choice == 2)
      {
        cout << endl << endl << "Generation: " << generation;
        board.getArray();
        board.ArrayCopy();
        cin.get();
        //print to console with pressing enter key.
      }
      if (print_choice == 3)
      {
        board.PrintToFile(new_sequence_file, generation);
        board.ArrayCopy();
        //ask for file and print to that.
      }
      generation++;
    }
    cout << "Game is finished. Please press Enter." << endl;
    sequenceFile.close();
    new_sequence_file.close();
    cin.get();
  }
  return 0;
}
