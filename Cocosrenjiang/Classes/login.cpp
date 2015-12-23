#include "login.hpp"

Scene* login::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = login::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool login::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    auto rootNode = CSLoader::createNode("MainScene.csb");
    auto rootNode = CSLoader::createNode("loginScene.csb");
//    auto rootNode = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("loginScene.json");
   
    addChild(rootNode);
    Layout* root = (Layout*)rootNode->getChildByName("root");
   txtAccount = (TextField*)Helper::seekWidgetByName(root,"txtAccount");
// txtAccount = (TextField*)root->getChildByName("shurukuang")->getChildByName("txtAccount");

    Button* but_stat = (Button*)Helper::seekWidgetByName(root, "Btn_stat");
    
    txtAccount->setString("");
    txtAccount->setPlaceHolder("input");
    
    but_stat->addTouchEventListener(CC_CALLBACK_2(login::stattouch, this));
    
    return true;
}
void login::stattouch(Ref *psender, Widget::TouchEventType type)

{
    switch (type) {
        case Widget::TouchEventType::BEGAN:
            CCLOG("began");
            break;
        case Widget::TouchEventType::MOVED:
            CCLOG("moved");
            break;
        case Widget::TouchEventType::ENDED:
            auto director = Director::getInstance();
            auto scene = SelectRole::createScene();
            auto trastion = TransitionCrossFade::create(1.0,scene);
            director->replaceScene(trastion);
            txtAccount->setString("123456");
            CCLOG("ended");
   
            break;
    }
}