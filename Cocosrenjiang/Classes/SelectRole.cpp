//
//  SelectRole.cpp
//  Cocosrenjiang
//
//  Created by playcrab on 15/11/18.
//
//

#include "SelectRole.hpp"
#include "tinyxml2/tinyxml2.h"
#include "utilsParseXml.hpp"

Scene* SelectRole::createScene()
{
    auto scene = Scene::create();
    
    auto layer = SelectRole::create();
    scene->addChild(layer);
    return scene;
    
}
bool SelectRole::init()
{
    if(!Layer::init()){
        return false;
    }
    auto rootNode = CSLoader::createNode("RoleScene.csb");
   
    addChild(rootNode);
    Layout * root  = (Layout*)rootNode->getChildByName("root");
    Button* bntreturn = (Button*)Helper::seekWidgetByName(root,"teturn");
//    
//    for (i=1; i<=6; i++) {
//       
//    }
   ImageView* bntreturn1 = (ImageView*)Helper::seekWidgetByName(root,"Image_1");
   ImageView* bntreturn2 = (ImageView*)Helper::seekWidgetByName(root,"Image_2");
   ImageView* bntreturn3 = (ImageView*)Helper::seekWidgetByName(root,"Image_3");
   ImageView* bntreturn4 = (ImageView*)Helper::seekWidgetByName(root,"Image_4");
   ImageView* bntreturn5 = (ImageView*)Helper::seekWidgetByName(root,"Image_5");
   ImageView* bntreturn6 = (ImageView*)Helper::seekWidgetByName(root,"Image_6");
    
    ImageView* imgRole1 = ImageView::create("renwu/baihaogangshou_icon.png");
//    ImageView* imgRole2 = (ImageView*)Helper::seekWidgetByName(root,"Image_2");
//    ImageView* imgRole3 = (ImageView*)Helper::seekWidgetByName(root,"Image_3");
//    ImageView* imgRole4 = (ImageView*)Helper::seekWidgetByName(root,"Image_4");
//    ImageView* imgRole5 = (ImageView*)Helper::seekWidgetByName(root,"Image_5");
//    ImageView* imgRole6 = (ImageView*)Helper::seekWidgetByName(root,"Image_6");
    imgRole1->setPosition(bntreturn1->getAnchorPointInPoints());
    bntreturn1->addChild(imgRole1);
    bntreturn->addTouchEventListener(CC_CALLBACK_2(SelectRole::Callback, this));
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("ainmotion/xujixunlunyanimage.plist");
    Sprite* horse = Sprite::createWithSpriteFrameName("jiagong_xujixunlunyanimage.png");
    horse->setPosition(bntreturn2->getAnchorPointInPoints());
    bntreturn2->addChild(horse);

    Vector<SpriteFrame*> ffff(10);
    auto _abc = utilsParseXml::getInstance()->getDataMapFromJson();
    auto it = _abc.begin();
    while (it != _abc.end()) {
        log("renwustr%drenwustr%s",it->first, it->second.c_str());
        string str = it->second.c_str();
        it++;
     auto f3 = cache->getSpriteFrameByName(str);
     ffff.pushBack(f3);
    }
//     auto f3 = cache->getSpriteFrameByName("tx01_xujixunlunyanimage.png");
//     auto f4 = cache->getSpriteFrameByName("tx02_xujixunlunyanimage.png");
//     auto f5 = cache->getSpriteFrameByName("tx03_xujixunlunyanimage.png");
//     auto f6 = cache->getSpriteFrameByName("tx04_xujixunlunyanimage.png");
//     auto f7 = cache->getSpriteFrameByName("tx05_xujixunlunyanimage.png");
//     auto f8 = cache->getSpriteFrameByName("tx06_xujixunlunyanimage.png");
//     auto f9 = cache->getSpriteFrameByName("tx07_xujixunlunyanimage.png");
//     auto f0 = cache->getSpriteFrameByName("tx08_xujixunlunyanimage.png");
//  
//    ffff.pushBack(f3);
//    ffff.pushBack(f4);
//    ffff.pushBack(f5);
//    ffff.pushBack(f6);
//    ffff.pushBack(f7);
//    ffff.pushBack(f8);
//    ffff.pushBack(f9);
//    ffff.pushBack(f0);
    
    auto an = Animation::createWithSpriteFrames(ffff,0.1);
    
    horse->runAction(RepeatForever::create(Animate::create(an)));
//    Parse_xml();
    utilsParseXml::getInstance()->getDataMapFromJson();
    return true;
}
void SelectRole::Callback(Ref* psender,Widget::TouchEventType type){
    
    switch (type) {
        case Widget::TouchEventType::ENDED:
            
            auto dircter = Director::getInstance();
            Scene* sc = login::createScene();
            dircter->replaceScene(sc);
            break;
            
      
    }
   

}
void SelectRole::Parse_xml(){
    using namespace tinyxml2;
    string fileurl = FileUtils::getInstance()->fullPathForFilename("res/renwu/global_renwu_icons_6.xml");
    log("lujing%s",fileurl.c_str());

    XMLDocument* pDoc = new XMLDocument();
    
    pDoc->LoadFile(fileurl.c_str());
    XMLElement* xmlElement = pDoc->RootElement();
    XMLElement* Element = xmlElement->FirstChildElement();
    
    while (Element) {
        XMLElement* elemnt = Element->FirstChildElement();
        log("dflafdalfjaf%s",elemnt->GetText(),elemnt->Name());
    }
}
