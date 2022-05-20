#include <iostream>
#include <ios>
#include <string>
#include <algorithm>
#include <vector>
#include "message.hpp"


using namespace std;

/////////////////////// function divide /////////////////////////////////////////////////////////
/// function divide string for n smaller and return array with saved message from string       //
/// id string is divisible then function check divide by n part                                //
/// then function substr return string which is part from strat to start + part                //
/// if string is not divisible then we add to string could be divisible                        //
/// if string is not divisible then we add by one mark to first part divide over get zero rest //
/////////////////////////////////////////////////////////////////////////////////////////////////
message * divide(string input_message, int n){
    
    message * tab = new message[n];
    message temporary_message;
    int i =0;
    int lenght = input_message.length();
    int part = lenght/n;
    int start  = 0; 
    int rest = lenght % n;

   if(rest == 0){
     while(start < lenght){
            temporary_message.nr=i+1;
            temporary_message.message_struct=input_message.substr(start, part); 
            tab[i]=temporary_message;
            start+=part;
            i++;
        }
   }else{ 
        do
        {
        temporary_message.nr=i+1;
        temporary_message.message_struct=input_message.substr(start, (part+1)); 
        tab[i]=temporary_message;
        start+=(part+1);
        i++;
        rest--;
        }while(rest);
        while(start < lenght){
            temporary_message.nr=i+1;
            temporary_message.message_struct=input_message.substr(start, part); 
            tab[i]=temporary_message;
            start+=part;
            i++;

        }
   }
    return tab;
}

////////// combine ///////////////////////////////////////////
// function return combine string of divide part of orginal //
// string and information of much od part                   //
//////////////////////////////////////////////////////////////
string combine(message input_tab[], int size_of_tab){
    string result;
    for (int i = 0; i < size_of_tab; i++)
    {
        result+=input_tab[i].message_struct;
    }
    return result;
}

////////// sort_table ///////////////////////////////
// function get part of string i random order      //
// and size of table ,                             //
// next function with work loop for and while      //
// and using temporary table,                      //
// get right order which have orginal message,     //
// then that process is going to have all of start //
// array in temporary table                        //
// after all proces temporary table is delete      //
/////////////////////////////////////////////////////
void sort_table(message input_tab[], int size_of_tab){
    message * temp_tab = new message[size_of_tab];
    int message_index = 1;

    for (int i = 0; i < size_of_tab; i++){
        int k=0;
        while (input_tab[k].nr != message_index)
        {
            k++;
        }
        temp_tab[i]=input_tab[k];
        message_index++;
    }
    for (int i = 0; i < size_of_tab; i++)
    {
        input_tab[i]= temp_tab[i];
    }
    delete[] temp_tab;
}

//////// shufle_table ////////////////////////////////////
// function shufle_table return message in random order //
//////////////////////////////////////////////////////////
void shuffle_table(message input_tab[], int size_of_tab ){
    vector<message> vector_message;
    for (int i = 0; i < size_of_tab ; i++)
    {
        vector_message.push_back(input_tab[i]);
    }
    random_shuffle(begin(vector_message), end(vector_message));
    for (int i = 0; i < size_of_tab; i++)
    {
       input_tab[i] = vector_message[i];
    }
    vector_message.clear();
}

int main(){

    string message_input;
    string message_out;
    int numbers_of_part;
    
    cout<<"________________________________________________________________________________________________________\n"
    <<"Program divide input message for part of that message. \n"
    <<"Next it's simulates send thats message in numbered packages. \n"
    <<"Then aplication sort message in right order and combine in one output message .\n"
    <<"The program also shows all stages of its work in the terminal.\n"
    <<"Press ENTER to start.\n";
    cin.get();

    cout<<"Write message to send \n";
    getline(cin, message_input);

    cout<<"Set how much part do you want to divide message \n";
    do
    {
        cin>>numbers_of_part;
        if (numbers_of_part>message_input.length()||numbers_of_part<1)
        {
            cout<<"Incorect numbers of part - try one more time:\n";
        }
    } while (numbers_of_part>message_input.length());
    
    message * table=divide(message_input, numbers_of_part);

    // checking the correctness of the entry on the board
    cout<<"Table beffor shuffle"<<endl;
    for (int i = 0; i < numbers_of_part; i++)
    {
        cout<<table[i].message_struct<<" nr:"<<table[i].nr<<endl;
    }
    
    shuffle_table(table, numbers_of_part);
    cout<<"Table after shuffle"<<endl;
     for (int i = 0; i < numbers_of_part; i++)
    {
        cout<<table[i].message_struct<<" nr:"<<table[i].nr<<endl;
    }
   
   sort_table(table, numbers_of_part);
   cout<<"Table after sort"<<endl;
    for (int i = 0; i < numbers_of_part; i++)
    {
        cout<<table[i].message_struct<<" nr:"<<table[i].nr<<endl;
    }

    message_out=combine(table, numbers_of_part);
    cout<<"Output message:\n"<<message_out<<endl;

    cout<<"Enter to end";
    cin.get();

    delete[] table;

    return 0;
}