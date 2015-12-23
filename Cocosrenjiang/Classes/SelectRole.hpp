//
//  SelectRole.hpp
//  Cocosrenjiang
//
//  Created by playcrab on 15/11/18.
//
//

#ifndef SelectRole_hpp
#define SelectRole_hpp
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "login.hpp"
#include <iostream>
USING_NS_CC;
#include <stdio.h>

using namespace cocos2d::ui;
using namespace std;
using namespace tinyxml2;
class SelectRole:public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(SelectRole);
    
private:
    void Callback(cocos2d::Ref* psender,Widget::TouchEventType type);
    void Parse_xml();
    Layout* root;
    Button* bntreturn;
    
};


#endif /* SelectRole_hpp */
