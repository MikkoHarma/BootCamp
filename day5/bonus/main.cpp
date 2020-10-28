/* 
Write a program which receives the name of two text files as input argument.
The program shall count the number of occurrences of the words of the first
file, in the second file, and then print the result at the end of the second file

Hint : Google C++ strings tokenization
 */

//Implementation not fully complete, reads owrds from file 1 and file2, check if file1 word exits in file2 and writes it to end of file.

#include <iostream>
#include <fstream>
#include <set>
#include <cstring>

char* readFile(std::string , std::streampos &); //filename, filesize, return pointer to buffer
void writeFile(std::string , char* , int); //filename, buffer, writesize

int main(int argc ,char* argv[]){

    char *inbuffer, *outbuffer = new char[50];
    std::string sbuffer;
    int pointer = 0, wordpointer = 0;
    std::streampos filesize;
    std::set<std::pair <std::string, int> > file1Words; //store words in file 1 (unique) + occurance
    std::multiset<std::string> file2Words;   // store all words in file 2 (duplicates)

    if(argc > 2 && argc < 4)
    {
        inbuffer = readFile(argv[1], filesize);   //read file 1 

        while(pointer < filesize){
            if(inbuffer[pointer] != 0x20 && inbuffer[pointer] != 0x0A && inbuffer[pointer] != 0x2E ) //end word by space, ".", newline
                wordpointer++;
            else {
                if(wordpointer > 0)
                {   
                    sbuffer.insert(0, inbuffer, pointer-wordpointer, wordpointer); //store word and convert char to string
                    file1Words.insert(make_pair(sbuffer,0)); //insert word
                    sbuffer.clear();
                    wordpointer = 0;
                }
            }
            pointer++;
        }
        
        delete [] inbuffer; //clean up

        inbuffer = readFile(argv[2], filesize); //read in file 2 words to multiset to allow duplicates
        pointer = 0; wordpointer = 0;
        
        while(pointer < filesize){
            if(inbuffer[pointer] != 0x20 && inbuffer[pointer] != 0x0A && inbuffer[pointer] != 0x2E)
                wordpointer++;
            else {
                if(wordpointer > 0)
                {   
                    sbuffer.insert(0, inbuffer,pointer-wordpointer, wordpointer);
                    file2Words.insert(sbuffer);
                    sbuffer.clear();
                    wordpointer = 0;
                }
            }
            pointer++;
        }
        delete [] inbuffer;

        for(auto i: file1Words) //print sorted multimap
        {
            auto it = file2Words.find(i.first);

            if(it != file2Words.end()){ //search file1 word in file2
                strcpy(outbuffer, i.first.c_str()); //convert string to char
                writeFile(argv[2], outbuffer, (i.first).size()); //write mnatching words
            }
        }     

     /* for(auto i: file1Words) //print sorted multimap (debug)
            std::cout << "Word: " << i.first << " " << i.second << std::endl;
        std::cout << " file 2" << std::endl;    
        for(auto i: file2Words) //print sorted multimap
            std::cout << "Word: " << i << std::endl;        
    */
        delete [] outbuffer;
    }
    else{
        std::cout << "no arguments" << std::endl;;
    } 
    return 0;
}

 //read file content to buffer, return buffer and size
char* readFile(std::string filename, std::streampos &filesize)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    std::streampos index = file.tellg();
    file.seekg(0,std::ios::end);
    std::streampos end = file.tellg();
    file.seekg(0,std::ios::beg);  
    filesize = end - index;  
    std::cout << "File size: " << filesize << std::endl;

    char* buffer = new char[filesize];
    file.read(buffer, filesize);

    file.close();

    return buffer;
}
//write buffer to file
void writeFile(std::string filename, char* buffer, int size) 
{
    std::fstream file;
    file.open(filename, std::fstream::out | std::fstream::app);
    file.seekg(0,std::ios::end);
    std::streampos end = file.tellg();

    file.write("\n",1);
    file.write(buffer, size);

    file.close();

    return;
}