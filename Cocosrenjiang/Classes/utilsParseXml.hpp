//
//  utilsParseXml.hpp
//  Cocosrenjiang
//
//  Created by playcrab on 15/12/3.
//
//

#ifndef utilsParseXml_hpp
#define utilsParseXml_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <map>

using namespace std;
typedef map<int, std::string> DataMap;

USING_NS_CC;

class utilsParseXml{
    
public:
    utilsParseXml();
    virtual ~utilsParseXml();
    static utilsParseXml* getInstance();
    //xml
    DataMap getDataMapFrom();
    //json
    DataMap getDataMapFromJson();
private:
    static utilsParseXml* _i;
};


#endif /* utilsParseXml_hpp */
