#ifndef TCSVREADER_H
#define TCSVREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> //atof
#include "TObject.h"
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TString.h"


using std::cout;
using std::endl;
using std::flush;
using std::ifstream;
using std::ios;
using std::string;
using std::atof;
using std::vector;

class TCSVReader:public TObject{
private:
    TString fExtension;
    TString fFilename;
    Int_t fNumberOfLines;
    vector<Double_t> fValueVector;
    Int_t fNumOfData;//one per point
    //Int_t fNumOfValues; //4*numOfData
    Int_t fNumOfValues() const{return 4*this->fNumOfData;};

    void ReadFile();

public:
    TCSVReader(const TString&);
    ~TCSVReader();

    Double_t *GetX();
    Double_t *GetY();
    Double_t *GetSigmaX();
    Double_t *GetSigmaY();
    inline Int_t GetSize(){return fNumOfData;};

    TGraph *GetTGraphErrors();
    TGraph *GetTGraph();

    ClassDef(TCSVReader,0);
};

#endif
