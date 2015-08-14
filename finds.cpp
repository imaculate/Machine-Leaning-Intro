#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main () {
  ifstream myfile;
  string line;
  int instances, attributes;
    myfile.open ("data.txt");
    
   
   if (myfile.is_open()) {
      getline(myfile, line);
      stringstream ss(line);
      ss>> instances>>attributes;
     
      
      string hypothesis[attributes];
      for(int k =0; k< attributes ; k++){
         hypothesis[k] = "None";
         
      }
     string ispositive;
     string c[attributes];
     for(int i = 0; i<instances; i++){
         getline(myfile, line);
         
          stringstream ssin(line);
          
          
          for(int m = 0; m< attributes; m++){
               ssin>>c[m];
               
               
          }
         
          ssin>>ispositive;
          
         if(ispositive.compare("Yes") == 0){
            for(int j =0; j< attributes; j++){
              
               if(c[j].compare(hypothesis[j]) != 0){
                  if(hypothesis[j].compare("None")==0){
                     hypothesis[j] = c[j];
                   
                  }else if(hypothesis[j].compare("Any")!=0){
                     hypothesis[j] = "Any";
                  }
               }
            }
         }
      }
       
      myfile.close();
      
      for(int n =0;n< attributes; n++){
         cout<< hypothesis[n]<<", ";
      }  
      return 0;
      

   
   }else{
      return -1;
   }
   
   
  }