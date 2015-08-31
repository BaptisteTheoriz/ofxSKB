/*--------------------------------------------------------------

By: digitalhack
Date: Feb 2014
Description: openFrameworks addon to create an on-screen keyboard.

Inspired by ofxSoftKeybaord by Jeffrey Crouse and hosted on 
github by Lensley.

--------------------------------------------------------------*/

#ifndef _OFX_SCREENKEYBOARD
#define _OFX_SCREENKEYBOARD

#include "ofMain.h"

#define OFXSKB_KEY_CAPS 10001
#define OFXSKB_KEY_MOVE 10002
#define OFXSKB_KEY_HIDE 10003
#define OFXSKB_KEY_RESIZE 10004
#define OFXSKB_KEY_DOTCOM 10005
#define OFXSKB_KEY_DOTFR 10006

#define OFXSKB_PRESS 1
#define OFXSKB_RELEASE 2

#define SHIFT_W 22
#define TAB_W 14
#define CAPS_W 17
#define DELETE_W 16
#define RETURN_W 17
#define DEFAULT_W 8
#define SPACE_W 60

#define KEY_H 8
#define KEY_P 1
#define SPACE_P 44

struct ofxSKBKeyType {
  int key[2];
  string label[2];
  bool isLastInRow;
  float x, y;
  float width, height;
  float baseWidth, baseHeight;
  float padTop, padRight, padBottom, padLeft;
  float basePadTop, basePadRight, basePadBottom, basePadLeft;
};

class ofxSKB   {
  public:
    ofxSKB();
    ~ofxSKB();
    
    enum KeyboardLayout{
        SKB_LAYOUT_KEYBOARD_EN,
        SKB_LAYOUT_KEYBOARD_FR,
        SKB_LAYOUT_KEYBOARD_FR_MAIL
    };

    void draw();
    void setFont(string _kbFontName);
    void setSize(float width);
    float getSize();
    ofVec2f getPosition();
    void setPosition(float _x, float _y);
    bool keyboardVisible();
    void hideKeyboard();
    void showKeyboard();
    void setLayout(KeyboardLayout layout);

    void mouseDragged(ofMouseEventArgs& args);
    void mouseMoved(ofMouseEventArgs& args);
    void mousePressed(ofMouseEventArgs& args);
    void mouseReleased(ofMouseEventArgs& args);
    
    void setTextColor(int hexColor);
    void setTextBGColor(int hexColor);
    void setBorderColor(int hexColor);
    void setHoverColor(int hexColor);
    void setClickColor(int hexColor);
    void setFillKeyboard(bool b);
    void setFillKeys(bool b);

  protected:
    vector<ofxSKBKeyType> keys;

  private:
    float x, y;
    float previousX, previousY;
    float kbSizer;
    float kbWidth, kbHeight;
    float kbSetWidth, kbSetWidthOld;
    float kbBaseWidth, kbBaseHeight;
    ofTrueTypeFont kbFont;
    ofTrueTypeFont kbFontSmall;
    string kbFontName;
    bool kbShow;
    bool caps;
    bool shift;
    bool shift1KeyPressed;
    bool moveKeyboard;
    bool resizeKeyboard;
    int textColor, textBGColor, borderColor, hoverColor, clickColor;
    
    bool fillKeyboard;
    bool fillKeys;
    
    bool isMousePressed;
    
    ofRectangle viewport;

    void addKey(int _key0, int _key1, bool lastInRow = false);
    int shiftState(int action = -1, int key = -1);
    bool keyTest(ofxSKBKeyType key, int tx, int ty);
    ofVec2f scaleMouseCoordinates(int mouseX, int mouseY);
};

#endif
