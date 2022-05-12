#include <iostream>
#include <fstream>
#include<string>

void simpleTranslator ();
void adminTranslator (std::string);
void userTranslator (std::string);
void chooseVersion();
void addWords ();
void readWord ();
void delWord  ();
void fromLanguages ();
void fromEng ();
void armFrom ();
void editWords ();


struct Languages
{
    
    std::string enLang;
    std::string armLang;

};


void simpleTranslator ()
{   std::cout << "You are admin or user ";
    std::string name;
    std::system ("clear");
    do{
     std::cin>> name;
   for(int i = 0; i < name.length();++i){
  
        if(name[i] >= 65 && name[i] <= 90) {
            name[i] += 32; 
           }
       
   if (name == "admin")
        {
             
                adminTranslator (name);
        }
      if(name[i] >= 65 && name[i] <= 90)
        {
            name[i] += 32;
            
        } 
        if (name == "user")
            {
            
               userTranslator ( name);
            }
    }   
    std::system ("clear");
   std::cout << "You entered incorrectly: Please try again"<<std::endl;
   
  } while(name != "admin" && name != "user"); 
}

void userTranslator (std::string name)
{ std::cout << "You are  " << name << std::endl;
  std::cout << "\e[1m" << "Attention " << "\e[0m" <<
    "Must contain only numbers and " << "lowercase letters and must contain"
    << " a minimum of 8 characters and a maximum of 16 characters" << std::endl;
  std::cout << "You must enter the " << "\e[3m" << "User " << "\e[0m" <<
    " password " << std::endl;
  std::string passwordUser;
  std::string correctPassword = "user19982022";
  
  do{
  
  std::cout << "Please enter password " << std::endl;
  
  std::cin>>passwordUser;
   std::system ("clear");
          if (passwordUser.length () <= 8 || passwordUser.length () >= 16)
         {
             if(passwordUser != correctPassword)
             {
              std::cout << "You are  inccorect " <<std::endl;
             }
         }
         for(int i = 0; i < passwordUser.length() ; ++i) 
         {
          if(passwordUser[i] >= 65 && passwordUser[i] <= 90)
          {
             passwordUser[i] += 32;
          }
       
         }
  
  }while(correctPassword != passwordUser);
  
  if (passwordUser == correctPassword)
    {
        
      std::cout << "You  are " << "\e[3m" << "User " << "\e[0m" << std::endl;

      fromLanguages ();
    }

}

void adminTranslator(std::string name)
{
  std::cout << "You are  " << name << std::endl;
  std::cout << "\e[2m" << "Attention " << "\e[0m" <<
    "Must contain only numbers and " << "lowercase letters and must contain"
    << " a minimum of 8 characters and a maximum of 16 characters" << std::endl;
  std::cout << "You must enter the " << "\e[1m" << "Admin" << "\e[0m" <<
    " password" << std::endl;
  std::string passwordAdmin;
  std::string correctPassword = "admin19982022";
  do{
  
  std::cout << "Please enter password " << std::endl;
  std::cin>>passwordAdmin;
  std::system ("clear");
   if (passwordAdmin.length () <= 8 || passwordAdmin.length () >= 16)
         {
             if(passwordAdmin != correctPassword)
             {
               std::cout << "You are  inccorect " <<std::endl;
             }
         }
         for(int i = 0; i < passwordAdmin.length() ; ++i){
             
          if(passwordAdmin[i] >= 65 && passwordAdmin[i] <= 90)
          {
                passwordAdmin[i] += 32;
          }
       
       }
  
    }while(correctPassword != passwordAdmin);
  if (passwordAdmin == correctPassword)
    {
      std::cout << "You are " << "\e[1m" << "Admin" << "\e[0m" << std::endl;

      chooseVersion();

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
      armFrom ();
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
      getline (read, words.enLang);
      getline (read, words.armLang);
      if (words.enLang == wordsEngName)
	 {
	  std::cout << " This is Armenian word " << words.armLang << std::endl;

	 }
  }
}

void armFrom ()
{
  std::string wordsArmName;
  std::cout << "Enter word  want to search : " << std::endl;
  std::cin >> wordsArmName;
  Languages words;
  std::ifstream read;
  read.open ("allWords.txt");
  while (!read.eof ())
    {
      getline (read, words.enLang);
      getline (read, words.armLang);
      if (words.armLang == wordsArmName)
     	{
	  std::cout << "" << words.enLang << std::endl;


     	}
    }
}


void chooseVersion()
{
  int i = 4;
  while (i > 0)
    {
      int choie;
      std::cout << "1.Add Words" << std::endl;
      std::cout << "2.read Words" << std::endl;
      std::cout << "3.del Words" << std::endl;
      std::cout << "4.edit Words" << std::endl;
      std::cout << "Enter choose  " << std::endl;
     
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
    case 4:
      editWords ();
      break;
    	}
    }
  --i;
}


void addWords ()
{

  Languages words;
  do{
  
      std::cout << "Enter English Words : " << std::endl;
  
      // get(std::cin,words.enLang);
     std::cin >> words.enLang;
      //std::cin.get();
      //std::getline (std::cin, words.enLang);
      std::cout << "Enter Armenian Words : " << std::endl;
     // get(std::cin,words.armLang);
     // std::getline(std::cin , words.armLang);
    std::cin >> words.armLang;
     // std::cin.get();
  std::ofstream write;
  write.open ("allWords.txt", std::ios::app);

  
  write << words.enLang << std::endl;
  write << words.armLang << std::endl;
  write.close ();
  if(words.enLang.length() ==  0 || words.armLang.length() == 0){
      std::cout << "It is not allowed to leave an empty field or one character"<<std::endl;
  }
 }while(words.enLang.length() ==  0 || words.armLang.length() == 0);

}

void print (Languages s)
{
  
  std::cout << "English is word : " << s.enLang << std::endl;
  std::cout << "Armenian is word : " << s.armLang << std::endl;

}

void readWord ()
{
  Languages words;
  std::ifstream read;
  read.open ("allWords.txt");
  while (getline (read, words.enLang) &&
      getline (read, words.armLang))
    {
      
     print (words);
    } 
  //read.close ();
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
	  getline (read, words.enLang);
	  getline (read, words.armLang);
	  if (words.enLang != delEng)
	    {

	      temp << words.enLang << std::endl;
	      temp << words.armLang << std::endl;
	      break;

	    }
	  else
	    {
	      write << words.enLang << std::endl;
	      write << words.armLang << std::endl;
	      break;
	    }
	}
      read.close ();
      temp.close ();
      remove ("allWords.txt");
      rename ("temp.txt", "allWords.txt");


}

void editWords(){
    
    std::cout << "You want to update record (y/n) : ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        std::string pair;
        std::cout << "Enter your English word which you are want to edit"<<std::endl;
        std::cin  >> pair;
        Languages newWords;
        getline(std::cin, newWords.enLang);
        getline(std::cin,newWords.armLang);
        Languages words;
        std::ofstream tempFile;
        tempFile.open("temp.txt");
        std::ifstream read;
        read.open("allWords.txt");
        while (!read.eof()) {
            getline(read, words.enLang);
            getline(read, words.armLang);
            if (words.enLang != pair) {
                tempFile << words.enLang<<std::endl;
                tempFile << words.armLang<<std::endl;
               
            }
            else {
                
                tempFile << newWords.armLang;
                tempFile << newWords.enLang;
              
            }
        }
        read.close();
        tempFile.close();
        remove("allWords.txt");
        rename("temp.txt", "allWords.txt");
        std::cout << "Successfuly"<<std::endl;
    }
    else {
        std::cout << "UnSuccessfuly"<<std::endl;
    }

}
int main ()
{
  simpleTranslator ();

}
