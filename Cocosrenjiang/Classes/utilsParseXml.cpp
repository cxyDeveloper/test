//
//  utilsParseXml.cpp
//  Cocosrenjiang
//
//  Created by playcrab on 15/12/3.
//
//

#include "utilsParseXml.hpp"
#include "cocos-ext.h"
#include "tinyxml2/tinyxml2.h"

#include <stdlib.h>
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

using namespace tinyxml2;
utilsParseXml::utilsParseXml()
{
    
}
utilsParseXml::~utilsParseXml()
{
    
}

utilsParseXml* utilsParseXml::_i = nullptr;

utilsParseXml* utilsParseXml::getInstance(){
    
    if (_i == nullptr) {
        _i = new utilsParseXml;
    }
    return _i;
}

DataMap utilsParseXml::getDataMapFrom(){
    DataMap map;
    string renwu = FileUtils::getInstance()->fullPathForFilename("res/renwu.xml");
    XMLDocument* doc = new XMLDocument;
    XMLError errorId = doc->LoadFile(renwu.c_str());
    
    if (errorId != 0) {
        log("xml格式错误%s",renwu.c_str());
    }
    
    doc->LoadFile(renwu.c_str());
    XMLElement* rootElement = doc->RootElement();
    XMLElement* Child_e = rootElement->FirstChildElement();
    int i = 0;
    while (Child_e) {
        
        std::string k = Child_e->Name();
        std::string v = Child_e->GetText();
        
        if (k.compare("sound_dir") == 0) {
            i++;
            map.insert(std::make_pair(i, v));
        }else{
            
        }
        
        Child_e = Child_e->NextSiblingElement();
    }
    return map;
}

DataMap utilsParseXml::getDataMapFromJson(){
    DataMap map;
    int j = 0;
    string element;
    string renwu = FileUtils::getInstance()->fullPathForFilename("res/renwu.json");
    using namespace rapidjson;
    
    Document doc;
    
    string js_st = FileUtils::getInstance()->getStringFromFile(renwu);
    
    doc.Parse<0>(js_st.c_str());
    
    const rapidjson::Value& v = doc["renwu"];
    
    if (v.IsArray()) {
        for (unsigned int i = 0; i<v.Size(); i++) {
            
            const rapidjson::Value& vv = v[i];
            //            log("adfadfafadf%s", vv[i]);
            
            if (vv.IsArray()){
                for (unsigned int q = 0; q<vv.Size(); q++) {
                    element  = vv[q].GetString();
                    map.insert(make_pair(j, element));
                    j++;
                }
                
                
            }else{
                element = vv["sound_dir"].GetString();
                map.insert(make_pair(j, element));
            }
            
            
            
            j++;
        }
    }
    
    return map;
}