#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void Capitalize(string& sequence_line) //function to convert any string to a capitalized version
{
  for (int i = 0; i < sequence_line.length(); ++i)
  {
    sequence_line[i] = toupper(sequence_line[i]);
  }
}

void CountLetters(string& line, int& nuc_count, int& A, int& C, int& T, int& G) //calculating number of nucleotides in each line in the file
{
  for (int i = 0; i < line.length(); ++i)
  {
    switch (line[i])
    {
      case 'A':
        A++;
        nuc_count++;
        break;
      case 'C':
        C++;
        nuc_count++;
        break;
      case 'T':
        T++;
        nuc_count++;
        break;
      case 'G':
        G++;
        nuc_count++;
        break;
      case ' ':
        cout << "Error in DNA file. An empty nucleotide is not possible." << endl << "Continuing anyways." << endl;
        break;
    }
  }
}

void CountBigrams(string& line, int& AA, int& AC, int& AT, int& AG, int& CA, int& CC, int& CT, int& CG, int& TA, int& TC, int& TT, int& TG, int& GA, int& GC, int& GT, int& GG)
{ //this function counts the number of bigrams in each line of the file
    for (int i = 1; i < line.length() - 1; i += 2)
    {
      switch (line[i]) //looks at the odd number index of the string
      {
        case 'A':
          switch (line[i - 1]) //looks at the previous index of the string
          {
            case 'A':
              AA++;
              break;
            case 'C':
              CA++;
              break;
            case 'T':
              TA++;
              break;
            case 'G':
              GA++;
              break;
            case '\n':
              break;
          }
          break;
        case 'C':
          switch (line[i - 1])
          {
            case 'A':
              AC++;
              break;
            case 'C':
              CC++;
              break;
            case 'T':
              TC++;
              break;
            case 'G':
              GC++;
              break;
            case '\n':
              break;
          }
          break;
        case 'T':
          switch (line[i - 1])
          {
            case 'A':
              AT++;
              break;
            case 'C':
              CT++;
              break;
            case 'T':
              TT++;
              break;
            case 'G':
              GT++;
              break;
            case '\n':
              break;
          }
          break;
        case 'G':
          switch (line[i - 1])
          {
            case 'A':
              AG++;
              break;
            case 'C':
              CG++;
              break;
            case 'T':
              TG++;
              break;
            case 'G':
              GG++;
              break;
            case '\n':
              break;
          }
          break;
        case '\n':
          break;
      }
    }
}

void CountLineLength(string& line, int& count) //THIS FUNCTION IS USED BECAUSE std::string.length() COUTNS THE NEWLINE CHARACTER AT THE END
{
  for (int i = 0; i < line.length(); ++i)
  {
    switch (line[i])
    {
      case 'A':
        count++;
        break;
      case 'C':
        count++;
        break;
      case 'T':
        count++;
        break;
      case 'G':
        count++;
        break;
      case ' ':
        cout << "Error in DNA file. An empty nucleotide is not possible." << endl << "Continuing anyways." << endl;
        break;
    }
  }
}

void CalclateBigramProb(double& prob_Bigram, int& dna_Bigram, int total) //function to calculate the probability of a bigram
{
  prob_Bigram = ((double) dna_Bigram / (double) total) * 100;
}

double CalculationOfC(double rand_1, double rand_2) //function to calcluate C (standard Gaussian)
{
  double temp_1 = -2 * log(rand_1);
  double temp_2 = cos(2.0 * M_PI * rand_2);
  return sqrt(temp_1) * temp_2;
}

int CalculationOfD(double stand_deviation, double C, double avg)
{
  return round((stand_deviation * C) + avg);
}

int main(int argc, char* argv[])
{
  srand(time(NULL));
  int file_number = 1;
  int choice;
  int main_count = 0;
  string file_name;
  ifstream sequenceFile; //reading data from files
  ofstream new_sequence_file; //printing out data onto .out file
  do
  {
    if (main_count == 0) //if the program is running for its first time
    {
      if (argc > 2) //checks if there are more than just a file name.
      {
        cout << "Too many arguments." << endl << "Enter only a file name." << endl;
        return -1;
      }
      if (argc == 1) //checks if the program ran with no arguments other than itself.
      {
        cout << "Please enter a file name." << endl;
        return -1;
      }
      file_name = argv[1];
      sequenceFile.open(file_name);
      if (!sequenceFile.is_open()) //checks if the file is open or not
      {
        cout << "Please enter a valid file name." << endl;
        return -1;
      }
      if (sequenceFile.peek() == ifstream::traits_type::eof())
      {
        cout << "Cannot enter an empty file. Please use file with data." << endl;
        return -1;
      }
    }

    string line;
    int lineCount = 0;
    int dna_length_count = 0;
    int dna_A = 0, dna_C = 0, dna_T = 0, dna_G = 0; //sets all numbers of nucleotides to 0.
    int dna_AA = 0, dna_AC = 0, dna_AT = 0, dna_AG = 0; //sets all numbers of bigrams starting with A to 0.
    int dna_CA = 0, dna_CC = 0, dna_CT = 0, dna_CG = 0; //sets all numbers of bigrams starting with C to 0.
    int dna_TA = 0, dna_TC = 0, dna_TT = 0, dna_TG = 0; //sets all numbers of bigrams starting with T to 0.
    int dna_GA = 0, dna_GC = 0, dna_GT = 0, dna_GG = 0; //sets all numbers of bigrams starting with G to 0.

    while (getline(sequenceFile, line))
    {
      Capitalize(line);
      lineCount++; //geting the total number of lines in the file
      CountLetters(line, dna_length_count, dna_A, dna_C, dna_T, dna_G); //getting the total number of each nucleotides
      CountBigrams(line, dna_AA, dna_AC, dna_AT, dna_AG, dna_CA, dna_CC, dna_CT, dna_CG, dna_TA, dna_TC, dna_TT, dna_TG, dna_GA, dna_GC, dna_GT, dna_GG);
    }
    sequenceFile.close();
    int total_count_of_bigrams = dna_AA + dna_AC + dna_AT + dna_AG + dna_CA + dna_CC + dna_CT + dna_CG + dna_TA + dna_TC + dna_TT + dna_TG + dna_GA + dna_GC + dna_GT + dna_GG;
    double probability_A = ((double) dna_A / (double) dna_length_count) * 100;
    double probability_C = ((double) dna_C / (double) dna_length_count) * 100;
    double probability_T = ((double) dna_T / (double) dna_length_count) * 100;
    double probability_G = ((double) dna_G / (double) dna_length_count) * 100;
    double probability_AA, probability_AC, probability_AT, probability_AG, probability_CA, probability_CC, probability_CT, probability_CG;
    double probability_TA, probability_TC, probability_TT, probability_TG, probability_GA, probability_GC, probability_GT, probability_GG;
    CalclateBigramProb(probability_AA, dna_AA, total_count_of_bigrams);
    CalclateBigramProb(probability_AC, dna_AC, total_count_of_bigrams);
    CalclateBigramProb(probability_AT, dna_AT, total_count_of_bigrams);
    CalclateBigramProb(probability_AG, dna_AG, total_count_of_bigrams);
    CalclateBigramProb(probability_CA, dna_CA, total_count_of_bigrams);
    CalclateBigramProb(probability_CC, dna_CC, total_count_of_bigrams);
    CalclateBigramProb(probability_CT, dna_CT, total_count_of_bigrams);
    CalclateBigramProb(probability_CG, dna_CG, total_count_of_bigrams);
    CalclateBigramProb(probability_TA, dna_TA, total_count_of_bigrams); //CALCULATING BIGRAM PROBABILITY
    CalclateBigramProb(probability_TC, dna_TC, total_count_of_bigrams);
    CalclateBigramProb(probability_TT, dna_TT, total_count_of_bigrams);
    CalclateBigramProb(probability_TG, dna_TG, total_count_of_bigrams);
    CalclateBigramProb(probability_GA, dna_GA, total_count_of_bigrams);
    CalclateBigramProb(probability_GC, dna_GC, total_count_of_bigrams);
    CalclateBigramProb(probability_GT, dna_GT, total_count_of_bigrams);
    CalclateBigramProb(probability_GG, dna_GG, total_count_of_bigrams);  //probability IS ALL DONE
    double average_of_length = (double) dna_length_count / (double) lineCount; //gets the average of the length
    //getting the variance
    double square_variance_total = 0.0;
    sequenceFile.open(file_name);
    string second_line;
    int line_length_temp = 0;
    double temp = 0.0;
    while (getline(sequenceFile, second_line))
    {
      Capitalize(second_line);
      line_length_temp = 0;
      CountLineLength(second_line, line_length_temp);
      temp = (double) line_length_temp - average_of_length;
      square_variance_total += pow(temp, 2.0);
    }
    sequenceFile.close();
    double variance = square_variance_total / ((double) (lineCount - 1)); //VARIANCE DONE
    double standard_dev = sqrt(variance); //STANDARD DEVIATION DONE


    if (main_count == 0) //if the program is running for its first time
    {
      new_sequence_file.open("John.out");
      new_sequence_file << "File Number: " << file_number << endl << endl;
      new_sequence_file << "John Park" << endl << "002298927" << endl;
      new_sequence_file << endl;
      new_sequence_file << "Sum of the Lengths of the DNA strings: " << dna_length_count << endl;
      new_sequence_file << "Mean of the Lengths of the DNA strings: " << average_of_length << endl;
      new_sequence_file << "Variance of the Lengths of the DNA strings: " << variance << endl;
      new_sequence_file << "Standard Deviation of the Lengths of the DNA strings: " << standard_dev << endl;
      new_sequence_file << endl;
      new_sequence_file << "Relative Probability of Nucleotide A: " << probability_A << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide C: " << probability_C << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide T: " << probability_T << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide G: " << probability_G << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AA: " << probability_AA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AC: " << probability_AC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AT: " << probability_AT << " %" << endl;   //PRINTING OUT ALL PROBABILITIES
      new_sequence_file << "Relative Probability of Bigram AG: " << probability_AG << " %" << endl;   //ONTO A .out FILE
      new_sequence_file << "Relative Probability of Bigram CA: " << probability_CA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CC: " << probability_CC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CT: " << probability_CT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CG: " << probability_CG << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TA: " << probability_TA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TC: " << probability_TC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TT: " << probability_TT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TG: " << probability_TG << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GA: " << probability_GA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GC: " << probability_GC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GT: " << probability_GT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GG: " << probability_GG << " %" << endl;
      new_sequence_file << endl << endl << endl;
      new_sequence_file.close();
    }
    else
    {
      new_sequence_file.open("John.out", ios_base::app); //IOS_BASE IS PART OF STD. THIS IS TO APPEND THE TEXT.
      new_sequence_file << "File Number: " << file_number << endl << endl;
      new_sequence_file << "John Park" << endl << "002298927" << endl;
      new_sequence_file << endl;
      new_sequence_file << "Sum of the Lengths of the DNA strings: " << dna_length_count << endl;
      new_sequence_file << "Mean of the Lengths of the DNA strings: " << average_of_length << endl;
      new_sequence_file << "Variance of the Lengths of the DNA strings: " << variance << endl;
      new_sequence_file << "Standard Deviation of the Lengths of the DNA strings: " << standard_dev << endl;
      new_sequence_file << endl;
      new_sequence_file << "Relative Probability of Nucleotide A: " << probability_A << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide C: " << probability_C << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide T: " << probability_T << " %" << endl;
      new_sequence_file << "Relative Probability of Nucleotide G: " << probability_G << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AA: " << probability_AA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AC: " << probability_AC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram AT: " << probability_AT << " %" << endl;   //PRINTING OUT ALL PROBABILITIES
      new_sequence_file << "Relative Probability of Bigram AG: " << probability_AG << " %" << endl;   //ONTO A .out FILE
      new_sequence_file << "Relative Probability of Bigram CA: " << probability_CA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CC: " << probability_CC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CT: " << probability_CT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram CG: " << probability_CG << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TA: " << probability_TA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TC: " << probability_TC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TT: " << probability_TT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram TG: " << probability_TG << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GA: " << probability_GA << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GC: " << probability_GC << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GT: " << probability_GT << " %" << endl;
      new_sequence_file << "Relative Probability of Bigram GG: " << probability_GG << " %" << endl;
      new_sequence_file << endl << endl << endl << endl;
      new_sequence_file.close();
    }


    double random_double_1;
    double random_double_2;
    new_sequence_file.open("John.out", ios_base::app);
    for (int i = 0; i < 1000; i++)
    {
      do //ths do-while loop makes sure the random doubles are located in the [0,1) interval.
      {
        random_double_1 = ((double) rand() / (double) RAND_MAX);
        random_double_2 = ((double) rand() / (double) RAND_MAX);
      }
      while (random_double_1 == 1 && random_double_2 == 1);
      //int new_length_C = sqrt(-2.0 * log(random_double_1) * )
      int new_length = CalculationOfD(standard_dev, CalculationOfC(random_double_1, random_double_2), average_of_length);

      for (int j = 0; j < new_length; j++)
      {
        round(probability_A);
        round(probability_C);
        round(probability_T);
        round(probability_G);

        int new_random = (rand() % 100) + 1;
        //need to find a way to produce given 4 probabilities
        if ((new_random >= 1) && (new_random <= probability_A))
        {
          new_sequence_file << 'A';
        }
        if ((new_random > probability_A) && (new_random <= (probability_A + probability_C)))
        {
          new_sequence_file << 'C';
        }
        if ((new_random > (probability_A + probability_C)) && (new_random <= (probability_A + probability_C + probability_T)))
        {
          new_sequence_file << 'T';
        }
        if ((new_random > (probability_A + probability_C + probability_T)) && (new_random <= 100))
        {
          new_sequence_file << 'G';
        }
      }
      new_sequence_file << endl;
    }
    new_sequence_file.close();

    bool choice_while = true;
    while (choice_while) //while loop is to see if the user puts in real / correct options
    {
      cout << endl;
      cout << "Would you like to process a new file?" << endl << "Enter 1 for yes" << endl << "Enter 2 for no" << endl;
      cin >> choice;
      if (!(choice == 1 || choice == 2))
      {
        cout << "Please enter a valid option." << endl;
        cout << endl;
      }
      else
      {
        choice_while = false;
      }
    }
    if (choice == 2)
    {
      return -1; //program ends if user inputs 2
    }
    bool file_while = true;
    while (file_while) //this while loop is to see if the user puts in an actual file name
    {
      cout << endl;
      cout << "What is the file's name?" << endl;
      cin >> file_name;
      sequenceFile.open(file_name);
      if (!sequenceFile.is_open()) //checks if the file is open or not
      {
        cout << "Please enter a valid file name." << endl;
        cout << endl;
      }
      else if (sequenceFile.peek() == ifstream::traits_type::eof()) //checks if file is empty
      {
        cout << "Cannot enter an empty file. Please use file with data." << endl << endl;
      }
      else
      {
        file_while = false;
      }
    }
    main_count++;
    file_number++;
  }
  while (choice == 1); //program ends if user inputs 2 (no)
  return 0;
}
