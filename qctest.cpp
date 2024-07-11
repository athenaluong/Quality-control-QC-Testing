//
//  main.cpp
//  Project 3
//
//  Created by Emily Ni on 2/2/24.
//

#include <iostream>
#include "string"
#include "cctype"
#include <cassert>
using namespace std;

bool isValidQC(string results){
    
    if(results == ""){ //confirms not empty string
        return false;
    }
    
    int n = 0;
    while(n < results.length()){ //while loop that repeats below process for every batch until end of string
        
        if(results[n] != 'Q'){ //checks that first letter is Q
            return false;
        }
        if(!isdigit(results[n+1]) || results[n+1] == '0'){ //checks the second char is a nonzero digit
            return false;
        }
        string test = "", pass = "", defect = ""; //declare both string and int variables to count total, pass, and defects
        int ntest = 0, npass = 0, ndefect = 0;

        //count total number test cases
        for(int i=n+1; i< results.length() && isdigit(results[i]) ; i++){
            test += results[i];
            n = i;
        }
        ntest = stoi(test); //convert to int
        
        if(results[n+1] == 'p'){ //for if p comes before d
            for(int j=n+2; j< results.length() && isdigit(results[j]); j++){ //count number passes
                pass += results[j];
                n = j;
            }
            
            if( pass == ""){
                return false;
            }
            else{
                npass = stoi(pass);
            }
            
        
            if(results[n+1] == 'd'){ //d after p
                for(int k=n+2; k< results.length() && isdigit(results[k]); k++){ //count number defects
                    defect += results[k];
                    n = k;
                }
            }
            else{ //if no d after p
                return false;
            }
            if( defect == ""){
                return false;
            }
            else{
                ndefect = stoi(defect);
            }
        }
        else if(results[n+1] == 'd'){ //for if d comes before p
            for(int j=n+2; j< results.length() && isdigit(results[j]); j++){ //count number defects
                defect += results[j];
                n = j;
            }
            
            if( defect == ""){
                return false;
            }
            else{
                ndefect = stoi(defect);
            }
            
            if(results[n+1] == 'p'){ //p after d
                for(int k=n+2; k< results.length() && isdigit(results[k]); k++){ // count number passes
                    pass += results[k];
                    n = k;
                }
            }
            else{ //if no p after d
                return false;
            }
            if( pass == ""){
                return false;
            }
            else{
                npass = stoi(pass);
            }
        }
        else{ //if no p or d after Q
            return false;
        }
        
        //test that no leading 0s in test, pass, or defect
        if(test!="0" && test[0] == '0'){
            return false;
        }
        if(pass!="0" && pass[0] == '0'){
            return false;
        }
        if(defect!="0" && defect[0] == '0'){
            return false;
        }
        
        //test number passes and defects add to total
        if(ntest != npass + ndefect){
            return false;
        }
        n++; //moves onto next index, which should be start of next batch or end of string

    }
    return true;
}


int passQC(string results){
    if(isValidQC(results) == false){ //return -1 if parameter not valid
        return -1;
    }
    else{
        int n=0;
        string pass = "";
        int npass = 0;
        while(n<results.length()){
            if(results[n] == 'p'){
                for(int i=n+1; i< results.length() && isdigit(results[i]); i++){
                    pass += results[i];
                    n = i;
                }
                npass += stoi(pass);
            }
            n++;
            pass = ""; //clear string from previous batch
        }
    
        return npass;
    }
}
       

int defectQC(string results){
    if(isValidQC(results) == false){ //return -1 if parameter not valid
        return -1;
    }
    else{
        int n=0;
        string defect = "";
        int ndefect = 0;
        while(n<results.length()){
            if(results[n] == 'd'){
                for(int i=n+1; i< results.length() && isdigit(results[i]); i++){
                    defect += results[i];
                    n = i;
                }
                ndefect += stoi(defect);
            }
            n++;
            defect = ""; //clear string from previous batch
        }
    

        return ndefect;
    }
}

int totalQC(string results){
    if(isValidQC(results) == false){ //return -1 if parameter not valid
        return -1;
    }
    else{
        int n=0;
        string total = "";
        int ntotal = 0;
        while(n<results.length()){
            if(results[n] == 'Q'){
                for(int i=n+1; i< results.length() && isdigit(results[i]); i++){
                    total += results[i];
                    n = i;
                }
                ntotal += stoi(total);
            }
            n++;
            total = ""; //clear string from previous batch
        }
    

        return ntotal;
    }
}

int batches(string results){
    if(isValidQC(results) == false){ //return -1 if parameter not valid
        return -1;
    }
    else{
        int n = 0;
        for(int i=0;i<results.length();i++){
            if(results[i] == 'Q'){
                n +=1;
            }
        }
        return n;
    }
}

int main() {

    assert( isValidQC("") == false );
    assert( isValidQC(" ") == false );
    assert( passQC( " " ) == -1 );
    assert( defectQC( " " ) == -1 );
    assert( totalQC( " " ) == -1 );
    assert( batches( " " ) == -1 );
    assert( isValidQC( "Q2p1d1" ) == true );
    assert( passQC( "Q2p1d1" ) == 1 );
    assert( defectQC( "Q2p1d1" ) == 1 );
    assert( totalQC( "Q2p1d1" ) == 2 );
    assert( batches( "Q2+1-1" ) == -1 );

    cout << "All test cases succeeded" << endl;
    
    return 0;
    
    
    
}
