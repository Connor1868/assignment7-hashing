//Serial Number : 75
//
// Author : Connor Widder
// Due Date : 12 - 02 - 19
// Programming Assignment Number 7
//
// Fall 2019 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
//This program impliments a hashing function using an array. The program can display the elemtns hashed into the array, insert an element
//into the array, search for an element in the array, and delete an element from the array.

#include <iostream>
#include <list>

void initialStatment();
void displayArray();
char randomCharGen();

class hash{
private:
    int hash_pos;   //Interger varible for the postion of the hash index.
    char array[20]; //Char array varible to contain the hash.
public:
    int count_Insert = 0;   //Interger varible for to count the linear probing calls.
    int count_Search = 0;   //Interger varible for to count the linear probing calls.
    int count_Delete = 0;   //Interger varible for to count the linear probing calls.
    hash() {
        for(int i = 0; i < 20; i++)     //Populate the hash array with intial '*' representing blank positons
            array[i] = '*';
        
        for(int i = 0; i < 15; i++){    //Insert 15 elements into the hash array with Random chars (A to Z) using the hashing funtion.
            char data;                  //Char varible for the char to be placed in the hash.
            data = randomCharGen();
            hash_pos = Hash(data);
            
            while(array[hash_pos] != '*'){  //Check if collision has occured, if so impliment linear probing
                hash_pos = reHash(hash_pos);
            }
            
            array[hash_pos] = data;
        }
    }
    int Hash(int key){      //Hashing function
        return key % 10;
    }
    int reHash(int key){    //Rehashing function, used once a colison occurs
        return key + 1;
    }
    void insert(){
        char data;                  //Char varible for the char to be placed in the hash.
        
        std::cout << "\nEnter a char you want to insert (between A – Z ): ";
        std::cin >> data;
        std::cout << "\n";
        if (data <= 'A' && data >= 'Z'){        //Check the value inputed
            std::cout << data << "is not a valid char./n";
            return;
        }
        
        hash_pos = Hash(data);      //Find data hash position
        
        while(array[hash_pos] != '*'){      //Check if collision has occured, if so impliment linear probing
            hash_pos = reHash(hash_pos);
            count_Insert++;
            if(count_Insert>=20){
                std::cout<<"\nArray is Full.\n";
                break;
            }
        }
        
        if(array[hash_pos] == '*'){     //Empty hash postion, place data in hash array
            array[hash_pos] = data;
            std::cout<<"The char " << data << " was inserted in location number "<< hash_pos << std::endl;
        }
    }
    void search(){
        char data;                  //Char varible for the char to be placed in the hash.
        
        std::cout<<"\nEnter a char you want to search (between A – Z): ";
        std::cin>>data;
        
        if (!(data >= 65 && data <= 90)){     //Check for proper input
            std::cout << "\n" << data << " is not a valid char.\n\n";
            return;
        }
        
        //Hashing search
        hash_pos = Hash(data);  //Find data hash position
        
        while(array[hash_pos] != data){     //Check if collision has occured, if so impliment linear probing
            hash_pos = reHash(hash_pos);
            count_Search++;
            if(count_Search>=20){
                std::cout<<"\nThe char " << data << " was not found in the array"<< std::endl;
                return;
            }
        }
        
        std::cout << "\nThe char " << data << " was found in location "<< hash_pos << std::endl;
    }
    void Delete(){
        char data;                  //Char varible for the char to be placed in the hash.
        
        std::cout << "\nEnter a char you want to delete (between A - Z): ";
        std::cin >> data;
        if (!(data >= 65 && data <= 90)){   //Check for proper input
            std::cout << "\n" << data << " is not a valid char.\n\n";
            return;
        }
        
        //Hashing deletion
        hash_pos = Hash(data);  //Find data hash position
        
        while(array[hash_pos] != data){         //Check if collision has occured, if so impliment linear probing
            hash_pos = reHash(hash_pos);
            count_Delete++;
            if(count_Delete>=20){
                std::cout << "\n" << data <<"not found in the array";
                return;
            }
        }
        array[hash_pos] = '*';
        std::cout<< "\n" << data <<"is deleted from the array\n";
        
        
            
    }
    void Display(){
        std::cout << "\nDisplaying the generated array." << std::endl;
        for(int i = 0; i < 20; i++){
            std::cout<<array[i]<<"   ";
            if(i == 9)
                std::cout<< std::endl;
        }
        std::cout<< std::endl;
    }
};

int main(int argc, const char * argv[]) {
    
    srand(time(0)); //random number generator
   
    hash h;
    
    initialStatment();
    
    h.Display();
    
    char choice;
    while(1){
        std::cout<<"\nChoose from the following menu options\n";
        std::cout<< "\nA. Display the generated array.\nB. Search for a Character ( between A – Z ) in the array.\n";
        std::cout << "C. Insert new Character ( between A - Z ) in the array.\nD. Delete a character ( between A – Z ) from the array.\n";
        std::cout << "X. End the program\n";
        
        std::cout<<"\nChoose your option: ";
        std::cin>>choice;
        switch(choice){
            case 'A':
                h.Display();
                break;
            case 'B':
                h.search();
                break;
            case 'C':
                h.insert();
                break;
            case 'D':
                h.Delete();
                break;
            case 'X':
                std::cout << "\nThe number of linear probes when each number is hashed and collision";
                std::cout << "\noccurred when adding a character in the array is " << h.count_Insert;
                
                std::cout << "\n\nThe number of linear probes when each number is hashed and collision";
                std::cout << "\noccurred when searching for a character in the array is " << h.count_Search;
                
                std::cout << "\n\nThe number of linear probes when each number is hashed and collision";
                std::cout << "\noccurred when deleting a character in the array is " << h.count_Delete;
                
                std::cout << "\n\nThis hashing program was implemented by\nConnor Widder – 12 – 2 - 2019\n";
                
                exit(0);
            default:
                std::cout<<"\n*** Invalid Option ***\n";
                break;
        }
    }
    
    return 0;
}

void initialStatment(){
    std::cout << "Welcome to my Hashing Program" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "A. Creates an char array of size 20. Assigning - to each" << std::endl;
    std::cout << "   location in the array indicating that the array is empty." << std::endl;
    std::cout << "B. Populates 15 elements of the array with random characters" << std::endl;
    std::cout << "   between A and Z inclusive." << std::endl;
    std::cout << "C. If a collision occurs, linear probing will find the next" << std::endl;
    std::cout << "   available position / location." << std::endl;
    std::cout << "D. The generated array will be displayed in 2 lines." << std::endl;
    std::cout << "   Each line contains 10 characters separated by 2 spaces." << std::endl;
}

void displayArray(){
    std::cout << "The Generated Array." << std::endl;
    
}

char randomCharGen(){
    return rand() % ((90 - 65 + 1)) + 65;
}
