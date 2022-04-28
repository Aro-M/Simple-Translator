#include <iostream>
#include <fstream>
#include<string>

void simpleTranslator (std::string name);
void adminTranslator ();
void userTranslator ();
void choose_version();
void addWords ();
void readWord ();
void delWord  ();
void fromLanguages ();
void fromEng ();
void armfrom ();


struct Languages
{
  int id;
    std::string enlang;
    std::string armlang;

};

void sendName ()
{
  std::cout << "You are admin or user ";
  std::string name;
  getline (std::cin, name);
  simpleTranslator (name);
}

void simpleTranslator (std::string name)
{

  if (name == "admin")
    {
      std::cout << "You are " << name << std::endl;
      adminTranslator ();
    }
  else if (name == "user")
    {
      std::cout << "You are  " << name << std::endl;
      userTranslator ();
    }
  else
    {
      std::cout << "You entered incorrectly: Please try again";
    }
}

void userTranslator ()
{
  std::cout << "\e[1m" << "Attention " << "\e[0m" <<
    "Must contain only numbers and " << "lowercase letters and must contain"
    << " a minimum of 8 characters and a maximum of 16 characters" << std::endl;
  std::cout << "You must enter the " << "\e[3m" << "User " << "\e[0m" <<
    " password " << std::endl;
  std::string passwordUser;
  std::string correctPassword = "user19982022";
  std::cin >> passwordUser;
  std::system ("clear");
  if (passwordUser.length () <= 8 || passwordUser.length () >= 16)
    {
      std::cout << "you are  inccorect ";
    }
  if (passwordUser == correctPassword)
    {
      std::cout << "you  are " << "\e[1m" << "User " << "\e[0m" << std::endl;

      fromLanguages ();
    }

}

void adminTranslator()
{

  std::cout << "\e[2m" << "Attention " << "\e[0m" <<
    "Must contain only numbers and " << "lowercase letters and must contain"
    << " a minimum of 8 characters and a maximum of 16 characters" << std::endl;
  std::cout << "You must enter the " << "\e[1m" << "Admin" << "\e[0m" <<
    " password" << std::endl;
  std::string passwordAdmin;
  std::string correctPassword = "admin19982022";
  std::cin >> passwordAdmin;
  std::system ("clear");
  if (passwordAdmin.length () <= 8 || passwordAdmin.length () >= 16)
    {
      std::cout << "you are  inccorect ";
    }
  if (passwordAdmin == correctPassword)
    {
      std::cout << "You are " << "\e[1m" << "Admin" << "\e[0m" << std::endl;

      choose_version();

    }
  else
    {
      std::cout << "You entered the password incorrectly";
    }


}

void fromLanguages ()
{
  int ch;
  std::cout << "Do you want to enter the English word to get the Armenian word "
    << "2. And enter the Armenian word to get the English word?" << std::endl;
  std::cin >> ch;
  if (ch == 1)
    {
      fromEng ();
    }
  else if (ch == 2)
    {
      armfrom ();
    }
  else
    {
      std::cout << "Doesn't function" << std::endl;
    }

}

void fromEng ()
{
  std::string wordsEngName;
  std::cout << "Enter word  want to search : " << std::endl;
  std::cin >> wordsEngName;
  Languages words;
  std::ifstream read;
  read.open ("allWords.txt");
  while (!read.eof ())
 {
      getline (read, words.enlang);
      getline (read, words.armlang);
      if (words.enlang == wordsEngName)
	 {
	  std::cout << " This is Armenian word " << words.armlang << std::endl;

	 }
  }
}

void armfrom ()
{
  std::string wordsArmName;
  std::cout << "Enter word  want to search : " << std::endl;
  std::cin >> wordsArmName;
  Languages words;
  std::ifstream read;
  read.open ("allWords.txt");
  while (!read.eof ())
    {
      getline (read, words.enlang);
      getline (read, words.armlang);
      if (words.armlang == wordsArmName)
     	{
	  std::cout << "" << words.enlang << std::endl;


     	}
    }
}


void choose_version()
{
  int i = 4;
  while (i > 0)
    {
      std::cout << "1.Add Words" << std::endl;
      std::cout << "2.read Words" << std::endl;
      std::cout << "3.del Words" << std::endl;
      int choie;
      std::cout << "Enter choie  " << std::endl;
      std::cin >> choie;
      switch (choie)
	    {
	case 1:
	  addWords ();
	  break;
	case 2:
	  readWord ();
	  break;
	case 3:
	  delWord  ();
	  break;

    	}
    }
  --i;
}


void addWords ()
{

  Languages words;
  std::cout << "Enter English Words : " << std::endl;
  std::cin.get ();
  std::getline (std::cin, words.enlang);
  std::cout << "Enter Armenian Words : " << std::endl;
  std::cin >> words.armlang;


  std::ofstream write;
  write.open ("allWords.txt", std::ios::app);

  write << words.enlang << std::endl;
  write << words.armlang << std::endl;
  write.close ();

}

void
print (Languages s)
{
 
  std::cout << "English is word : " << s.enlang << std::endl;
  std::cout << "Armenian is word : " << s.armlang << std::endl;

}

void readWord ()
{
  Languages words;
  std::ifstream read;
  read.open ("allWords.txt");
  while (!read.eof ())
    {
    
      getline (read, words.enlang);
      getline (read, words.armlang);
      print (words);
    }
  read.close ();
}


void delWord  ()
{

  std::cout << "Which pair do you want to delete?" << std::endl;
  
      std::string delEng;
      std::cout << "Enter word  want to delete: " << std::endl;
      std::cin >> delEng;
      Languages words;
      std::ifstream read;
      std::ofstream temp;
      temp.open ("temp.txt");
      read.open ("allWords.txt");
      std::ofstream write;
      write.open ("allWords.txt", std::ios::app);
      while (!read.eof ())
	{
	  getline (read, words.enlang);
	  getline (read, words.armlang);
	  if (words.enlang != delEng)
	    {

	      temp << words.enlang << std::endl;
	      temp << words.armlang << std::endl;
	      break;

	    }
	  else
	    {
	      write << words.enlang << std::endl;
	      write << words.armlang << std::endl;

	      break;
	    }
	}
      read.close ();
      temp.close ();
      remove ("allWords.txt");
      rename ("temp.txt", "allWords.txt");


}


int main ()
{
  sendName ();

}

